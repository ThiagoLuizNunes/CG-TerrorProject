#ifndef GL_FUNCTIONS_H
#define GL_FUNCTIONS_H

#include <iostream>
#include <string>
// #include "Objects.h"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
  #include <math.h>
}

class GLFunctions {

private:
	std::string pathName;

public:
	GLFunctions(const std::string& path);
	~GLFunctions();
	
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

	void changeSize(int w, int h);
	void computePos(float deltaMove);
	void computeDir(float deltaAngle);
	void renderScene(void);
	void initializes(void);
	void pressKey(int key, int xx, int yy);
	void releaseKey(int key, int x, int y);
	void simpleKeyboard (unsigned char key, int x, int y);
	
};

#endif