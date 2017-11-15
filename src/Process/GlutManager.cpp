#include "GlutManager.hpp"
#include "GlutFunctions.h"

GlutManager::GlutManager (int *argc, char** argv, int width, int height, const std::string& name, 
	                      std::vector< std::vector<TriangleGL> > allObjects, 
	                      std::vector<TextureGL*> allTextures) {

	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	// Specifies the initial position
	glutInitWindowPosition(10,10);
	// Specifies the size at pixels; width and height
	glutInitWindowSize(width,height);
	// Create the window with described name
	glutCreateWindow(name.c_str());

	// Set all objects
	setObject(allObjects.at(0), allTextures.at(0));
	// std::clog << "ALL OBJECTS SIZE : " << allObjects.at(0).size() << std::endl;

	/*Callback functions*/
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutKeyboardFunc(simpleKeyboard);
	glutSpecialFunc(pressKey);

	// glutMouseFunc(clickEventMouse);
	// glutMotionFunc();
	glutPassiveMotionFunc(mousePassiveMotion);
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

}

GlutManager::~GlutManager () {
	
}