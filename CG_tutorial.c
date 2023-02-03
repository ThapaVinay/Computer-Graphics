# include <GL/gl.h>  // header file for openGL API 
# include <GL/glu.h>  // openGL utility functions to interact with the openGL easier
# include <GL/glut.h>  // openGL utility toolkit
# include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();  // resets the transformation matrix


    /*  
    DRAW POINTS 
    glPointSize(10);   // points size 
    glBegin(GL_POINTS);   // begin of the diagram 
        glVertex2f(5,5);
        glVertex2f(-5,-5);     // vertex with two arguments of float type 
    glEnd();  // end of the diagram 
    */

    
   // DRAW TRAINGLES
    glTranslatef(5,5,0);   // it shifts the origin to a particular position
    glShadeModel(GL_FLAT);  // the colors will not blend and only the first color will be shown 
    glBegin(GL_TRIANGLES);  // assume that the origin is in the center of the window
        //glColor3f(1,0,0);  // it is use to set the color for the primitive or diagram
        glVertex2f(-5,0);    
        glVertex2f(5,0);
        glVertex2f(0,5);
    glEnd();
    glutSwapBuffers();  
    // glFlush();
    // GL_POLYGONS - it has two sides #front side {points defined in anticlockwise direction} and #back side {clockwise direction}.


}

void reshape(int w, int h)
{
    glViewport(0,0,w,h);   // it is the area where the graphics will be displayed
    glMatrixMode(GL_PROJECTION);  // switch to projection matrix {projection : screen resolution}
    glLoadIdentity();

    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);  
    
    // GLUT_DOUBLE: initialises double buffer display mode in which front buffer consists of the frame that is currently displaying
    // and the back buffer draws the next frames that is going to be displayed.
    // we use glutSwapBuffers() function instead of glFlush() to swap the buffers.
    // It removes the occurance of distorted images.
    
    glutInitWindowPosition(500,100);
    glutInitWindowSize(500,500);

    glutCreateWindow("Vinay Thapa");
    glutDisplayFunc(display); // it is where we will draw 

    glutReshapeFunc(reshape); // it is called whenever the window is reshaped

    //glutTimerFunc(0,timer,0);  // it calls a function again and again after a particular amount of time

    glClearColor(0,0,0,0); // to change the background of the window
    glutMainLoop(); // to loop and not just exit 
}   