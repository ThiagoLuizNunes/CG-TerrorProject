#include "ObjectGL.h"

ObjectGL::ObjectGL (std::vector<std::string>& vertices, std::vector<std::string>& textures) {
	this->vertices_ = vertices_;
	this->textures_ = textures;
}

ObjectGL::~ObjectGL () {}

std::vector<std::string> ObjectGL::getVertices (void) {
	return this->vertices_;
}

std::vector<std::string> ObjectGL::getTextures (void) {
	return this->textures_;
}