# include <GL/glut.h>
# include <iostream>
# include <math.h>
using namespace std;

int man_y = 100, ob_x = 500;
int pos = 0;
int flag = 0;
int jump = 0;
bool mouse = false;
float t = 100;

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
    // glFlush();
}

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    // glFlush();
}


// obstacle
void obstacle(int x, int y)
{
    drawLine(x, y, x, 50);
    drawLine(x, y+10, x-20, y+30);
    drawLine(x, y+10, x+20, y+30);

    drawLine(x, y+30, x-10, y+40);
    drawLine(x, y+30, x+10, y+40);
}

// man
void man(int x, int y, int pos)
{
    // head
    circle(x, y, 20);

    // body
    drawLine(x,y-20, x, y-70);

    if(pos == 0)
    {
        // arms
        drawLine(x, y-20, x-20, y-50);
        drawLine(x, y-20, x+20, y-50);
        
        // legs
        drawLine(x , y-70, x-20, y-100);
        drawLine(x , y-70, x+20, y-100);
    }
    else if (pos == 1)
    {
        drawLine(x, y-20, x-15, y-50);
        drawLine(x, y-20, x+15, y-50);
        drawLine(x, y-70, x-10, y-100);
        drawLine(x, y-70, x+10, y-100);
    }
    else if (pos == 2)
    {
        drawLine(x, y-20, x-10, y-50);
        drawLine(x, y-20, x+10, y-50);
        drawLine(x , y-70, x-5, y-100);
        drawLine(x , y-70, x+5, y-100);
    }
    else if (pos == 3)
    {
        drawLine(x, y-20, x-5, y-50);
        drawLine(x, y-20, x+5, y-50);
        drawLine(x , y-70, x, y-100);
        drawLine(x , y-70, x, y-100);
    }
    else if (pos == 4)
    {
        drawLine(x, y-20, x-10, y-50);
        drawLine(x, y-20, x+10, y-50);
        drawLine(x , y-70, x-5, y-100);
        drawLine(x , y-70, x+5, y-100);
    }
    else if(pos == 5)
    {

        drawLine(x, y-20, x-15, y-50);
        drawLine(x, y-20, x+15, y-50);
        drawLine(x , y-70, x-10, y-100);
        drawLine(x , y-70, x+10, y-100);
    }
}

void display()
{
    // path
    glClear(GL_COLOR_BUFFER_BIT);
    drawLine(-500,0, 500,0);
    obstacle(ob_x,0);
    man(-70,man_y,pos);
    glFlush();

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

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(t,timer,0);   // it will re-run the timer function after a particular time
    if(ob_x > -500)
    {
        ob_x = ob_x - 10;
    }else{
        ob_x = 500;
    }

    if(flag == 0)
    {
        man_y = 100;
    }

    if(flag == 1)
    {
        if(jump <= 7)
        {
            man_y += 12;
            pos = 0;
            jump ++;
        }
        else if(jump <= 15)
        {
            man_y -= 12;
            pos = 0;
            jump ++;
        }  
        if(jump == 16)
        {
            mouse = false;
            flag = 0;
            // if((ob_x+20) < -90)
            // {
            //     glutLeaveMainLoop();  // exits the window
            // }
        }
    }
    else{
        pos = (pos+1) % 6;
    }
}

void onClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && mouse == false)
    {
        flag = 1;
        jump = 0;
        mouse = true;
        if(t > 10)
            t -= 10;
    }
}

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("THE GAME");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(onClick);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
    return 0;
}