#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2i(x+pntX1, y+pntY1);
	glEnd();
}


void myInit (void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500.0, -400.0, 400.0);
}


void midPointCircleAlgo()
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	plot(x, y);

	while (y > x)
	{
		if (d < 0)
		{
			d += 2*x+1;
		}
		else
		{
			y--;
			d += 2*(x-y)+1;
		}
		x++;
		plot(x, y);
		plot(x, -y);
		plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
	}

}

void myDisplay(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (0.0, 0.0, 0.0);
	glPointSize(1.0);

	midPointCircleAlgo();

	glFlush ();
}

int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center:\n\n" << endl;

	cout << "X-coordinate   : "; cin >> pntX1;
	cout << "\nY-coordinate : "; cin >> pntY1;
	cout << "\nEnter radius : "; cin >> r;
    pntX1=pntX1+r;
    pntY1=pntY1-r;

	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Circle");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}
