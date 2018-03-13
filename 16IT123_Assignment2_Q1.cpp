#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;

#define sign(x) ((x>0)?1:((x<0)?-1:0))


void intiopenGL()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1,1.0,1.0);
    gluOrtho2D(-500,500,-500,500);

}



void bresenham(int x1, int y1, int x2, int y2)
{
    int y = y1;
    int m_new = 2 * (y2 - y1);
    int slope_error = m_new - (x2 - x1);
    for (int x = x1;   x <= x2; x++)
   {
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
      slope_error += m_new;


      if (slope_error >= 0)
      {
         y++;
         slope_error  -= 2 * (x2 - x1);
      }
}
}

void display(void)
{
    bresenham(-250,-250,250,250);

    glutSwapBuffers();

}





int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150,100);
    glutCreateWindow("DDLD Algo.");
    intiopenGL();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
