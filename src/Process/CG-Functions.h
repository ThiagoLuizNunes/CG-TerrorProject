#include <iostream>
#include <string>
#include "Objects.h"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

//Callback function called to make the drawing
void drawing (void) {
  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective( 85.0f, 1.0f, 0.1f, 100.0f );
  //Cam position
  //Target position
  //Up position
  gluLookAt(	0.0f, 0.0f, 2.5f,
				0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f);

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
  std::cout << "*** Key handling commom" << '\n';
  std::cout << "Key: " + std::to_string(key) << '\n';

  /*Window options*/
  if(key == 27) {
    exit(0);
  }
  if((key == 13) && GLUT_ACTIVE_ALT) {
    glutFullScreen();
  }
  if(key == 'A') {
    glutReshapeWindow(700,500);
    glutPositionWindow(100,100);
  }

  /*Character options*/
  //Running fast character
  if(auxChange & GLUT_ACTIVE_SHIFT) {
    std::cout << "RUN FAST" << '\n';
  }
  //Character crouching
  if(auxChange & GLUT_ACTIVE_CTRL) {
    std::cout << "CHARACTER CROUCHING" << '\n';
  }
  //ALT key plus other key pressed
  if(auxChange & GLUT_ACTIVE_ALT) {
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

  if(state == GLUT_DOWN) {
    std::clog << "DOWN BUTTON " + std::to_string(button) + " PRESSED" << '\n';
  }
  if(state == GLUT_UP) {
    std::clog << "UP BUTTON " + std::to_string(button) + " PRESSED" << '\n';
  }
}
