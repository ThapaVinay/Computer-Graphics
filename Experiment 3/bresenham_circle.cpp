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
    int xc= 0, yc = 0;  // centre of the circle
    int r = 300;  // radius of the circle
    int y = r,x = 0;   // the start point 
    int d = 1-r;


    glBegin(GL_POINTS);
    while (x <= y) {
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc - y, yc - x);
        if (d < 0) {
            d += 4 * x + 6;
        } else {
            d += 4 * (x - y) + 10;
            y--;
        }
        x++;
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
    glutCreateWindow("Circle Bresenham");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}