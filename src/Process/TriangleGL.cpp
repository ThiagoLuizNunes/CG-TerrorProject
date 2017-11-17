#include "TriangleGL.hpp"

// TriangleGL::TriangleGL(VertexGL &first, VertexGL &second, VertexGL &thrid) {
TriangleGL::TriangleGL(VertexGL *first, VertexGL *second, VertexGL *thrid) {
	this->first_vertex_ = new VertexGL(first->getAxes(), first->getNormal(), first->getTexture());
	this->second_vertex_ = new VertexGL(second->getAxes(), second->getNormal(), second->getTexture());
	this->thrid_vertex_ = new VertexGL(thrid->getAxes(), thrid->getNormal(), thrid->getTexture());
}
TriangleGL::~TriangleGL() {}

VertexGL* TriangleGL::getFirstVertex(void) {
	return this->first_vertex_;
}
VertexGL* TriangleGL::getSecondVertex(void) {
	return this->second_vertex_;
}
VertexGL* TriangleGL::getThirdVertex(void) {
	return this->thrid_vertex_;
}