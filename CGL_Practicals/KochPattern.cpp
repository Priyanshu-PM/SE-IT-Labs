//  Problem Statement : Draw a fractal pattern using Koch CURVECAPS

#include <GL/glut.h>
#include <bits/stdc++.h>
#include <math.h>

#define XMAX 1200
#define YMAX 900
#define RADIAN (3.14/180)

using namespace std;

void initialize(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    gluOrtho2D(0.0, XMAX, YMAX, 0.0);

}

void drawKoch(float xa, float ya, float xb, float yb , int n)
{
    float xc, yc, xd, yd, midx, midy;

    xc = (2*xa+xb)/3;
    yc = (2*ya+yb)/3;
    xd = (2*xb+xa)/3;
    yd = (2*yb+ya)/3;

    midx = xc + ((xd-xc)*cos(60*RADIAN)) + ((yd-yc)*sin(60*RADIAN));
    midy = yc - ((xd-xc)*sin(60*RADIAN)) + ((yd-yc)*cos(60*RADIAN));

    if(n > 0)
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
    cout << "Enter the number of iterations you want to draw in : ";
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
    glutCreateWindow("Fractal Pattern using Koch Curve");

    initialize();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
