extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

//Callback function called to make the drawing
void drawing(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  //Specifies the current color is RED
  glColor3f(1.0f, 0.0f, 0.0f);
}

void initializes(void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Callback function called when the window size is changed
void changeSizeWindow(GLsizei w, GLsizei h) {
}
