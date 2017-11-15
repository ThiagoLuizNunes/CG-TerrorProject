#include <iostream>
#include <string>
#include <vector>

#include "Objects.h"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"
#include "TextureGL.hpp"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
  #include <math.h>
}

float angle = 0.0f; // angle of rotation for the camera direction
float lx=0.0f,lz=-1.0f, ly=0.0f; // actual vector representing the camera's direction
float x=0.0f, z=5.0f; // XZ position of the camera
float deltaAngle = 0.0f; // the key states. These variables will be zero 
float deltaMove = 0; // when no key is being presses
float y = 5.0f;

std::vector<TriangleGL> _cube;
TextureGL *_cubeTexture = nullptr;

void setObject(std::vector<TriangleGL> object, TextureGL *texture) {
	_cube = object;
	_cubeTexture = texture;
}
void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	
	glMatrixMode(GL_PROJECTION); // Use the Projection Matrix
	glLoadIdentity(); // Reset Matrix
	glViewport(0, 0, w, h); // Set the viewport to be the entire window
	gluPerspective(45.0f, ratio, 0.1f, 100.0f); // Set the correct perspective.
	glMatrixMode(GL_MODELVIEW); // Get Back to the Modelview
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

	if (deltaMove) {
		computePos(deltaMove);
	}
	if (deltaAngle) {
		computeDir(deltaAngle);
	}

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, y , z,
				x+lx, y+ly,  z+lz,
				0.0f, 1.0f,  0.0f);

	// Draw ground
	DrawGround();

	// Test obj
	glPushMatrix();
		glTranslatef(0, 1, 0);
		DrawObject(_cube, _cubeTexture);
		// _cube.at(0).getFirstVertex()->printAttributes(0);
	glPopMatrix();

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

	glutSwapBuffers();
}
void initializes (void) {
  // Define background color of the visualization window with black color
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
  if (key == 119 || key == 'w') {
  	ly += 0.2f;
  	glutPostRedisplay();
  }
  if (key == 115 || key == 's') {
  	ly -= 0.2f;
  	glutPostRedisplay();
  }
}
void mousePassiveMotion (int x, int y) {
  // if (x > currentPositionX) {
  //   currentPositionX += x - currentPositionX;
  //   angle += 0.01f;
  //   lx = sin(angle);
  //   // lz = -cos(angle);
  //   glutPostRedisplay();
  // }
  // if (x < currentPositionX) {
  //     currentPositionX -= currentPositionX - x;
  //     angle -= 0.01f;
  //     lx = sin(angle);
  //     // lz = -cos(angle);
  //     glutPostRedisplay();
  // }
}