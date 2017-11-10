#include "ObjectGL.h"

ObjectGL::ObjectGL() {
}

ObjectGL::~ObjectGL() {}

/*----------  GET METHODS  ----------*/

std::vector<glm::vec3> ObjectGL::getVertices (void) {
	return this->vertices_;
}
std::vector<glm::vec3> ObjectGL::getNormals (void) {
	return this->normals_;
}

std::vector<glm::vec2> ObjectGL::getTextures (void) {
	return this->textures_;
}

std::vector< std::vector<int> > ObjectGL::getFaces (void) {
	return this->faces_;
}

/*----------  VOID METHODS  ----------*/

void ObjectGL::putVertices(glm::vec3 const& vertex) {
	this->vertices_.push_back(vertex);
}
void ObjectGL::putNormals(glm::vec3 const& normal) {
	this->normals_.push_back(normal);
}
void ObjectGL::putTextures(glm::vec2 const& texture) {
	this->textures_.push_back(texture);
}
void ObjectGL::putFaces(std::vector<int> face) {
	this->faces_.push_back(face);
}


void ObjectGL::print(void) {
	std::clog << "PRINT FUNCTION" << std::endl;
}