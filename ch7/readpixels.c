
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUt/glut.h>
#else
#include <GL/glut.h>
#endif

int n=300;
int m=300;



void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(255, 255, 127);
    glRecti(0,0,n,m);
	glutSwapBuffers(); 
}


void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLfloat) w, 0.0, (GLfloat) h);
    glMatrixMode(GL_MODELVIEW);
	n=w;
	m=h;
	printf("n= %d m= %d\n", n, m);
}

void mouse(int state, int button, int x, int y)
{
	int i,j;
	GLubyte pixels[3];
	glutPostRedisplay();
	glReadPixels(x,m-y,1,1,GL_RGB,GL_UNSIGNED_BYTE, pixels);
	for(i=0;i<2;i++) for(j=0;j<2;j++)
	{
		printf("%d %d %d\n", pixels[0], pixels[1], pixels[2]);
	}
}

void myinit()
{
    int j;
    glClearColor (0.0, 0.5, 1.0, 1.0);
    gluOrtho2D(0.0, 0.0, (GLfloat) n, (GLfloat) m);
	glReadBuffer(GL_BACK); 
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glDisable(GL_DITHER);
	glGetIntegerv(GL_RED_BITS,&j);
	printf("red bits %d \n",j);

}

main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(300, 300);
    glutCreateWindow("image");
    myinit();
    glutReshapeFunc(myReshape);
	glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();


}
