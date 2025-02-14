#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#include<math.h>

void ellipse_midpoint(int, int, int, int);
void drawellipse(int, int, int, int);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    srand(time(NULL)); // Seed random number generator

    for (int i = 0; i < 10; i++) {
        int xc = rand() % 300 + 190; 
        int yc = rand() % 300 + 90; 
        int rx = rand() % 190; 
        int ry = rand() % 190; 

        ellipse_midpoint(xc, yc, rx, ry);
    }

    getch();
    closegraph();
    return 0;
}

void ellipse_midpoint(int xc, int yc, int rx, int ry) {
    // REGION 1
    int x = 0, y = ry, x2, y2;
    float p1 = (ry * ry) - (rx * rx * ry) + (rx * rx) / 4;
    int a = 2 * ry * ry * x;
    int b = 2 * rx * rx * y;
    while (a <= b) {
        drawellipse(xc, yc, x, y);
        x++;
        if (p1 < 0) {
            a = 2 * ry * ry * x;
            p1 = p1 + a + (ry * ry);
        } else {
            y--;
            a = 2 * ry * ry * x;
            b = 2 * rx * rx * y;
            p1 = p1 + a - b + (ry * ry);
        }
        drawellipse(xc, yc, x, y);
        delay(10);
    }
    // REGION 2
    float p2 = ((ry * ry) * (x + 0.5) * (x + 0.5)) + ((rx * rx) * (y - 1) * (y - 1)) - ((rx * rx) * (ry * ry));
    a = 0;
    b = 0;
    while (y >= 0) {
        drawellipse(xc, yc, x, y);
        y--;
        if (p2 < 0) {
            x++;
            a = 2 * ry * ry * x;
            b = 2 * rx * rx * y;
            p2 = p2 + a - b + (rx * rx);
        } else {
            b = 2 * rx * rx * y;
            p2 = p2 - b + (rx * rx);
        }
        drawellipse(xc, yc, x, y);
    }
}

void drawellipse(int xc, int yc, int x, int y) {
    putpixel(xc + x, yc + y, 15);
    putpixel(xc - x, yc + y, WHITE);
    putpixel(xc + x, yc - y, WHITE);
    putpixel(xc - x, yc - y, 15);
}
