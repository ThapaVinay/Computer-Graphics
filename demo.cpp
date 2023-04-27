#include<GL/glut.h>
#include<iostream>
using namespace std;

void init()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255,255,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);
}
int flag=0;
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
}

void drawline(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glEnd();
}

void draw_man(int x,int y,int pos)
{
    
    circle(x,y,20);
    drawline(x,y-20,x,y-60);
    if(pos==0)
    {
        drawline(x,y-60,x-20,y-80);
        drawline(x,y-60,x+20,y-80);
        drawline(x,y-30,x-20,y-40);
        drawline(x,y-30,x+20,y-40);
    }
    else if(pos==1)
    {
        drawline(x,y-60,x-15,y-80);
        drawline(x,y-60,x+15,y-80);
        drawline(x,y-30,x-15,y-40);
        drawline(x,y-30,x+15,y-40);
    }
    else if(pos==2)
    {
        drawline(x,y-60,x-10,y-80);
        drawline(x,y-60,x+10,y-80);
        drawline(x,y-30,x-10,y-40);
        drawline(x,y-30,x+10,y-40);
    }
    else if(pos==3) 
    {
        drawline(x,y-60,x-5,y-80);
        drawline(x,y-60,x+5,y-80);
        drawline(x,y-30,x-5,y-40);
        drawline(x,y-30,x+5,y-40);
    }
    else if(pos==4)
    {
        drawline(x,y-60,x-2,y-80);
        drawline(x,y-60,x+2,y-80);
        drawline(x,y-30,x-2,y-40);
        drawline(x,y-30,x+2,y-40);
    }
    else if(pos==5) 
    {
        drawline(x,y-60,x-5,y-80);
        drawline(x,y-60,x+5,y-80);
        drawline(x,y-30,x-5,y-40);
        drawline(x,y-30,x+5,y-40);
    }
    else if(pos==6)
    {
        drawline(x,y-60,x-10,y-80);
        drawline(x,y-60,x+10,y-80);
        drawline(x,y-30,x-10,y-40);
        drawline(x,y-30,x+10,y-40);
    }
    else if(pos==7)
    {
        drawline(x,y-60,x-15,y-80);
        drawline(x,y-60,x+15,y-80);
        drawline(x,y-30,x-15,y-40);
        drawline(x,y-30,x+15,y-40);
    }
    
}
void draw_obstacle(int x,int y)
{
    drawline(x,y,x,y+40);
    drawline(x,y+10,x-20,y+20);
    drawline(x,y+10,x+20,y+20);
    drawline(x,y+20,x-12,y+30);
    drawline(x,y+20,x+12,y+30);
    drawline(x,y+30,x-5,y+35);
    drawline(x,y+30,x+5,y+35);
    
}
void onClick(int button,int state,int x,int y)
{
    cout<<"Clicked";
    flag=1;
}
void disp()
{
    // int x=0,y=0;
    
    // int cox=0,coy=0;
    // int xo=500,yo=0;
    // int pos=0,obstacle=500;
    // int gap=4;
    // while(true)
    // {
         glClear(GL_COLOR_BUFFER_BIT);
    //     if(flag==1)
    //     {
    //         if(y>60) gap=(-1)*gap;
    //         y+=gap;
    //         draw_man(x,y+80,pos%8);
    //         if(y==0)
    //         {
    //             gap=(-1)*gap;
    //             flag=0;
    //         }
    //     }
    //     else
    //     {
    //         draw_man(x,y+80,pos%8);
    //         pos++;
    //     }
    //     drawline(500,0,-500,0);
    //     draw_obstacle(xo,yo);
    //     if(xo==x+60)
    //     {
    //         flag=1;
    //     }

        
    //     glFlush();
    //     system("sleep 0.02");
        
    //    // glutMouseFunc(onClick);
        
    //     xo-=4; 
    //     if(xo<(-500 - 20)) xo=500+20;
    // }
}

int main(int a,char** b)
{

    int x=0,y=0;
    
    int cox=0,coy=0;
    int xo=500,yo=0;
    int pos=0,obstacle=500;
    int gap=4;

    glutInit(&a,b);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Graphic Run...");
    glutDisplayFunc(disp);
    init();
    game:
    // while(true)
    // {
        disp();
        //glClear(GL_COLOR_BUFFER_BIT);
        if(flag==1)
        {
            if(y>60) gap=(-1)*gap;
            y+=gap;
            draw_man(x,y+80,pos%8);
            if(y==0)
            {
                gap=(-1)*gap;
                flag=0;
            }
        }
        else
        {
            draw_man(x,y+80,pos%8);
            pos++;
        }
        drawline(500,0,-500,0);
        draw_obstacle(xo,yo);
        if(xo==x+60)
        {
            flag=1;
        }

        
        glFlush();
        system("sleep 0.02");
        glutMouseFunc(onClick);
       // glutMouseFunc(onClick);
        
        xo-=4; 
        if(xo<(-500 - 20)) xo=500+20;

         

        goto game;

        glutMainLoop();
    //}//disp();


    
   
    return 0;
}