#include <iostream>
#include <string>
#include "Objects.h"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
  #include <math.h>
}

//Callback function called to make the drawing
float auxCamX = 0.0f;
float auxCamY = 0.0f;
float auxCamZ = 0.0f;

float axisCamX = 0.0f;
float axisCamY = 0.0f;
float axisCamZ = 2.5f;

// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, y = 0.0f, z = 5.0f;

int currentPositionX = 512;
int currentPositionY = 360;

void drawing (void) {
  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective( 85.0f, 1.0f, 0.1f, 100.0f );

  gluLookAt(  x, y, z,
        x+lx, y+ly,  z+lz,
        0.0f, 1.0f,  0.0f);

  glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

  DrawCube();
  DrawQuad();

  // Executa os comandos OpenGL
  glFlush();

  // glutSwapBuffers();
}

void initializes (void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Callback function called when the window size is changed
void reshapeWindow (GLsizei w, GLsizei h) {
  GLsizei width, height;
  //Prevent division by zero
  if(h == 0) h = 1;

  width = w;
  height = h;

  //Viewport dimensions
  glViewport(0, 0, width, height);

  //Start coordinates system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Estabelece a janela de seleção (left, right, bottom, top)
  if (width <= height)
  gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*height/width);
  else
  gluOrtho2D (0.0f, 250.0f*width/height, 0.0f, 250.0f);
}

// Callback function responsible by simple keys
void simpleKeyboard (unsigned char key, int x, int y) {
  int auxChange = glutGetModifiers();

  float fraction = 0.03f;
  if (key == 'w') {
    // auxCamZ -= 0.1f;
    x += lx * fraction;
    z += lz * fraction;
    glutPostRedisplay();
  }
  if (key == 's') {
    // auxCamZ += 0.1f;
    x -= lx * fraction;
		z -= lz * fraction;
    glutPostRedisplay();
  }
  if (key == 'd') {
    // auxCamX += 0.1f;
    angle += 0.05f;
    lx = sin(angle);
    lz = -cos(angle);
    glutPostRedisplay();
  }
  if (key == 'a') {
    // auxCamX -= 0.1f;
    angle -= 0.05f;
    lx = sin(angle);
    lz = -cos(angle);
    glutPostRedisplay();
  }
  if (key == 27) {
    exit(0);
  }
  if ((key == 13) && GLUT_ACTIVE_ALT) {
    glutFullScreen();
  }
}

















//Callback function responsible by special keys
void specialKeyboad (int key, int x, int y) {
  switch (key) {
  }
}

//Callback function responsible by mouse click
void clickEventMouse (int button, int state, int x, int y) {
  if(state == GLUT_UP) {
  }
  if(state == GLUT_DOWN) {
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

void mouseEntry (int state) {
  if (state == GLUT_LEFT) {
    angle == 0.0;
  } else {
    angle == 1.0;
  }
  glutPostRedisplay();
}
