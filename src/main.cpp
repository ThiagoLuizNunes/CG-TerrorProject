/*
Author: Thiago Luiz Nunes
Project: CG-TerrorProject
*/
#include "GL-Functions.h"
#include "Objects.h"
#include "FileManager.cpp"

#include <iostream>
#include <string>

const static std::string path;


int main(int argc, char *argv[]) {

  // std::string mypath = argv[1];
  std::string mypath = "./objects/teste.txt";

  FileManager* file_manager = nullptr;
 
    try {
        file_manager = new FileManager(mypath); 
    } catch (FileManagerException& exc) {
        std::cerr << "FileManagerException - what(): " << exc.what() << std::endl;
    }
 
    if (file_manager != nullptr) {
        std::clog << "First line: " << file_manager->getNextLine() << std::endl;
        std::clog << "Second line: " << file_manager->getNextLine() << std::endl;
 
        delete file_manager;
    }

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  //Specifies the initial position
  glutInitWindowPosition(10,10);
  //Specifies the size at pixels; width and height
  glutInitWindowSize(1024,720);
  //Create the window with described name
  glutCreateWindow("Hello darkness");

  /*Callback functions*/
  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutIdleFunc(renderScene);

  glutKeyboardFunc(simpleKeyboard);
  glutSpecialFunc(pressKey);
  
  // glutMouseFunc(clickEventMouse);
  // glutMotionFunc();
  // glutPassiveMotionFunc(mousePassiveMotion);
  // glutEntryFunc(mouseEntry);
  // glutIdleFunc();

  initializes();

  // here are the new entries
	glutIgnoreKeyRepeat(1);
	glutSpecialUpFunc(releaseKey);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

  return 0;
}
