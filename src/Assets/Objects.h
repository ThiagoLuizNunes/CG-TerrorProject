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

	glEnable( GL_TEXTURE_2D );
	glBindTexture( GL_TEXTURE_2D, texture->getTextureID() );

	for (int i = 0; i < count; i++) {
		glBegin(GL_TRIANGLES);

			glm::vec3 first = obj.at(i).getFirstVertex()->getAxes();
			glm::vec3 second = obj.at(i).getSecondVertex()->getAxes();
			glm::vec3 third = obj.at(i).getThirdVertex()->getAxes();

			glm::vec2 first_vt = obj.at(i).getFirstVertex()->getTexture();
			glm::vec2 second_vt = obj.at(i).getSecondVertex()->getTexture();
			glm::vec2 third_vt = obj.at(i).getThirdVertex()->getTexture();

		    glTexCoord2f(first_vt.x, first_vt.y); 
		    glVertex3f(first.x, first.y, first.z);

		    glTexCoord2f(second_vt.x, second_vt.y); 
		    glVertex3f(second.x, second.y, second.z);

		    glTexCoord2f(third_vt.x, third_vt.y); 
		    glVertex3f(third.x, third.y, third.z);
	  	glEnd();
	}
	glEnable(GL_TEXTURE_2D);
}
void DrawGround () {
  glColor3f(0.5f, 0.5f, 0.5f);
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
