//  Write a Program in OpenGL on Linux Platform to draw a Dash-Dot-Dash Line & Dash
//  Line using DDA Line Drawing Algorithm. Divide the screen in four quadrants with
//  centre as (0,0). Use Mouse / Without Mouse to Plot the Points.

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
    displayPoint(x, y);

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        displayPoint(x, y);
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
    displayPoint(x, y);

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        if(i % 10 != 0 && (i+1) % 10 != 0)
        {
            displayPoint(x, y);
        }
    }
    glFlush();
}

void dashDotDashLine(int x1, int y1, int x2, int y2)
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
    displayPoint(x, y);

    int dashPattern = 10;
    int patternIndex = 0;

    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;

        if(patternIndex < dashPattern)
        {
            displayPoint(x, y);
            patternIndex++;
        }
        else
        {
            i += 4;
            x += 2*Xin;
            y += 2*Yin;
            displayPoint(x, y);
            x += 2*Xin;
            y += 2*Yin;
            patternIndex = 0;
        }
    }

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 't':
        {
            glColor3f(1, 0, 0);
            dashedLine(200, 200, 600, 200);
            break;
        }
        case 'b':
        {
            glColor3f(1, 0, 0);
            dashedLine(200, 600, 600, 600);
            break;
        }
        case 'l':
        {
            glColor3f(1, 0, 0);
            dashDotDashLine(200, 200, 200, 600);
            break;
        }
        case 'r':
        {
            glColor3f(1, 0, 0);
            dashDotDashLine(600, 200, 600, 600);
            break;
        }
    }
}

void primitives(void)
{
    glColor3f(0, 1, 0);
    simpleLine(0, 400, 800, 400);
    simpleLine(400, 0, 400, 800);

    glutKeyboardFunc(keyboard);

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
    glutCreateWindow("Dash-dot-Dash lines using DDA");

    initialize();
    glutDisplayFunc(primitives);

    glutMainLoop();
    return 0;
}
