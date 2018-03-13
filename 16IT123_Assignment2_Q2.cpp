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

void idle() {
   glutPostRedisplay();
}


float angle = 0.0,move=0.0;
void display(void)
{
    float p1[] = {-50,-50},p2[] = {-50,50},p3[] ={50,50},p4[] = {50,-50};
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(move, 0.0f, 0.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(angle,0.0f,  0.0f,  1.0f);

    glBegin(GL_POLYGON);
        glVertex2fv(p1);
        glVertex2fv(p2);
        glVertex2fv(p3);
        glVertex2fv(p4);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
    angle += 1.0f;
    move += 0.01f;
}






int main(int argc, char** argv)
{


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150,100);
    glutCreateWindow("Rotation using vertex arrays.");
    intiopenGL();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
