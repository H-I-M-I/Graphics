#include <stdio.h>
#include <graphics.h>
#include <unistd.h>

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;
    float m, c;

    initgraph(&gd, &gm, (char*)"");

    cleardevice();

    printf("Enter starting point coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter ending point coordinates (x2, y2): ");
    scanf("%d %d", &x2, &y2);

    m = (float)(y2 - y1) / (x2 - x1);
    c = y1 - m * x1;

    for (int x = x1; x <= x2; x++) {
        int y = (int)(m * x + c);
        putpixel(x, y, WHITE);
        usleep(10000); 
    }

    getch();
    closegraph();

    return 0;
}
