#include <windows.h>
#include <gl/gl.h>

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
    float dx, dy, x, y, step, Xin, Yin;
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
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();

}

void dottedLine(int x1, int y1, int x2, int y2)
{
    float dx, dy, x, y, step, Xin, Yin;
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
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        if(i % 5 == 0)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
    glFlush();
}

void dashedLine(int x1, int y1, int x2, int y2)
{
    float dx, dy, x, y, step, Xin, Yin;
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
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        if(i % 10 != 0)
        {
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }
    glFlush();
}

void bresenhams(int x1, int y1, int x2, int y2)
{
    int x, y, dx, dy, e, step, incx, incy, inc1, inc2;

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
    if(dx > dy)
    {
        displayPoint(x, y);
        e = 2 * dy - dx;
        inc1 = 2 *(dy - dx);
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

            displayPoint(x, y);
        }
    }
    glFlush();
}

/*
void bresenhams(int x1, int y1, int x2, int y2)
{
    int dx, dy, i, e;
    int incx, incy, inc1, inc2;
    int x, y;

    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    incx = 1;
    if (x2 < x1)
        incx = -1;
    incy = 1;
    if (y2 < y1)
        incy = -1;
    x = x1;
    y = y1;
    if (dx > dy)
    {
        displayPoint(x, y);
        e = 2 * dy - dx;
        inc1 = 2 * (dy - dx);
        inc2 = 2 * dy;
        for (i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            displayPoint(x, y);
        }
    }
    else
    {
        displayPoint(x, y);
        e = 2 * dx - dy;
        inc1 = 2 * (dx - dy);
        inc2 = 2 * dx;
        for (i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            displayPoint(x, y);
        }
    }
    glFlush();
}
*/

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 's':
        {
            glColor3f(1, 0, 0);
            simpleLine(150, 450, 450, 450);
            break;
        }
        case 'd':
        {
            glColor3f(1, 0, 0);
            dottedLine(450, 450, 450, 150);
            break;
        }
        case 'D':
        {
            glColor3f(1, 0, 0);
            dashedLine(150, 150, 150, 450);
            break;
        }
        case 'b':
        {
            glColor3f(1, 0, 0);
            bresenhams(150, 150, 450, 150);
            break;
        }
        default:
        {
            break;
        }
    }
}

void primitives(void)
{
    glColor3f(0, 1, 0);
    simpleLine(0, 300, 600, 300);
    simpleLine(300, 0, 300, 600);
    glutKeyboardFunc(keyboard);

}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 600, 600, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Assignment 2");

    initialize();
    cout << "s. simple Line"<<endl;
    cout << "d. dotted Line"<<endl;
    cout << "D. dashed Line"<<endl;
    cout << "s. bresenhams Line"<<endl;
    glutDisplayFunc(primitives);

    glutMainLoop();
}
