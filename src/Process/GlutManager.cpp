#include "GlutManager.h"
#include "GlutFunctions.h"

GlutManager::GlutManager (int *argc, char** argv, int width, 
	int height, const std::string& name) {

	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//Specifies the initial position
	glutInitWindowPosition(10,10);
	//Specifies the size at pixels; width and height
	glutInitWindowSize(width,height);
	//Create the window with described name
	glutCreateWindow(name.c_str());

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

}

GlutManager::~GlutManager () {
	
}