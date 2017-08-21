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
