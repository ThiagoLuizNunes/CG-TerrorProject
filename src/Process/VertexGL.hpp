#ifndef VERTEX_GL_H
#define VERTEX_GL_H

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class VertexGL {

private: 
	/* Vertex coordinates */
	glm::vec3 const& axes_;
	// const float axis_x_;
	// const float axis_y_;
	// const float axis_z_;

	/* Normal vector coordinates*/
	glm::vec3 const& v_normal_;
	// const float vn_x_;
	// const float vn_y_;
	// const float vn_z_;

	/* Texture coordinates */
	glm::vec2 const& v_texture_;
	// const float vt_1_;
	// const float vt_2_;


public:
	 VertexGL();
	~ VertexGL();
	
};

#endif