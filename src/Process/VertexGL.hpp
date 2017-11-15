#ifndef VERTEX_GL_H
#define VERTEX_GL_H

#include <iostream>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class VertexGL {

private: 
	glm::vec3 axes_; // Vertex coordinates
	glm::vec3 v_normal_; // Normal vector coordinates
	glm::vec2 v_texture_; // Texture coordinates
public:
	 VertexGL(glm::vec3 const& v, glm::vec3 const& vn, glm::vec2 const& vt);
	~ VertexGL();
	
	glm::vec3 getAxes(void);
	glm::vec3 getNormal(void);
	glm::vec2 getTexture(void);
	void printAttributes(int choose);
};

#endif