# include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);     // clears the previous contents of the window
    glLoadIdentity();  // resets the geometry
    glFlush();  // display any function you make 
    glutSwapBuffers();

}

void init()
{
    glClearColor(1,1,1,1);   // alpha is used for blending or luminance 
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(500,100);
    // glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Line Program");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
}