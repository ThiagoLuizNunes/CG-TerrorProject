#include <iostream>
#include <string>

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

//Callback function called to make the drawing
void drawing(void) {
  std::cout << "*** DRAWING CALLBACK FUNCTION IT'S RUN" << '\n';
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);
  //Displays the drawing in the window
  glutSwapBuffers();
}

void initializes(void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Callback function called when the window size is changed
void reshapeWindow(GLsizei w, GLsizei h) {
  std::cout << "*** RESHAPE-WINDOW CALLBACK FUNCTION IT'S RUN" << '\n';
  std::cout << ">>> New window size: width - " + std::to_string(w) + " height- " + std::to_string(h) << '\n';
}

//Callback function responsible by simple keys
void simpleKeyboard (unsigned char key, int x, int y) {
  int auxChange = glutGetModifiers();
  std::cout << "*** Key handling commom" << '\n';
  std::cout << "Key: " + std::to_string(key) << '\n';

  /*Window options*/
  if(key == 27) {
    exit(0);
  }
  if(key == 'a') {
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
