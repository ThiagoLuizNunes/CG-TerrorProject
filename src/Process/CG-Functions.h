extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

//Callback function called to make the drawing
void drawing(void) {
  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  //Does run the OpenGL commands
  glFlush();
}

void initializes(void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
