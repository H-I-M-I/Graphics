#include <stdio.h>
#include <graphics.h>
#include <time.h> 
#include <unistd.h> 

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    cleardevice();

    srand(time(NULL));

    for (int i = 0; i < 1000; i++) {
        int xmin = 0, xmax = getmaxx(), ymin = 0, ymax = getmaxy();
        int x1 = rand() % (xmax - xmin + 1) + xmin;
        int y1 = rand() % (ymax - ymin + 1) + ymin;
        int x2 = rand() % (xmax - xmin + 1) + xmin;
        int y2 = rand() % (ymax - ymin + 1) + ymin;

        float m = (float)(y2 - y1) / (x2 - x1);
        float c = y1 - m * x1;

        for (int x = x1; x <= x2; x++) {
            int y = (int)(m * x + c);
            putpixel(x, y, WHITE);
            usleep(10000000000); 
        }
    }

    getch();
    closegraph();

    return 0;
}
