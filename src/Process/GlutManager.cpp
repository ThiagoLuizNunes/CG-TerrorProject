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
	setObject(allObjects, allTextures);

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
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	// Create light components.
	GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position[] = { 10.0f, 0.0f, 5.2f, 1.0f };
	//GLfloat spot_direction[] = {0.0f, 0.0f, 0.0f};


	// Assign created components to GL_LIGHT0.
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	//glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1.0);
	//glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	//glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0);

	glEnable(GL_LIGHT1);


	// Create light components.
	GLfloat ambientLight1[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat diffuseLight1[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat specularLight1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat position1[] = { 13.0f, 13.0f, 5.2f, 1.0f };
	//GLfloat spot_direction1[] = {0.0f, 0.0f, 0.0f};


	// Assign created components to GL_LIGHT0.
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
	glLightfv(GL_LIGHT1, GL_POSITION, position1);
	/*glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);*/

	glutMainLoop(); // enter GLUT event processing cycle
}
GlutManager::~GlutManager () {}
