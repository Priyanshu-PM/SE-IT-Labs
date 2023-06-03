#include <GL/gl.h>
#include <freeglut.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>

using namespace std;

int flag = 0;

struct Color
{
    float r, g, b;
};

Color f_color;

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void initialize(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
}

Color getPixelColor(float x, float y)
{
    Color c;
    glReadPixels(x, y, 1.0, 1.0, GLUT_RGB, GL_FLOAT, &c);
    return c;
}

void simpleLine(int x1, int y1, int x2, int y2)
{
    float x, y, dx, dy, step, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    Xin = dx/step;
    Yin = dy/step;

    x = x1;
    y = y1;
    displayPoint(x, y);
    for(int i = 0; i <= step; i++)
    {
        x += Xin;
        y += Yin;
        displayPoint(x,y);
    }
    glFlush();
}

void floodFill(int x, int y)
{
    Color c = getPixelColor(x, y);

    Color old = {1.0,1.0, 1.0};
    if(c.r == old.r && c.g == old.g && c.b == old.b)
    {
        glBegin(GL_POINTS);
        glColor3f(f_color.r, f_color.g, f_color.b);
        glVertex2f(x, y);
        glEnd();
        glFlush();
        floodFill(x, y+1);
        floodFill(x, y-1);
        floodFill(x+1, y);
        floodFill(x-1, y);
    }
    glFlush();
}


void mouseLister(int button, int state, int x, int y)
{
    if(state == GLUT_DOWN && flag == 0)
    {
        draw_fig();
        flag = 1;
    }
    else if(state == GLUT_DOWN && flag == 1)
    {
        initialize();
        rotate_fig();
        flag = 2;
    }
    
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Chess board");
    gluOrtho2D(0, 800, 0, 800);

    initialize();

    glutDisplayFunc();
    glutMainLoop();
    return 0;
}