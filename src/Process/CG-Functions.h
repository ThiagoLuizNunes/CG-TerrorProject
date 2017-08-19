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

  //Does drawing a filled square with the current color
  glBegin(GL_QUADS);
      glVertex2i(100, 150);
      glVertex2i(100, 100);
      //Specifies the current color is blue
      glColor3f(0.0f, 0.0f, 1.0f);
      glVertex2i(150,100);
      glVertex2i(150,150);
  glEnd();

  //Does run the OpenGL commands
  glFlush();
}

void initializes(void) {
  //Define background color of the visualization window with black color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

//Callback function called when the window size is changed
void changeSizeWindow(GLsizei w, GLsizei h) {
  //Prevents the division by zero
  if(h == 0) {
    h = 1;
  }
  //Specifies the dimensions of the Viewport
  glViewport(0, 0, w, h);
  //Initializes the coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  //Set the selection window(left, right, bottom, top)
  if(w <= h) {
    gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
  }
  else {
    gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
  }
}
