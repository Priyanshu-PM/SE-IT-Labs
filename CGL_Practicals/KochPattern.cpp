//  Write a Program in OpenGL on Linux Platform to draw a fractal patterns by using Koch curves.

#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>

#define XMAX 1200
#define YMAX 900
#define RADIAN (3.14/180)

using namespace std;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDALine(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, step, Xin ,Yin;
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

void initialize(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0.0, XMAX, YMAX, 0.0);

}
/*

void primitives(void)
{
    glColor3f(0, 1, 0);
    DDALine(0, 0, 800, 800);

}


*/


void drawKoch(float xa, float ya, float xb, float yb, int n)
{
    float xc, yc, xd, yd, midx, midy;

    xc = (2*xa+xb)/3;
    yc = (2*ya+yb)/3;
    xd = (2*xb+xa)/3;
    yd = (2*yb+ya)/3;

    midx = xc + ((xd-xc)*cos(60*RADIAN)) + ((yd-yc)*sin(60*RADIAN));
    midy = yc - ((xd-xc)*sin(60*RADIAN)) + ((yd-yc)*cos(60*RADIAN));


    if(n>0)
    {
        drawKoch(xa, ya, xc, yc, n-1);
        drawKoch(xc, yc, midx, midy, n-1);
        drawKoch(midx, midy, xd, yd, n-1);
        drawKoch(xd, yd, xb, yb, n-1);

    }
    else
    {
        glVertex2f(xa, ya);
        glVertex2f(xc, yc);

        glVertex2f(xc, yc);
        glVertex2f(midx, midy);

        glVertex2f(midx, midy);
        glVertex2f(xd, yd);

        glVertex2f(xd, yd);
        glVertex2f(xb, yb);
    }
}



void draw()
{

    int n;
    cout <<"Enter for how many iterations you want to draw : ";
    cin >> n;
    glBegin(GL_LINES);
    drawKoch(600, 100, 800, 400, n);
    drawKoch(800, 400, 400, 400, n);
    drawKoch(400, 400, 600, 100, n);
    glEnd();
    glFlush();
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(XMAX, YMAX);
    glutCreateWindow("Fractal patterns using Koch curve");

    initialize();

    glutDisplayFunc(draw);
    glutMainLoop();
}
