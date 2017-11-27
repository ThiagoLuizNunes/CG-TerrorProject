#include <iostream>
#include <string>
#include <vector>

#include "Objects.h"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"
#include "TextureGL.hpp"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
  #include <math.h>
}

float angle = 0.0f;              // angle of rotation for the camera direction
float lx=0.0f,lz=-1.0f, ly=0.0f; // actual vector representing the camera's direction
float x=0.0f, z=5.0f;            // XZ position of the camera
float deltaAngle = 0.0f;         // the key states. These variables will be zero
float deltaMove = 0;             // when no key is being presses
float y = 3.0f;

std::vector< std::vector<TriangleGL> > _allObjects;
std::vector<TextureGL*> _allTextures;

GLuint texture_id;
unsigned char* img;
int img_width;
int img_height;
int img_channels;

void setObject(std::vector< std::vector<TriangleGL> > objects,
	           std::vector<TextureGL*> textures) {

	_allObjects = objects;
	_allTextures = textures;

	for (int i = 0; i < objects.size(); ++i)
	{
		img = textures.at(i)->getData();
		img_width = textures.at(i)->getWidth();
		img_height = textures.at(i)->getHeight();
		img_channels = textures.at(i)->getChannels();

		glGenTextures( 1, &texture_id );
		glBindTexture( GL_TEXTURE_2D, texture_id );
		gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, img_width, img_height, GL_RGBA, GL_UNSIGNED_BYTE, img);
		textures.at(i)->setTextureID(texture_id);
	}
}
void changeSize(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0) {
		h = 1;
	}
	float ratio =  w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);                // Use the Projection Matrix
	glLoadIdentity();                           // Reset Matrix
	glViewport(0, 0, w, h);                     // Set the viewport to be the entire window
	gluPerspective(45.0f, ratio, 0.1f, 100.0f); // Set the correct perspective.
	glMatrixMode(GL_MODELVIEW);                 // Get Back to the Modelview
}
void computePos(float deltaMove) {
	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}
