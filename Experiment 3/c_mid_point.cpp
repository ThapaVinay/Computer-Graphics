#include<GL/glut.h>

void init()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    int r=300;
    int y1=r,x1=0;
    int p=1-r;
    glBegin(GL_POINTS);
    while(x1<y1)
    {
        glVertex2d(x1,y1);
        glVertex2d(y1,x1);
        glVertex2d(-x1,y1);
        glVertex2d(-y1,x1);
        glVertex2d(-x1,-y1);
        glVertex2d(-y1,-x1);
        glVertex2d(y1,-x1);
        glVertex2d(x1,-y1);
        x1++;
        if(p<0)
        {
            p=p+2*(x1)+1;
        }
        else 
        {
            y1=y1-1;
            p=p+2*x1-2*y1+1;
        }
    }
    glEnd();
    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Circle Mid Point");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}