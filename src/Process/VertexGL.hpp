#ifndef VERTEX_GL_H
#define VERTEX_GL_H

class VertexGL {

private: 
	/* Vertex coordinates */
	const float axis_x_;
	const float axis_y_;
	const float axis_z_;

	/* Normal vector coordinates*/
	const float vn_x_;
	const float vn_y_;
	const float vn_z_;

	/* Texture coordinates */
	
	const float vt_1_;
	const float vt_2_;


public:
	 VertexGL();
	~ VertexGL();
	
};

#endif