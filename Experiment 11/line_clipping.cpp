
// in this algorithm we are taking a sqaure clipping window and the center of the square will be center
// only valid for lines that are partially outside


# include <GL/glut.h>
# include <iostream>
# include <math.h>
using namespace std;

int size = 500;
int winx1 = (-1 * ::size)/2, winy1 = (-1 * ::size)/2, winx2 = ::size/2, winy2 = ::size/2;   // size should be searched in the global namespace

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    glEnd();
    glFlush();
}

void drawSquare(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y1);
        glVertex2f(x2,y2);
        glVertex2f(x1,y2);
    glEnd();
    glFlush();
}

float slope(int x1, int y1, int x2, int y2)
{
    return (y2-y1)/(x2-x1);
}

int check_side(int x, int y)
{
    if(x < winx1)
    {
        return 1;  // left
    }
    else if(y > winy2)
    {
        return 2;  // top
    }
    else if(x > winx2)
    {
        return 3;  // right
    }
    else if(y < winy1)
    {
        return 4;  // bottom
    }
    else{
        return 0;  // no need of clipping
    }
}

int * clipping_func(int x1, int y1, int x2, int y2, int check)
{
    float m = slope(x1, y1, x2, y2);
    // cout << m << " ";
    if(check == 1)
    {
        x1 = winx1;
        y1 = y2 + m * (winx1 - x2);
    }
    else if (check == 2)
    {
        // cout << winy2 << " ";
        y1 = winy2;
        x1 = x2 + (winy2 - y2)/m;
    }
    else if (check == 3)
    {
        x1 = winx2;
        y1 = y2 + m * (winx2 - x2);
    }
    else if (check == 4)
    {
        y1 = winy1;
        x1 = x2 + (winy1 - y2) / m;
    }
    int * arr = new int [2];
    arr[0] = x1;
    arr[1] = y1;
    return arr;
}

void display()
{
    int x1 = -100, x2 = 400, x3 = 200, x4 = -400;
    int y1 = 100, y2 = 100, y3 = -400, y4 = -400;

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    drawLine(x1, x2, x3, x4);
    drawLine(y1, y2, y3, y4); 
    drawSquare(winx1, winy1, winx2, winy2);



}

void init(void)
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500,-500,500); 

}

void onClick(int button, int state, int x, int y)
{
    int  arr[] = {-100, 400, 200, -400};
    int  arr1[] = {100, 100, -400, -400};

    if(button == GLUT_LEFT_BUTTON)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        for(int i=0; i<4; i+=2)
        {
            int c = check_side(arr[i], arr[i+1]);
            int * temp = clipping_func(arr[i % 4], arr[(i+1) % 4], arr[(i+2) % 4], arr[(i+3) % 4], c);
            cout << temp[0] << " " << temp[1] << endl;
            arr[i] = temp[0], arr[i+1] = temp[1];
        }
        drawLine(arr[0], arr[1], arr[2], arr[3]);
        
        for(int i=0; i<4; i+=2)
        {
            int c = check_side(arr1[i], arr1[i+1]);
            int * temp = clipping_func(arr1[i % 4], arr1[(i+1) % 4], arr1[(i+2) % 4], arr1[(i+3) % 4], c);
            arr1[i] = temp[0], arr1[i+1] = temp[1];
        }

        drawLine(arr1[0], arr1[1], arr1[2], arr1[3]);

    }
}

int main(int argc, char ** argv)
{

    glutInit(&argc, argv);
    glutInitWindowSize(600, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Clipping");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(onClick);
    glutMainLoop();
    return 0;
}



