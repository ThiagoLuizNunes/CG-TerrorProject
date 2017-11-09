#ifndef TRIANGLE_GL_H
#define TRIANGLE_GL_H

#include "VertexGL.hpp"

class TriangleGL {

private:
	VertexGL first_vertex_;
	VertexGL second_vertex_;
	VertexGL thrid_vertex_;

public:
	TriangleGL();
	~TriangleGL();
	
};

#endif