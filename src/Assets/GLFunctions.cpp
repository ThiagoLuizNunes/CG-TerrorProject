#include "GLFunctions.h"

GLFunctions::GLFunctions(const std::string& path) {
	this->pathName = path;
}

GLFunctions::~GLFunctions() {}

void GLFunctions::changeSize(int w, int h) {
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

void GLFunctions::computePos(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void GLFunctions::computeDir(float deltaAngle) {

	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}

void GLFunctions::renderScene(void) {

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
	//DrawGround();
	// Draw .ojb test

  	// Draw 36 SnowMen
	// for(int i = -3; i < 3; i++)
	// 	for(int j=-3; j < 3; j++) {
	// 		glPushMatrix();
	// 		glTranslatef(i*10.0,0,j * 10.0);
	// 		DrawSnowMan();
	// 		glPopMatrix();
	// 	}

	glutSwapBuffers();
}

void GLFunctions::initializes(void) {
  
	//Define background color of the visualization window with black color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void GLFunctions::pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.01f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.01f; break;
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
	}
}

void GLFunctions::releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}

void GLFunctions::simpleKeyboard (unsigned char key, int x, int y) {
	
	int auxChange = glutGetModifiers();
	if (key == 27) {
		exit(0);
	}
	if ((key == 13) && GLUT_ACTIVE_ALT) {
		glutFullScreen();
	}
}