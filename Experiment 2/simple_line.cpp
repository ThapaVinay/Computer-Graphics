# include <stdio.h>
# include <GL/glut.h>
# include <math.h>
# include <iostream>

using namespace std;

float xa = 12, ya = 12, xb = 200, yb = 200;

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   
    glColor3f(0,0,0);

    glBegin(GL_POINTS);
        float m = (yb - ya) / (xb - xa);
        float c = ya - m * xa;
        for(float x = xa; x < xb; x++)
        {
            float y = m * x + c;
            glVertex2f(x,y);
        }
    glEnd();
    glFlush();

}

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);  
    glutInitWindowSize(600,500);
    glutInitWindowPosition(500,100);
    glutInitWindowPosition(500,100);

    glutCreateWindow("Simple Line");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
    
}