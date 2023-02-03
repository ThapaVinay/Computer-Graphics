
// projebction : we use projection in the z-axis to determine which object to be seen bigger and which one smaller 
//                  based on the distance from the viewer.
// the objects between the near clip plane and the far clip plane will be visible.

# include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex3f(5,0,-5);
        glVertex3f(0,5,-5);
        glVertex3f(-5,0,-5);
    glEnd();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    gluPerspective(40,1,2.0,50.0);    // fov, ratio,z_near, z_far 
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("PROJECTION");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0,0,0,0);
    glutMainLoop();
}