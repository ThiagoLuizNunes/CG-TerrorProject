#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
#include <iostream>
#include <string>
#include <vector>

#include "TriangleGL.hpp"
#include "VertexGL.hpp"
#include "TextureGL.hpp"

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

void DrawObject (std::vector<TriangleGL> obj, TextureGL *texture) {
	int count  = obj.size();

	GLuint texture_id;

	glColor3f(0.0f,0.0f,1.0f);

	// glGenTextures( 1, &texture_id ); // Generate identifier to texture
	// glBindTexture( GL_TEXTURE_2D, texture_id ); // Define current texture
	// gluBuild2DMipmaps( GL_TEXTURE_2D, GL_RGB, texture->getWidth(), texture->getHeight(), GL_RGBA, GL_UNSIGNED_BYTE, texture->getData());
	
	// glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	// glLightModelf(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SEPARATE_SPECULAR_COLOR);

	// glDisable(GL_TEXTURE_2D);

	for (int i = 0; i < count; i++) {
		glBegin(GL_LINES);

			glm::vec3 first = obj.at(i).getFirstVertex()->getAxes();
			glm::vec3 second = obj.at(i).getSecondVertex()->getAxes();
			glm::vec3 third = obj.at(i).getThirdVertex()->getAxes();

			glm::vec2 first_vt = obj.at(i).getFirstVertex()->getTexture();
			glm::vec2 second_vt = obj.at(i).getSecondVertex()->getTexture();
			glm::vec2 third_vt = obj.at(i).getThirdVertex()->getTexture();

		    // glTexCoord2f(first_vt.x, first_vt.y); 
		    // glTexCoord2f(0.0,0.0);
		    glVertex3f(first.x, first.y, first.z);

		    // glTexCoord2f(second_vt.x, second_vt.y); 
		    // glTexCoord2f(1.0,0.0);
		    glVertex3f(second.x, second.y, second.z);

		    // glTexCoord2f(third_vt.x, third_vt.y); 
		    // glTexCoord2f(1.0,1.0);
		    glVertex3f(third.x, third.y, third.z);
	  	glEnd();
	}
	glEnable(GL_TEXTURE_2D);
}
void DrawGround () {
  glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();
}
void DrawSnowMan () {
	glColor3f(1.0f, 1.0f, 1.0f);

  // Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

  // Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

  // Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

  // Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}
void DrawQuad (void) {
	GLubyte txt[] = { 0, 0, 0, 0, 64, 64, 64, 64, 128, 128, 128, 128, 192, 192, 192, 192 };
	GLuint txt_id;

	glGenTextures(1, &txt_id); // Generate identifier to texture
	glBindTexture(GL_TEXTURE_1D, txt_id); // Define current texture
	glTexImage1D(GL_TEXTURE_1D, 0, GL_LUMINANCE, 16, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, txt); // Send texture to OpenGL
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glEnable(GL_TEXTURE_1D); // Active texture
	glBegin(GL_QUADS);
		glTexCoord1f(0); glVertex3f(0.0f,1.0f,0.0f);
		glTexCoord1f(1.0); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord1f(1.0); glVertex3f(1.0f,0.0f, 0.0f);
		glTexCoord1f(0); glVertex3f(1.0f,1.0f,0.0f);
	glEnd();
	glDisable(GL_TEXTURE_1D);
}













void DrawCube (void) {
  float size1 = 0.5f;

	glColor3f(0.0f, 1.0f, 0.0);

	glBegin(GL_LINES);
		// bottom
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);

		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1, size1);

		glVertex3f( size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);

		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);

		// top
		glVertex3f(-size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1,-size1);

		// left
		glVertex3f(-size1,-size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1, size1);
		glVertex3f(-size1,-size1,-size1);

		// right
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1,-size1);

		// front
		glVertex3f(-size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1,-size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f( size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1, size1, size1);
		glVertex3f(-size1,-size1, size1);

		// back
		glVertex3f(-size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1,-size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f( size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1, size1,-size1);
		glVertex3f(-size1,-size1,-size1);
	glEnd();
}

#endif
