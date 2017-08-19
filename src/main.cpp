#include "CG-Functions.h"
#include <iostream>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutCreateWindow("My first progm with OpenGL");
  glutDisplayFunc(drawing);
  glutMainLoop();

  return 0;
}