void computeDir(float deltaAngle) {
	angle += deltaAngle;
	lx = sin(angle);
	lz = -cos(angle);
}
void renderScene(void) {

	if (deltaMove) {
		computePos(deltaMove);
	}
	if (deltaAngle) {
		computeDir(deltaAngle);
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear Color and Depth Buffers
	glLoadIdentity();                                   // Reset transformations
	gluLookAt(	x, y , z,
				x+lx, y+ly,  z+lz,
				0.0f, 1.0f,  0.0f);                     // Set the camera

  //ILUMINAÇÃO GERAL
  glEnable(GL_COLOR_MATERIAL);
  glEnable(GL_LIGHTING);//HABILITAR LUZES
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
  glEnable(GL_LIGHT4);
  glEnable(GL_LIGHT5);
  glEnable(GL_LIGHT6);
  glEnable(GL_LIGHT7);
  glEnable(GL_NORMALIZE);
  glEnable(GL_SMOOTH);
  //glEnable(GL_FLAT);

  GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.00f};
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
  glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
  GLfloat specref[] = {1.0f, 1.0f, 1.0f, 1.00f};
  glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR,specref);
  glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);

  //atenuação da luzes
  GLfloat kc = 10;

  glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);

  // Create light components.
  //GLfloat ambientLight0[] = { 0.2f, 0.2f, 0.2f, 1.0f };
  GLfloat diffuseLight0[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight0[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position0[] = { 10.0f, 0.0f, 5.2f, 1.0f };
  GLfloat spot_direction[] = {10.0f, 0.0f, 5.2f};


  // Assign created components to GL_LIGHT0
  //glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight0);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight0);
  glLightfv(GL_LIGHT0, GL_POSITION, position0);
  glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, kc );
  glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0);

  // Create light components.
  //GLfloat ambientLight1[] = { 0.2f, 0.2f, 0.2f, 1.0f };
  GLfloat diffuseLight1[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight1[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position1[] = { 13.0f, 13.0f, 5.2f, 1.0f };
  GLfloat spot_direction1[] = {13.0f, 13.0f, 5.2f};

  // Assign created components to GL_LIGHT1.
  glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight1);
  glLightfv(GL_LIGHT1, GL_SPECULAR, specularLight1);
  glLightfv(GL_LIGHT1, GL_POSITION, position1);
  glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction1);
  glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 2.
  GLfloat ambientLight2[] = {0.2f, 0.2f, 0.2f, 1.0f };
  GLfloat diffuseLight2[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position2[] = { 18.0f, 18.0f, 5.2f, 1.0f };
  GLfloat spot_direction2[] = {18.0f, 18.0f, 1.0f};

  // Assign created components to GL_LIGHT2.
  glLightfv(GL_LIGHT2, GL_AMBIENT, ambientLight2);
  glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuseLight2);
  glLightfv(GL_LIGHT2, GL_SPECULAR, specularLight2);
  glLightfv(GL_LIGHT2, GL_POSITION, position2);
  glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction2);
  glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 3
  GLfloat diffuseLight3[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight3[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position3[] = { 22.0f, 22.0f, 5.2f, 1.0f };
  GLfloat spot_direction3[] = {22.0f, 22.0f, 5.2f};

  // Assign created components to GL_LIGHT3.
  glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuseLight3);
  glLightfv(GL_LIGHT3, GL_SPECULAR, specularLight3);
  glLightfv(GL_LIGHT3, GL_POSITION, position3);
  glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction3);
  glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 4.
  GLfloat diffuseLight4[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight4[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position4[] = { 22.0f, -22.0f, 5.2f, 1.0f };
  GLfloat spot_direction4[] = {22.0f, -22.0f, 5.2f};

  // Assign created components to GL_LIGHT4.
  glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuseLight4);
  glLightfv(GL_LIGHT4, GL_SPECULAR, specularLight4);
  glLightfv(GL_LIGHT4, GL_POSITION, position4);
  glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction4);
  glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 5.
  GLfloat diffuseLight5[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight5[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position5[] = { -10.0f, 0.0f, 5.2f, 1.0f };
  GLfloat spot_direction5[] = {-10.0f, 0.0f, 5.2f};

  // Assign created components to GL_LIGHT5.
  glLightfv(GL_LIGHT5, GL_DIFFUSE, diffuseLight5);
  glLightfv(GL_LIGHT5, GL_SPECULAR, specularLight5);
  glLightfv(GL_LIGHT5, GL_POSITION, position5);
  glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, spot_direction5);
  glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 6.
  GLfloat ambientLight6[] = { 0.2f, 0.2f, 0.2f, 1.0f };
  GLfloat diffuseLight6[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight6[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position6[] = { -13.0f, -13.0f, 5.2f, 1.0f };
  GLfloat spot_direction6[] = {-13.0f, -13.0f, 5.2f};

  // Assign created components to GL_LIGHT6.
  glLightfv(GL_LIGHT6, GL_DIFFUSE, diffuseLight6);
  glLightfv(GL_LIGHT6, GL_SPECULAR, specularLight6);
  glLightfv(GL_LIGHT6, GL_POSITION, position6);
  glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, spot_direction6);
  glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 180.0);

  /**************************/
  // Create light components 7.
  GLfloat diffuseLight7[] = { 0.8f, 0.8f, 0.8f, 1.0f };
  GLfloat specularLight7[] = { 1.0f, 1.0f, 1.0f, 1.0f };
  GLfloat position7[] = { -18.0f, -18.0f, 5.2f, 1.0f };
  GLfloat spot_direction7[] = {-18.0f, -18.0f, 5.2f};

  // Assign created components to GL_LIGHT7
  glLightfv(GL_LIGHT7, GL_DIFFUSE, diffuseLight7);
  glLightfv(GL_LIGHT7, GL_SPECULAR, specularLight7);
  glLightfv(GL_LIGHT7, GL_POSITION, position7);
  glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, kc);
  glLightf(GL_LIGHT7, GL_SPOT_EXPONENT, 10.0);
  glLightfv(GL_LIGHT7, GL_SPOT_DIRECTION, spot_direction7);
  glLightf(GL_LIGHT7, GL_SPOT_CUTOFF, 180.0);

	DrawGround(); // Draw ground

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// glColor3f(0.6f, 0.48f, 0.2f);

	glPushMatrix(); // Draw maze
		DrawObject(_allObjects.at(0), _allTextures.at(0));
	glPopMatrix();

	glPushMatrix(); // Draw floor
		DrawObject(_allObjects.at(1), _allTextures.at(1));
	glPopMatrix();

	glPushMatrix(); // Draw ceiling
		DrawObject(_allObjects.at(2), _allTextures.at(2));
	glPopMatrix();

	glPushMatrix(); // Draw doors
		DrawObject(_allObjects.at(3), _allTextures.at(3));
	glPopMatrix();

	glPushMatrix(); // Draw doors lock
		DrawObject(_allObjects.at(4), _allTextures.at(4));
	glPopMatrix();

	glPushMatrix(); // Draw desk
		// glTranslatef(19.2, 0, 17.2);
		DrawObject(_allObjects.at(5), _allTextures.at(5));
	glPopMatrix();

	glPushMatrix(); // Draw paintings
		// glTranslatef(19.2, 0, 18.85);
		DrawObject(_allObjects.at(6), _allTextures.at(6));
	glPopMatrix();

	glPushMatrix(); // Draw paintings
		DrawObject(_allObjects.at(7), _allTextures.at(7));
	glPopMatrix();

	glPushMatrix(); // Draw lamp
		// DrawObject(_allObjects.at(8), _allTextures.at(8));
	glPopMatrix();

	glPushMatrix(); // Draw 36 SnowMen
		glTranslatef(0, 0, -5);
		DrawSnowMan();
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}
void initializes (void) {
  // Define background color of the visualization window with black color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_LEFT : deltaAngle = -0.07f; break;
		case GLUT_KEY_RIGHT : deltaAngle = 0.07f; break;
		case GLUT_KEY_UP : deltaMove = 1.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -1.5f; break;
	}
}
void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT :
		case GLUT_KEY_RIGHT : deltaAngle = 0.0f;break;
		case GLUT_KEY_UP :
		case GLUT_KEY_DOWN : deltaMove = 0;break;
	}
}
void simpleKeyboard (unsigned char key, int x, int y) {
  int auxChange = glutGetModifiers();

  if (key == 27) {
    exit(0);
  }
  if ((key == 13) && GLUT_ACTIVE_ALT) {
    glutFullScreen();
  }
  if (key == 'W' || key == 'w') {
  	ly += 0.2f;
  	glutPostRedisplay();
  }
  if (key == 'S' || key == 's') {
  	ly -= 0.2f;
  	glutPostRedisplay();
  }
}
void mousePassiveMotion (int x, int y) {
  // if (x > currentPositionX) {
  //   currentPositionX += x - currentPositionX;
  //   angle += 0.01f;
  //   lx = sin(angle);
  //   // lz = -cos(angle);
  //   glutPostRedisplay();
  // }
  // if (x < currentPositionX) {
  //     currentPositionX -= currentPositionX - x;
  //     angle -= 0.01f;
  //     lx = sin(angle);
  //     // lz = -cos(angle);
  //     glutPostRedisplay();
  // }
}
