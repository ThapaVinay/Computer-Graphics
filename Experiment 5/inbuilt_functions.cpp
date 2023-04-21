
/*

1. inbuilt functions to draw a line 
   declaration: line (int x1, int y1, int x2, int y2) 
   this function takes 4 arguments and draw the line from point (x1,y1) to (x2,y2)

2. inbuilt functions to draw rectangle
   rectangle (int left, int top, int right, int bottom)

3. inbuilt functions to draw a circle
   circle( int x, int y, int z)

4. inbuilt functions to draw an argc
   arc(int x, int y, int start_angle, int end_angle, int r)



int main(int argc, char *, argv[])
{
   int gd = DETECT gm;
   initgraph(&gd, &gm, " ");
   setsecolor(5);
   rectangle(150, 350, 450, 100);
   getch();
   closegraph();
   return ();
}

*/


# include <GL/glut.h>
# include <graphics.h>
# include <stdioo.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);     
    glLoadIdentity();  
    glFlush();  
    glutSwapBuffers();

}

void init()
{
    glClearColor(1,0,0,0);  
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600,500);
    glutInitWindowPosition(500,100);
    // glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Inbuilt functions ");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
}