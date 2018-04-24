// Zadanie1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei asize = 50;
GLsizei hsize = 43;

GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

GLfloat windowWidth;
GLfloat windowHeight;


void RenderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.8f, 0.8f, 0.8f);

	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x1 + asize, y1);
	glVertex2f(x1 + asize + (asize / 2.0f), y1 + hsize);
	glVertex2f(x1 + asize, y1 + (2.0f * hsize));
	glVertex2f(x1, y1 + (2.0f * hsize));
	glVertex2f(x1 - (asize / 2.0f), y1 + hsize);

	glEnd();
	glutSwapBuffers();
}

void TimerFunction(int value) {
	if ((x1 + asize + (asize / 2)) > windowWidth || (x1 - (asize / 2)) < 0)
		xstep = -xstep;

	if (y1 + (2 * hsize) > windowHeight || y1 < 0)
		ystep = -ystep;

	x1 += xstep;
	y1 += ystep;


	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}

void SetupRC(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void ChangeSize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h)
	{
		windowHeight = 250.0f*h / w;
		windowWidth = 250.0f;
	}
	else
	{
		windowWidth = 250.0f*w / h;
		windowHeight = 250.0f;
	}

	glOrtho(0.0f, windowWidth, 0.0f, windowHeight, 1.0f, -1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("szesciokat");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(33, TimerFunction, 1);
	SetupRC();
	glutMainLoop();
	return 0;
}

