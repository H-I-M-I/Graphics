#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void CSLCAD(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax);

void CSLCAD(double x0, double y0, double x1, double y1, double xmin, double xmax, double ymin, double ymax)
{
    int accept = 0, done = 0;

    // Check if both endpoints are already inside the window
    if (x0 >= xmin && x0 <= xmax && y0 >= ymin && y0 <= ymax &&
        x1 >= xmin && x1 <= xmax && y1 >= ymin && y1 <= ymax) {
        accept = 1;
    }

    // If both endpoints are not inside the window, clip the line
    while (!done)
    {
        // Clip against left boundary
        if (x0 < xmin && x1 < xmin) {
            done = 1;
        } else if (x0 < xmin) {
            y0 += (y1 - y0) * (xmin - x0) / (x1 - x0);
            x0 = xmin;
        } else if (x1 < xmin) {
            y1 += (y0 - y1) * (xmin - x1) / (x0 - x1);
            x1 = xmin;
        }

        // Clip against right boundary
        else if (x0 > xmax && x1 > xmax) {
            done = 1;
        } else if (x0 > xmax) {
            y0 += (y1 - y0) * (xmax - x0) / (x1 - x0);
            x0 = xmax;
        } else if (x1 > xmax) {
            y1 += (y0 - y1) * (xmax - x1) / (x0 - x1);
            x1 = xmax;
        }

        // Clip against top boundary
        else if (y0 < ymin && y1 < ymin) {
            done = 1;
        } else if (y0 < ymin) {
            x0 += (x1 - x0) * (ymin - y0) / (y1 - y0);
            y0 = ymin;
        } else if (y1 < ymin) {
            x1 += (x0 - x1) * (ymin - y1) / (y0 - y1);
            y1 = ymin;
        }

        // Clip against bottom boundary
        else if (y0 > ymax && y1 > ymax) {
            done = 1;
        } else if (y0 > ymax) {
            x0 += (x1 - x0) * (ymax - y0) / (y1 - y0);
            y0 = ymax;
        } else if (y1 > ymax) {
            x1 += (x0 - x1) * (ymax - y1) / (y0 - y1);
            y1 = ymax;
        } else {
            accept = 1;
            done = 1;
        }
    }

    // If line is accepted, draw it
    if (accept)
    {
        line(x0, y0, x1, y1);
    }
}


int main()
{
    double xmin, xmax, ymin, ymax, x0, y0, x1, y1;

    initwindow(500, 600);

    printf("Enter the coordinates of the line:\n");
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);
    line(x0, y0, x1, y1);

    printf("Enter the rectangular coordinates of clipping window:\n");
    scanf("%lf%lf%lf%lf", &xmin, &ymin, &xmax, &ymax);

    rectangle(xmin, ymin, xmax, ymax);

    outtextxy(150, 20, (char*)"BEFORE CLIPPING");
    

    getch(); 

    cleardevice();
    outtextxy(150, 20, (char*)"AFTER CLIPPING");
    CSLCAD(x0, y0, x1, y1, xmin, xmax, ymin, ymax);
    rectangle(xmin, ymin, xmax, ymax);
    
    getch();
    closegraph();
    return 0;
}
