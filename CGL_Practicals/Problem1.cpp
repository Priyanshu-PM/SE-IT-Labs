//  Write a Program in OpenGL on Linux Platform to draw following pattern by a Line
//  using DDA Line Drawing Algorithm. (Use Mouse / Without Mouse to Plot the Points.) 
//  ( A Monitor Screen with a Hill On Display )

#include <windows.h>
#include <GL/glut.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


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


void primitives(void)
{
    glColor3f(0, 0, 0);

    // lower line
    simpleLine(100, 500, 350, 500);
    simpleLine(450, 500, 700, 500);

    simpleLine(150, 450, 650, 450);

    // upper line
    simpleLine(100, 100, 700, 100);
    simpleLine(150, 150, 650, 150);

    // left line
    simpleLine(100, 100, 100, 500);
    simpleLine(150, 150, 150, 450);

    // right line
    simpleLine(700, 100, 700, 500);
    simpleLine(650, 150, 650, 450);


    // monitor stand
    simpleLine(250, 600, 550, 600);

    simpleLine(250, 600, 350, 500);
    simpleLine(550, 600, 450, 500);

    // hills on monitor
    simpleLine(150, 450, 250, 375);
    simpleLine(250, 375, 350, 450);

    simpleLine(350, 450, 500, 290);
    simpleLine(500, 290, 650, 450);


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
    glutCreateWindow("Monitor hills using DDA");

    initialize();
    glutDisplayFunc(primitives);

    glutMainLoop();
}
