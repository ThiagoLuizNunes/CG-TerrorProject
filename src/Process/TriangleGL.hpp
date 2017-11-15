#ifndef TRIANGLE_GL_HPP
#define TRIANGLE_GL_HPP

#include "VertexGL.hpp"

class TriangleGL {

private:
	VertexGL *first_vertex_ = nullptr;
	VertexGL *second_vertex_ = nullptr;
	VertexGL *thrid_vertex_ = nullptr;
public:
	// TriangleGL(VertexGL &first, VertexGL &second, VertexGL &thrid);
	TriangleGL(VertexGL *first, VertexGL *second, VertexGL *thrid);
	~TriangleGL();
	
	VertexGL* getFirstVertex(void);
	VertexGL* getSecondVertex(void);
	VertexGL* getThirdVertex(void);
};

#endif