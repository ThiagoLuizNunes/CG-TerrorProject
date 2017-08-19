/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "CG-Functions.h"
#include <iostream>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(400,350);
  glutInitWindowPosition(10,10);
  glutCreateWindow("My first progm with OpenGL");
  glutDisplayFunc(drawing);
  glutReshapeFunc(changeSizeWindow);
  initializes();
  glutMainLoop();

  return 0;
}
