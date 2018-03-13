#include <windows.h>
#include <GL/glut.h>

void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

GLfloat angle = 0.0f;

void idle() {
   glutPostRedisplay();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glPushMatrix();
   glRotatef(angle, 0.0f, 0.0f, 1.0f);
   glBegin(GL_POLYGON);
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex2d(-100, -100);
      glVertex2d( 100, -100);
      glVertex2d( 100,  100);
      glVertex2d(-100,  100);
   glEnd();
   glPopMatrix();

   glutSwapBuffers();

   angle += 1.0f;
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);          // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(500, 500);   // Set the window's initial width & height
   glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
   glutCreateWindow("Rotation");  // Create window with the given title
   gluOrtho2D(-250, 250, -250, 250);
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutIdleFunc(idle);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the event-processing loop
   return 0;
}
