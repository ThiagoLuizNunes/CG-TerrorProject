#include "GlutManager.hpp"
#include "GlutFunctions.h"

GlutManager::GlutManager (int *argc, char** argv, int width, int height, const std::string& name, 
	                      std::vector< std::vector<TriangleGL> > allObjects, 
	                      std::vector<TextureGL*> allTextures) {

	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(10,10); // Specifies the initial position
	glutInitWindowSize(width,height); // Specifies the size at pixels; width and height
	glutCreateWindow(name.c_str()); // Create the window with described name

	// Set all objects
	setObject(allObjects.at(0), allTextures.at(0));

	// Callback functions
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(simpleKeyboard);
	glutSpecialFunc(pressKey);

	glutPassiveMotionFunc(mousePassiveMotion);
	initializes();
	glutIgnoreKeyRepeat(1); // here are the new entries
	glutSpecialUpFunc(releaseKey);
	glEnable(GL_DEPTH_TEST); // OpenGL init
	glutMainLoop(); // enter GLUT event processing cycle
}
GlutManager::~GlutManager () {}