#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

/* void EightWaySymmetricPlot(int xc, int yc, int x, int y)
{
    putpixel( x + xc,  y + yc, RED);
    putpixel( x + xc, -y + yc, BLUE);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc,  y + yc, YELLOW);
    putpixel( y + xc,  x + yc, 12);
    putpixel( y + xc, -x + yc, 14);
    putpixel(-y + xc, -x + yc, 18);
    putpixel(-y + xc,  x + yc, 9);
}
*/

void EightWaySymmetricPlot(int xc, int yc, int x, int y)
{
    putpixel( x + xc,  y + yc, GREEN);
    putpixel( x + xc, -y + yc, GREEN);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc,  y + yc, GREEN);
    putpixel( y + xc,  x + yc, GREEN);
    putpixel( y + xc, -x + yc, GREEN);
    putpixel(-y + xc, -x + yc, GREEN);
    putpixel(-y + xc,  x + yc, GREEN);
}

void BresenhamCircle(int xc, int yc, int r)
{
    int x = 0, y = r, d = 3 - (2 * r);
    EightWaySymmetricPlot(xc, yc, x, y);

    while (x <= y)
    {
        if (d < 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
        EightWaySymmetricPlot(xc, yc, x, y);
    }
}

void MidPointCircle(int x0, int y0, int r)
{
    int x = 0, y = r, p = 1 - r;

    while (x <= y)
    {
        putpixel(x0 + x, y0 + y, 7);
        putpixel(x0 + y, y0 + x, 7);
        putpixel(x0 - y, y0 + x, 7);
        putpixel(x0 - x, y0 + y, 7);
        putpixel(x0 - x, y0 - y, 7);
        putpixel(x0 - y, y0 - x, 7);
        putpixel(x0 + y, y0 - x, 7);
        putpixel(x0 + x, y0 - y, 7);

        x = x + 1;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * (x - y) + 1;
        }
    }
}

int main(void)
{
    int xc = 250, yc = 250, r[100], gdriver = DETECT, gmode, errorcode;
    clock_t start, end;
    double bresenham_time = 0, midpoint_time = 0;

    initgraph(&gdriver, &gmode, (char *)"C:\\TURBOC3\\BGI");
    errorcode = graphresult();

    if (errorcode != grOk)
    {
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1);
    }

    /* printf("Enter the values of xc and yc :");
    scanf("%d%d", &xc, &yc);
    */
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        r[i] = rand() % 150 + 50;
    }

    start = clock();
    for (int i = 0; i < 100; i++)
    {
        MidPointCircle(xc, yc, r[i]);
    }
    end = clock();
    midpoint_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    for (int i = 0; i < 100; i++)
    {
        BresenhamCircle(xc, yc, r[i]);
    }
    end = clock();
    bresenham_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken by Bresenham's algorithm: %f seconds\n", bresenham_time);
    printf("Time taken by Midpoint algorithm: %f seconds\n", midpoint_time);

    getch();
    closegraph();
    return 0;
}
