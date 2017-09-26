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
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;

int currentPositionX = 512;

void drawing (void) {
  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective( 85.0f, 1.0f, 0.1f, 100.0f );
  //Cam position
  //Target position
  //Up position
  // gluLookAt(	axisCamX+auxCamX, axisCamY+auxCamY, axisCamZ+auxCamZ,
		// 		0.0f, 0.0f, 0.0f,
		// 		0.0f, 1.0f, 0.0f);
  gluLookAt(  x, 0.0f, z,
        x+lx, 0.0f,  z+lz,
        0.0f, 1.0f,  0.0f);

  glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
  // DrawTriangle();
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
  /**
   *
   * Motion keys
   *
   */
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
    // angle += 0.03f;
    // lx = sin(angle);
    // lz = -cos(angle);
    // glutPostRedisplay();
  }
  if (key == 'a') {
    // auxCamX -= 0.1f;
    // angle -= 0.03f;
    // lx = sin(angle);
    // lz = -cos(angle);
    // glutPostRedisplay();
  }
  /**
   *
   * Window options
   *
   */
  
  if (key == 27) {
    exit(0);
  }
  if ((key == 13) && GLUT_ACTIVE_ALT) {
    glutFullScreen();
  }
  // if (key == 'A') {
  //   glutReshapeWindow(700,500);
  //   glutPositionWindow(100,100);
  // }

  /**
   *
   * Character options
   *
   */
  
  //Running fast character
  if (auxChange & GLUT_ACTIVE_SHIFT) {
    std::cout << "RUN FAST" << '\n';
  }
  //Character crouching
  if (auxChange & GLUT_ACTIVE_CTRL) {
    std::cout << "CHARACTER CROUCHING" << '\n';
  }
  //ALT key plus other key pressed
  if (auxChange & GLUT_ACTIVE_ALT) {
    std::cout << "ALT IS PRESSED" << '\n';
  }
}

//Callback function responsible by special keys
void specialKeyboad (int key, int x, int y) {
  std::cout << "*** Key handling special" << '\n';

  switch (key) {
    case GLUT_KEY_F1:
      std::cout << "*** Key F1 pressed" << '\n';
      break;
    case GLUT_KEY_F2:
      std::cout << "*** Key F2 pressed" << '\n';
      break;
    case GLUT_KEY_F3:
      std::cout << "*** Key F3 pressed" << '\n';
      break;
  }
}

//Callback function responsible by mouse click
void clickEventMouse (int button, int state, int x, int y) {
  std::clog << "*** MOUSE CLICK EVENT" << '\n';

  if(state == GLUT_UP) {
    std::clog << "UP BUTTON " + std::to_string(button) + " PRESSED" << '\n';
    std::clog << "x: " << x << " Y: " << y << '\n';

  }
  if(state == GLUT_DOWN) {
    std::clog << "DOWN BUTTON " + std::to_string(button) + " PRESSED" << '\n';
  }

}

void mousePassiveMotion (int x, int y) {
  if (x > currentPositionX) {
    currentPositionX += x - currentPositionX;
    angle += 0.01f;
    lx = sin(angle);
    lz = -cos(angle);
    glutPostRedisplay();
  } else {
      currentPositionX -= currentPositionX - x;
      angle -= 0.01f;
      lx = sin(angle);
      lz = -cos(angle);
      glutPostRedisplay();
  }
}

void mouseEntry (int state) {
  if (state == GLUT_LEFT) {
    angle == 0.0;
  } else {
    angle == 1.0;
  }
  glutPostRedisplay();
}
