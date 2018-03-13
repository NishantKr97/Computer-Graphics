#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;


void intiopenGL()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1,1.0,1.0);
    gluOrtho2D(-500 , 500 , -500 , 500);

}


float round_of(double a){
    return floor(a+0.5);
}

double X1,Y1,X2,Y2;

void DDLD(){

    double dx=X2-X1;
    double dy=Y2-Y1;
    double step=(abs(dx)>abs(dy))?abs(dx):abs(dy);
    double xi,yi,x=X1,y=Y1;
    xi=dx/(float)step;
    yi=(-1*dy)/(float)step;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_POINTS);
    glVertex2d(x,y);
    for(int i=0;i<step;i++){
        x=x+xi;
        y=y+yi;
        glVertex2d(round_of(x),round_of(y));
    }
    glEnd();

    glFlush();
    glutSwapBuffers();

}

int main(int argc, char** argv)
{

    cout<<"Enter x1,y1:";
    cin>>X1>>Y1;
    cout<<"Enter x2,y2:";
    cin>>X2>>Y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150,100);
    glutCreateWindow("DDLD Algo.");
    intiopenGL();
    glutDisplayFunc(DDLD);
    glutMainLoop();
    return 0;
}
