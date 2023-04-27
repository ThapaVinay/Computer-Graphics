
# include <GL/glut.h>
# include <iostream>
# include <math.h>
using namespace std;

int width;
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // gluOrtho2D(-500, 500, -500, 500);
    
    // scales the coordinateds according to the window
    if(w <= h)
        gluOrtho2D(-500, 500, -500*h/w, 500*h/w);
    else
        gluOrtho2D(-500*w/h, 500*w/h, -500, 500);

    glMatrixMode(GL_MODELVIEW);
}

void fill_color(int width)
{
    
}


void display()
{
     glClear(GL_COLOR_BUFFER_BIT);
    int x = -500, y = 500;

    glBegin(GL_LINES);

        // vertical lines
        while(x <= 500)
        {
            glVertex2f(x,y);
            glVertex2f(x,-y);
            x += width;
        }

        // horizontal lines
        while(y >= -500)
        {
            glVertex2f(x,y);
            glVertex2f(-x,y);
            y -= width;
        }

    glEnd();
    glFlush();
}

void init(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500);  // the range of the coordinates
}

int main(int argc, char ** argv)
{ 
    // int width = 100;
    cout << "Enter the grid width :";
    cin >> width;  

    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE);
    glutCreateWindow("Fuck you SID !");
    init(); 

    // passing parameter to the display function
    glutDisplayFunc(display);
    
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}

