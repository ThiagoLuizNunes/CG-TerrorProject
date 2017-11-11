#include <iostream>
#include <string>
#include "Objects.h"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
  #include <math.h>
}

// angle of rotation for the camera direction
float angle = 0.0f;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f, z=5.0f;
// the key states. These variables will be zero
//when no key is being presses
float deltaAngle = 0.0f;
float deltaMove = 0;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void renderScene(void) {

	if (deltaMove)
		computePos(deltaMove);
	if (deltaAngle)
		computeDir(deltaAngle);

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
				x+lx, 1.0f,  z+lz,
				0.0f, 1.0f,  0.0f);

	// Draw ground
	DrawGround();
	glPushMatrix();
		glTranslatef(-5, 1.5, -5);
		DrawTriangle();
		glPopMatrix();


	glPushMatrix();
		glTranslatef(5, 1, -5);
		DrawCube();
		glPopMatrix();

  	// Draw 36 SnowMen
  	glPushMatrix();
		glTranslatef(0, 0, -5);
		DrawSnowMan();
		glPopMatrix();

	// for(int i = -3; i < 3; i++)
	// 	for(int j=-3; j < 3; j++) {
	// 		glPushMatrix();
	// 		glTranslatef(i*10.0,0,j * 10.0);
	// 		DrawSnowMan();
	// 		glPopMatrix();
	// 	}

	glutSwapBuffers();
}
void initializes (void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.07f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.07f; break;
		case GLUT_KEY_UP : deltaMove = 1.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -1.5f; break;
	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}
void simpleKeyboard (unsigned char key, int x, int y) {
  int auxChange = glutGetModifiers();

  if (key == 27) {
    exit(0);
  }
  if ((key == 13) && GLUT_ACTIVE_ALT) {
    glutFullScreen();
  }
}
