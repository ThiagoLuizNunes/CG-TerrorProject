extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

//Size and initial position of square
GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50;

// Increase size in the directions x and y
// (pixels number to move for each
// time interval)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

//Window's width and height
GLfloat windowWidth;
GLfloat windowHeight;

//Callback function called to make the drawing
void drawing(void) {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  //Does clean the visualization window with a background color specified
  glClear(GL_COLOR_BUFFER_BIT);

  //Specifies the current color is RED
  glColor3f(1.0f, 0.0f, 0.0f);
  // glTranslatef(-100.0f, -30.0f, 0.0f);
  // glScalef(1.5f, 0.5f, 1.0f);

  //Does drawing a filled square with the current color
  glBegin(GL_QUADS);
               glVertex2i(x1,y1+rsize);
               glVertex2i(x1,y1);
               //Specifies the current color is blue
               glColor3f(0.0f, 0.0f, 1.0f);
               //Widht and height
               glVertex2i(x1+rsize,y1);
               glVertex2i(x1+rsize,y1+rsize);
   glEnd();

  //Does run the OpenGL commands
  glutSwapBuffers();
}

void Timer(int value) {
  //Changes direction when it arrive the left or right edge
  if(x1 > windowWidth-rsize || x1 < 0) {
    xstep = -xstep;
  }

  //Changes direction when it arrive the top or bottom edge
  if(y1 > windowHeight-rsize || y1 < 0) {
    ystep = -ystep;
  }
  //Verify the edges. If the window is smaller and the
  //square get out of the visualization volume
  if(x1 > windowWidth-rsize) {
    x1 = windowWidth-rsize-1;
  }

  if(y1 > windowHeight-rsize) {
    y1 = windowHeight-rsize-1;
  }
  //Move the square
  x1 += xstep;
  y1 += ystep;

  //Redesign the square with the news coordinates
  glutPostRedisplay();
  glutTimerFunc(33,Timer, 1);
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
    // gluOrtho2D (0.0f, 250.0f, 0.0f, 250.0f*h/w);
    windowHeight = 250.0f*h/w;
		windowWidth = 250.0f;
  }
  else {
    // gluOrtho2D (0.0f, 250.0f*w/h, 0.0f, 250.0f);
    windowWidth = 250.0f*w/h;
		windowHeight = 250.0f;
  }
  gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
