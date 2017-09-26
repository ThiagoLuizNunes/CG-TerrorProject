#ifndef OBJECTS_H
#define OBJECTS_H

extern "C" {
  #include <GL/gl.h>
  #include <GL/glut.h>
}

void DrawTriangle (void) {
  glTranslatef(0.0f,0.0f,-4.0f);//move forward 4 units

  glColor3f(0.0f,0.0f,1.0f); //blue color

  glBegin(GL_TRIANGLES);//start drawing triangles
    glVertex3f(-1.0f,-0.25f,0.0f);//triangle one first vertex
    glVertex3f(-0.5f,-0.25f,0.0f);//triangle one second vertex
    glVertex3f(-0.75f,0.25f,0.0f);//triangle one third vertex
    //drawing a new triangle
    glVertex3f(0.5f,-0.25f,0.0f);//triangle two first vertex
    glVertex3f(1.0f,-0.25f,0.0f);//triangle two second vertex
    glVertex3f(0.75f,0.25f,0.0f);//triangle two third vertex
  glEnd();//end drawing of triangles
}
void DrawQuad (void) {
  glColor3f(1.0f, 0.0f, 0.0f);
  glTranslatef(-1.0f, 0.0f, 0.0f);
  glBegin(GL_QUADS);
    glVertex3f(0.0f,1.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    // Especifica que a cor corrente é azul
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f,0.0f, 0.0f);
    glVertex3f(1.0f,1.0f,0.0f);
  glEnd();
}

void DrawCubeFilled (void) {
  glColor3f(0.0f, 0.0f, 1.0f);

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
