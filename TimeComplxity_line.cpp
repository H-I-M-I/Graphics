#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawLineDirect(int x1, int y1, int x2, int y2);
void drawLineDDA(int x1, int y1, int x2, int y2);
void drawLineBresenham(int x1, int y1, int x2, int y2);

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    srand(time(NULL));

    clock_t start, end;
    double time_taken;

    int x1, y1, x2, y2;

    start = clock();
    for (int i = 0; i < 500; i++)
    {
        x1 = rand() % getmaxx();
        y1 = rand() % getmaxy();
        x2 = rand() % getmaxx();
        y2 = rand() % getmaxy();
        drawLineDirect(x1, y1, x2, y2);
    }
    end = clock();
    
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for direct line equation method: %f seconds\n", time_taken);

    for (int i = 0; i < 500; i++)
    {
        x1 = rand() % getmaxx();
        y1 = rand() % getmaxy();
        x2 = rand() % getmaxx();
        y2 = rand() % getmaxy();
        drawLineDDA(x1, y1, x2, y2);
    }
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for DDA algorithm: %f seconds\n", time_taken);

    start = clock();
    for (int i = 0; i < 500; i++)
    {
        x1 = rand() % getmaxx();
        y1 = rand() % getmaxy();
        x2 = rand() % getmaxx();
        y2 = rand() % getmaxy();
        drawLineBresenham(x1, y1, x2, y2);
    }
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for Bresenham's line algorithm: %f seconds\n", time_taken);

    getch();
    closegraph();
    return 0;
}

void drawLineDirect(int x1, int y1, int x2, int y2)
{
    float m = (float)(y2 - y1) / (x2 - x1);
    float c = y1 - m * x1;
    for (int x = x1; x <= x2; x++)
    {
        int y = (int)(m * x + c);
        putpixel(x, y, WHITE);
    }
}

void drawLineDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;
    float x = x1;
    float y = y1;
    for (int i = 0; i <= steps; i++)
    {
        putpixel((int)x, (int)y, GREEN);
        x += xIncrement;
        y += yIncrement;
    }
}

void drawLineBresenham(int x1, int y1, int x2, int y2)
{
    int dx, dy, p, x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    x = x1;
    y = y1;

    p = 2 * dy - dx;

    while (x < x2)
    {
        if (p >= 0)
        {
            putpixel(x, y, RED);
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        }
        else
        {
            putpixel(x, y, RED);
            p = p + 2 * dy;
        }
        x = x + 1;
    }
}
