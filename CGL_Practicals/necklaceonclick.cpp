#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

int xcor = 0;
int ycor = 0;

void initialize(void)
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, 400, -300, 500);
}

void displayPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void drawCirclePoints(int centerX, int centerY, int x, int y)
{
    glColor3f(1, 1, 0.5);
    displayPoint(centerX + x, centerY + y);
    displayPoint(centerX + x, centerY - y);
    displayPoint(centerX - x, centerY + y);
    displayPoint(centerX - x, centerY - y);

    displayPoint(centerX + y, centerY + x);
    displayPoint(centerX + y, centerY - x);
    displayPoint(centerX - y, centerY + x);
    displayPoint(centerX - y, centerY - x);

    glFlush();
}

void drawCircle(int centerX, int centerY, int radius)
{
    int x = 0;
    int y = radius;
    int p = 3 - 2 * radius;

    while (x <= y)
    {
        drawCirclePoints(centerX, centerY, x, y);
        if (p > 0)
        {
            y--;
            p += 4 * (x - y) + 10;
        }
        else
            p += 4 * x + 6;

        x++;
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // main circle
    drawCircle(xcor, ycor, 70);

    // right side
    drawCircle(xcor + 80, ycor + 80, 30);

    // left side
    drawCircle(xcor - 80, ycor + 80, 30);

    // lower circle
    drawCircle(xcor, ycor - 100, 30);
    drawCircle(xcor, ycor - 160, 30);

    glFlush();
}

void mouseListener(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        xcor = x - 400;
        ycor = 500 - y;
        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Necklace");

    initialize();
    glutDisplayFunc(display);
    glutMouseFunc(mouseListener);

    glutMainLoop();
    return 0;
}