#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;


vector<pair<double, double>> points;
vector <pair<double, double>> ans;

double rx, ry, angle;

void initialize(void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0,0,0);
}

struct Color
{
float r, g, b;
};


Color f_color = {1.0, 0.0, 0.0};
Color b_color = {0.0, 0.0, 0.0};

Color getPixelColor(int x, int y)
{
Color c;
glReadPixels(x, y, 1.0, 1.0, GLUT_RGB, GL_FLOAT, &c);
return c;
}

vector<pair<double, double>> createObject()
{
vector<pair<double, double>> points =
{

make_pair(175, 175),
make_pair(175, 425),
make_pair(375, 425),
make_pair(375, 575),
make_pair(175, 575),
make_pair(175, 625),
make_pair(425, 625),
make_pair(425, 425),
make_pair(575, 425),
make_pair(575, 625),
make_pair(625, 625),

make_pair(625, 375),
make_pair(425, 375),

make_pair(425, 225),
make_pair(625, 225),

make_pair(625, 175),

make_pair(375, 175),

make_pair(375, 375),
make_pair(225, 375),

make_pair(225, 375),
make_pair(225, 175)

};

ans = points;
return ans;
}


void boundaryFill(int x, int y)
{
Color c = getPixelColor(x, y);
if((c.r != b_color.r || c.r != b_color.g || c.b != b_color.b) && (c.r != f_color.r || c.g != f_color.g || c.b != f_color.b))
{
glBegin(GL_POINTS);
glColor3f(f_color.r, f_color.g, f_color.b);
glVertex2f(x, y);
glEnd();
glFlush();
boundaryFill(x+1, y);
boundaryFill(x-1, y);
boundaryFill(x, y+1);
boundaryFill(x, y-1);
}

}

void displayPoint(float x, float y)
{
glBegin(GL_POINTS);
glVertex2f(x, y);
glEnd();
}

void bresenhams(int x1, int y1, int x2, int y2)
{
float x, y, dx, dy, incx, incy, inc1, inc2, e;
dx = x2 - x1;
dy = y2 - y1;

if(dx < 0)
dx = -dx;

if(dy < 0)
dy = -dy;

incx = x2 > x1 ? 1 : -1;
incy = y2 > y1 ? 1 : -1;
x = x1;
y = y1;
if(dx > dy)
{
displayPoint(x, y);
e = 2 * dy - dx;
inc1 = 2 * (dy - dx);
inc2 = 2 * dy;

for(int i = 0; i < dx; i++)
{
if(e >= 0)
{
y+= incy;
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

y += incy;
displayPoint(x, y);
}
}
}

void floodFill(int x, int y)
{

cout << "Inside the flood fill ";

Color old = {1.0, 1.0, 1.0};
Color c = getPixelColor(x, y);

if(c.r == old.r && c.g == old.g && c.b == old.b)
{
glBegin(GL_POINTS);
glColor3f(1.0, 0.0, 0.0);
glVertex2f(x, y);
glEnd();
glFlush();
floodFill(x+1, y);
floodFill(x-1, y);
floodFill(x, y+1);
floodFill(x, y-1);
}
glFlush();

}

void drawObject()
{
//glPointSize(2);
for(int i = 0; i < points.size()-1; i++)
{
double x1 = ans[i].first;
double y1 = ans[i].second;

double x2 = ans[i+1].first;
double y2 = ans[i+1].second;

bresenhams(x1, y1, x2, y2);
}

double x1 = ans[ans.size()-1].first;
double y1 = ans[ans.size()-1].second;

double x2 = ans[0].first;
double y2 = ans[0].second;

bresenhams(x1, y1, x2, y2);
}


void rotateObject(double x, double y, vector<pair<double, double>> &points)
{
    angle = (angle * 3.14159) / 180.0; // Convert angle to radians

    // Create the rotation matrix
    double rotationMatrix[3][3] = {
        {cos(angle), -sin(angle), x - x * cos(angle) + y * sin(angle)},
        {sin(angle), cos(angle), y - x * sin(angle) - y * cos(angle)},
        {0, 0, 1}};

    // Apply rotation to each point of the object
    for (int i = 0; i < points.size(); i++)
    {
        double px = points[i].first;
        double py = points[i].second;

        double new_px = rotationMatrix[0][0] * px + rotationMatrix[0][1] * py + rotationMatrix[0][2];
        double new_py = rotationMatrix[1][0] * px + rotationMatrix[1][1] * py + rotationMatrix[1][2];

        ans[i] = make_pair(new_px, new_py);
    }
}


void keyboard(char unsigned key, int x, int y)
{
if(key == 'r')
{
initialize();
rotateObject(x, y, points);
drawObject();

        f_color.r = 1.0;
        f_color.g = 0.0;
        f_color.b = 0.0;
boundaryFill(400, 400);

}
}

void mouseListener(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        cout<<" x: "<<x<<" y: "<<y<<endl;
        cout << "Enter the rotation angle : ";
        cin >> angle;
        points = createObject();
        rotateObject(x,y,points);
        glColor3f(0.0, 0.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        drawObject();
        floodFill(400, 400);
        glFlush();
       
    }
    //glutKeyboardFunc(keyboard);
}

void primitives()
{
/*
glBegin(GL_LINES);
glVertex2f(0, 400);
glVertex2f(800, 400);

glVertex2f(400, 0);
glVertex2f(400, 800);
glEnd();
*/

points = createObject();
drawObject();

glFlush();

}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(0, 0);
glutInitWindowSize(800, 800);
glutCreateWindow("swastik rotation");

gluOrtho2D(0, 800, 800, 0);

initialize();
glutDisplayFunc(primitives);

glutMouseFunc(mouseListener);
glutMainLoop();
return 0;
}