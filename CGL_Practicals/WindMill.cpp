//  Problem Statement : Write a program in opengl to animate any one scene (Windmill)

#include <GL/glut.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int frameNumber = 0;

void drawWindMill()
{
    int i;

    glColor3f(1.0, 1.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex2f(-0.05, 0);
    glVertex2f(-0.05, 3);
    glVertex2f(0.05, 3);
    glVertex2f(0.05, 0);
    glEnd();

    glTranslatef(0, 3, 0);
    glColor3f(1.0, 0.0, 0.0);
    glRotated(frameNumber*(180.0/45), 0, 0, 1);

    for(int i = 0; i < 4; i++)
    {
        glRotated(90, 0, 0, 1);
        
        glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.0);
        glVertex2f(1.0, 0.2);
        glVertex2f(1.0, -0.2);
        glEnd();
        glFlush();
    }

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glTranslated(2.2, 1.6, 0);
    glScaled(0.4, 0.4, 1);
    drawWindMill();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.7, 0.8, 0);
    glScaled(0.7, 0.7, 1);
    drawWindMill();
    glPopMatrix();

    glutSwapBuffers();
}

void doFrame(int v)
{
    frameNumber++;
    glutPostRedisplay();
    glutTimerFunc(10, doFrame, 0);
}

void initialize(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 7, -1, 4, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(900, 800);
    glutCreateWindow("Windmill Animation");

    initialize();
    glutDisplayFunc(display);
    glutTimerFunc(200, doFrame, 0);
    glutMainLoop();
    return 0;
}
