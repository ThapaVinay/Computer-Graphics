# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>

float x_position = -10.0;
int state= 1;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glBegin(GL_POLYGON);
        glColor3f(1,0,0);
        glVertex2f(x_position, 1.0);
        glVertex2f(x_position, 0.0);
        glVertex2f(x_position+1.0, 0.0);
        glVertex2f(x_position+1.0, 1.0);
    glEnd();
    glutSwapBuffers();
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);

    switch(state)
    {
        case 1:
            if(x_position < 9)
            {
                x_position += 0.5;
            }
            else{
                state = 0;
            }
            break;
        case 0:
            if(x_position > -10)
            {
                x_position -= 0.5;
            }
            else{
                state = 1;
            }
    }
}


void reshape(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);

}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Sqaure Graphics");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);

    glClearColor(0,0,0,0);
    glutMainLoop();
}