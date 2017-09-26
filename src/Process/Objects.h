#ifndef OBJECTS_H
#define OBJECTS_H

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

void DrawQuad (void) {
  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_QUADS);
    glVertex2i(0,50);
    glVertex2i(0,0);
    // Especifica que a cor corrente é azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2i(50,0);
    glVertex2i(50,50);
  glEnd();
}


void DrawCube (void) {
  float size1 = 0.5f;

	glColor3f(1.0f, 1.0f, 1.0);

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
