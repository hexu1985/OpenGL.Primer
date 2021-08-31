/* draws the wire frame glut cube */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>         /* glut.h includes gl.h and glu.h */
#endif

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutWireCube(0.5);
	glutSwapBuffers();

}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
}

void init()
{
 	glClearColor (1.0, 1.0, 1.0, 1.0); 
 	glColor3f(0.0, 0.0, 0.0); 
}

int main(int argc, char** argv)
{
 	glutInit(&argc,argv); 
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);  
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0); 
	glutCreateWindow("cube"); 
    glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
