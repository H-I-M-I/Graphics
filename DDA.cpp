#include <stdio.h>
#include <graphics.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2, steps;
    float dx, dy, x, y;

    initgraph(&gd, &gm, (char*)"");

    cleardevice();

    printf("Enter starting point coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point coordinates (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    dx = x2 - x1;
    dy = y2 - y1;

    steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    dx = dx / (float)steps;
    dy = dy / (float)steps;

    x = x1;
    y = y1;

    int i = 1;
    while (i <= steps) {
        putpixel(x, y, WHITE);

        x += dx;
        y += dy;

        i++;
    }

    getch();
    closegraph();

    return 0;
}
