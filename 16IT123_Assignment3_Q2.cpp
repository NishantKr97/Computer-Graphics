#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

int  a = 150, b = 100, x_centre = 0, y_centre = 0;

void plot(int x, int y)
{
	glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x+x_centre, y+y_centre);
	glEnd();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void idle() {
    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);




        double d2; int X = 0; int Y = b;
        double sa = a*a, sb = b*b;
        double d1 = sb - sa*b + 0.25*sa;
        plot(X,Y);
        plot(X,-Y);



        while ( sa*(Y - 0.5) > sb*(X + 1) )
        {
            if (d1 < 0)
                d1 += sb*((X << 1) + 3);

            else
            {
                d1 += sb*((X << 1) + 3) + sa*(-(Y << 1) + 2);
                Y--;
            }

            X++ ;
            plot(X,Y);
            plot(-X,Y);
            plot(X,-Y);
            plot(-X,-Y);

        }

        d2 = sb*(X + 0.5)*(X + 0.5) + sa*(Y - 1)*(Y - 1) - sa*sb;

        while ( Y > 0)
        {
            if (d2 < 0)
            {
                d2 += sb*((X << 1) + 2) + sa*(-(Y << 1) + 3);
                X++;
            }

            else
                d2 += sa*(-(Y << 1) + 3);

            Y--;
            plot(X,Y);
            plot(-X,Y);
            plot(X,-Y);
            plot(-X,-Y);

        }


    glEnd();

    glFlush();
}

void reshape(GLsizei width, GLsizei height) {
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluOrtho2D(-1*width/2, width/2, -1*height/2, height/2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Ellipse");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
    return 0;
}

