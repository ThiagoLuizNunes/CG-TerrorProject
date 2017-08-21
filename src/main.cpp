/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "CG-Functions.h"
#include <iostream>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  //Glut window width and height
  glutInitWindowSize(700,500);
  glutInitWindowPosition(10,10);
  glutCreateWindow("Hello darkness");

  //Callback functions
  //Responsible by to draw the window if necessery
  glutDisplayFunc(drawing);
  //Responsible by window resizing
  glutReshapeFunc();
  //Responsible by keyboard event
  glutKeyboardFunc();
  //Responsible by special keyboard event
  glutSpecialFunc();
  //Responsible by mouse button events
  glutMouseFunc();
  //Responsible by mouse movement event when clicked
  glutMotionFunc();
  //Responsible by mouse movement event
  glutPassiveMotionFunc();
  //Responsible when there is not events
  glutIdleFunc();

  // initializes();
  glutMainLoop();

  return 0;
}
