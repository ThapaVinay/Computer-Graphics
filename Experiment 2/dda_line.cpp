#include<GL/glut.h>
#include<stdio.h>
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

    int x1=400,y1=350,x2=50,y2=340;
    int delx=x1-x2;
    int dely=y1-y2;
    int steps;

    if(delx>dely)
        steps=delx;
    else
        steps=dely;

    delx=steps/delx;
    dely=steps/dely;

    glColor3d(0,0,0);
    glBegin(GL_POINTS);
        for(int i=0;i<steps;i++)
        {
            glVertex3f(x1,y1,0);
            if(i%delx==0) 
            {
                if(x2>x1) x1++;
                else x1--;
            }
            if(i%dely==0) 
            {
                if(y2>y1) y1++;
                else y1--;
            }
        }
    glEnd();

    glFlush();
 }

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowSize(500,500);
    glutInitWindowPosition(200,200);
    glutCreateWindow("DDA Line");

    glutDisplayFunc(display);
    init();

    glutMainLoop();
}
