//  Write a Program in OpenGL on Linux Platform to draw a Dash Line using Bresenham
//  Line Drawing Algorithm. Divide the screen in four quadrants with centre as (0,0). Use
//  Mouse / Without Mouse to Plot the Points.

//  box pattern

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void simpleLine(int x1, int y1, int x2, int y2)
{

    int x, y, dx, dy, step, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;
    if(abs(dx) > abs(dy))
        step = abs(dx);
    else
        step = abs(dy);

    Xin = dx/step;
    Yin = dy/step;
    x = x1;
    y = y1;
    displayPoint(x, y);
    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        displayPoint(x, y);
    }

    glFlush();
}

void bresenhams(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy;
    int e, incx, incy, inc1, inc2;
    dx = x2 - x1;
    dy = y2 - y1;

    if(dx < 0)
        dx = -dx;
    if(dy < 0)
        dy = -dy;

    incx = 1;
    if(x2 < x1)
        incx = -1;
    incy = 1;
    if(y2 < y1)
        incy = -1;

    x = x1;
    y = y1;
    if(dx >= dy)
    {
        displayPoint(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for(int i = 0; i < dx; i++)
        {
            if(e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;

            if(i % 10 != 0 && (i+1) % 10 != 0)
                displayPoint(x, y);
        }
    }
    else
    {
        displayPoint(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for(int i = 0; i < dy; i++)
        {
            if(e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            if(i % 10 != 0 && (i+1) % 10 != 0)
                displayPoint(x, y);
        }
    }

    glFlush();
}

void primitives(void)
{

    glColor3f(0, 1, 0);
    simpleLine(0, 400, 800, 400);
    simpleLine(400, 0, 400, 800);

    int px, py, qx, qy;
    cout << "Enter the co-ordinates of Q (top-right) (x, y) :"<<endl;
    cin >> qx >> qy;
    cout << "Enter the co-ordinates of P (bottom-left) (x, y) :"<<endl;
    cin >> px >> py;
    glColor3f(0, 0, 0);
    bresenhams(px, py, px, qy);
    bresenhams(px, qy, qx, qy);
    bresenhams(qx, qy, qx, py);
    bresenhams(qx, py, px, py);

    int x2 = (px + qx)/2;
    int y2 = (py + qy)/2;

    //  inner square
    bresenhams(x2, qy, px, y2);
    bresenhams(px, y2, x2, py);
    bresenhams(x2, py, qx, y2);
    bresenhams(qx, y2, x2, qy);

    int x3 = (qx - px)/4;
    int y3 = (py - qy)/4;

    //  smallest square
    bresenhams(px + x3, qy + y3, qx - x3, qy + y3);
    bresenhams(qx - x3, qy + y3, qx - x3, py - y3);
    bresenhams(qx - x3, py - y3, px + x3, py - y3);
    bresenhams(px + x3, py - y3, px + x3, qy + y3);
}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 800, 800, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Monitor hills using bresenhams");

    initialize();
    glutDisplayFunc(primitives);
    glutMainLoop();
    return 0;
}
