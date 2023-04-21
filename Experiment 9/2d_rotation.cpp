// this code will rotate each point with respect to the origin (0,0).


# include <GL/glut.h>
# include <iostream>
# include <math.h>
using namespace std;


int rotate_x(int x, int y, float radian)
{
    return x * cos(radian) - y * sin(radian);
}

int rotate_y(int y, int x,float radian)
{
    return x * sin(radian) + y * cos(radian);
}

void square(int x1, int y1, int x2, int y2)
{

    glBegin(GL_QUADS);
        glVertex2f(x1,y1);
        glVertex2f(x2,y1);
        glVertex2f(x2,y2);
        glVertex2f(x1,y2);
    glEnd();
    glFlush();
}

void display()
{
    int x1 = 0, y1 = 0, x2 = 200, y2 = 200;
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();  // current matrix to the initial state 

    // draw a square
    glColor3d(0,1,1);
    square(x1, y1, x2, y2);

    int angle = 45;
    cout << "Enter the angle : ";
    cin >> angle;
    
    float radian = angle * (M_PI / 180.0); // Convert to angles

    // using rotation
    float new_x1, new_x2, new_y1, new_y2, new_x3, new_y3, new_x4, new_y4;

    new_x1 = rotate_x(x1,y1, radian);
    new_y1 = rotate_y(y1,x1, radian);

    new_x2 = rotate_x(x2,x1, radian);
    new_y2 = rotate_y(x1,x2, radian);

    new_x3 = rotate_x(x2,y2, radian);
    new_y3 = rotate_y(y2,x2, radian);

    new_x4 = rotate_x(x1,y2, radian);
    new_y4 = rotate_y(y2,x1, radian);


    // cout << "new points " << new_x1 << " " << new_y1 << " " << new_x2 << " " << new_y2 << " " << new_x3 << " " << new_y3 << " " << new_x4 << " " << new_y4;
    
    // glClear(GL_COLOR_BUFFER_BIT);  // clears the previous content

    glColor3d(1,0,0);

    glBegin(GL_QUADS);
        glVertex2f(new_x1,new_y1);

        glVertex2f(new_x2,new_y2);
        glVertex2f(new_x3,new_y3);
        glVertex2f(new_x4,new_y4);
            
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
    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Point Program");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



