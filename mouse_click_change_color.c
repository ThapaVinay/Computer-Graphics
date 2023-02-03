
// projebction : we use projection in the z-axis to determine which object to be seen bigger and which one smaller 
//                  based on the distance from the viewer.
// the objects between the near clip plane and the far clip plane will be visible.

# include <GL/glut.h>
# include <stdio.h>
# include <iostream>
bool isClicked = false;
using namespace std;

bool insideTriangle(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
    float area = x1 * (y2- y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    float a = abs(x * (y1- y2) + x1 * (y2 - y) + x2 * (y - y1));   // we need the absolute value else it will always be same 
    float b = abs(x * (y3- y1) + x3 * (y1 - y) + x1 * (y - y3));
    float c = abs(x * (y2- y3) + x2 * (y3 - y) + x3 * (y - y2));

    if(area == a+b+c)
    {
        return true;
    }
    else{
        return false;
    }

}

void object_coordinates(int x, int y, double & posX, double & posY, double & posZ)
{
    int viewport[4];
    double modelview[16];
    double projection[16];
    float winX, winY, winZ;

    // Get the viewport and matrices.
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    // Transform the window coordinates to object coordinates.
    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
    gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);   

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    if(isClicked == true)
    {
        glColor3f(0,1,0);
    }
    else{
        glColor3f(1,0,0);
    }
    glBegin(GL_POLYGON);
        glVertex2f(5,0);
        glVertex2f(0,5);
        glVertex2f(-5,0);
    glEnd();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}


void mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        double posX, posY, posZ;
        object_coordinates(x,y,posX, posY, posZ);
        if(insideTriangle(posX, posY, 5,0 ,0,5, -5,0))    // we use area to check it 
        {
            isClicked = !isClicked;
        } 
        glutPostRedisplay();
    }
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("CHANGE COLOR");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glClearColor(0,0,0,0);
    glutMainLoop();
}