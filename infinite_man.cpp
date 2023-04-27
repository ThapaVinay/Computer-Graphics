# include <GL/glut.h>
# include <iostream>
# include <math.h>
using namespace std;


void circle(int xc,int yc,int r)
{
    int x=0,y=r;
    int p=1-r;
    glBegin(GL_POINTS);
    while(x<y)
    {
        glVertex2f(x+xc,y+yc);
        glVertex2f(y+xc,x+yc);
       
        glVertex2f((-1)*x+xc,y+yc);
        glVertex2f((-1)*y+xc,x+yc);

        glVertex2f((-1)*x+xc,(-1)*y+yc);
        glVertex2f((-1)*y+xc,(-1)*x+yc);

        glVertex2f(x+xc,(-1)*y+yc);
        glVertex2f(y+xc,(-1)*x+yc);

        x++;
        if(p<0)
        {
            p+=2*x+1;
        }
        else
        {
            y--;
            p+=2*x-2*y+1;
        }
    }
    glEnd();
    glFlush();
}

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glFlush();
}


// obstacle
void obstacle()
{
    drawLine(0,0, 0,50);
    drawLine(0,10, -25,30);
    drawLine(0,10, 25,30);

    drawLine(0, 30, -10,40);
    drawLine(0, 30, 10,40);
}

// man
void man()
{
    // head
    circle(-70, 100, 20);

    // body
    drawLine(-70,80, -70,30);

    // legs
    drawLine(-70,30, -90, 0);
    drawLine(-70,30, -50, 0);

    // arms
    drawLine(-70, 80, -90,50);
    drawLine(-70, 80, -50,50);
}



void display()
{
    drawLine(-500,0, 500,0);
    obstacle();
    man();

}

void init(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
    glMatrixMode(GL_MODELVIEW);  
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("THE GAME");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}