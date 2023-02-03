# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
# include <string.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5,0);    
        glVertex2f(5,0);
        glVertex2f(0,5);
    glEnd();
    
    glColor3f(1, 0, 0);
    glRasterPos2f(-2.4, 1.5);   // defines the position for the text
    char name[] = "Vinay Thapa";
    for (int i = 0; i < strlen(name); i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, name[i]);   // displays the text character wise
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


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Sqaure Graphics");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glClearColor(0,0,0,0);
    glutMainLoop();
}

