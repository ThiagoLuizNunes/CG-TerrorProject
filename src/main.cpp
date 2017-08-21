/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "CG-Functions.h"
#include <iostream>

int main(int argc, char *argv[]) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
  //Specifies the initial position
  glutInitWindowPosition(10,10);
  //Specifies the size at pixels; width and height
  glutInitWindowSize(700,500);
  //Create the window with described name
  glutCreateWindow("Hello darkness");

  /*Callback functions*/
  //Responsible by to draw the window if necessery
  glutDisplayFunc(drawing);
  // //Responsible by window resizing
  // glutReshapeFunc();
  // //Responsible by keyboard event
  // glutKeyboardFunc();
  // //Responsible by special keyboard event
  // glutSpecialFunc();
  // //Responsible by mouse button events
  // glutMouseFunc();
  // //Responsible by mouse movement event when clicked
  // glutMotionFunc();
  // //Responsible by mouse movement event
  // glutPassiveMotionFunc();
  // //Responsible when there is not events
  // glutIdleFunc();

  // initializes();
  //From the moment this function is called, the program
  //control is transferred to GLUT, beginning the management events.
  glutMainLoop();

  return 0;
}
