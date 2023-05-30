// Write a program in OpenGL on Linux Platform to draw 
// a design shown on Right using Bresenhem Circle 
// Drawing Algorithm. User should only give centre 
// coordinates and radius. Rest should be drawn 
// automatically. Use Mouse/Without Mouse to Plot the 
// Points.


#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cx, cy, radius;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void simpleLine(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, step, Xin, Yin;
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
    for(int i = 0; i < step; i++)
    {
        x += Xin;
        y += Yin;
        displayPoint(x, y);
    }
    glFlush();
}

void drawCirclePoints(int cx , int cy, int x, int y)
{
    glColor3f(0, 0, 0);
    glBegin(GL_POINTS);

    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);

    glVertex2i(cx + y, cy + x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy - x);

    glEnd();
    glFlush();
}

void drawCircle()
{
    int x = 0;
    int y = radius;
    int d = 3 - 2*radius;

    drawCirclePoints(cx, cy, x, y);
    while(y >= x)
    {
        x++;
        if(d > 0)
        {
            y--;
            d += 4 * (x - y) + 10;
        }
        else
        {
            d += 4*x + 6;
        }
        drawCirclePoints(cx, cy, x, y);
    }
}

void keyboard(unsigned char key, int x, int y)
{
    cout << "The radius of the circle is : "<<key<<endl;
    cout << "The center of the circle is : "<<"( "<<cx<<", "<<cy<<" )"<<endl;
    radius = (key - '0') * 25;
    drawCircle();

}

void mouseListener(int button, int state, int x, int y)
{
    cout << "The mouse co-ordinates are : "<<"( "<<x<", "<<y<<" )"<<endl;
    cout << "Enter the radius of the circle : "<<endl;
    cx = x;
    cy = y;
    glutKeyboardFunc(keyboard);

}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0, 800, 800, 0);
}

void primitives(void)
{
    glColor3f(0, 0, 0);
    simpleLine(0, 400, 800, 400);
    simpleLine(400, 0, 400, 800);
    glutMouseFunc(mouseListener);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Necklace");

    initialize();

    glutDisplayFunc(primitives);

    glutMainLoop();
    return 0;
}

