#include "VertexGL.hpp"

VertexGL::VertexGL(glm::vec3 const& v, glm::vec3 const& vn, glm::vec2 const& vt) {
	this->axes_ = v;
	this->v_normal_ = vn;
	this->v_texture_ = vt;
}
VertexGL::~VertexGL() {}

glm::vec3 VertexGL::getAxes(void) {
	return this->axes_;
}
glm::vec3 VertexGL::getNormal(void) {
	return this->v_normal_;
}
glm::vec2 VertexGL::getTexture(void) {
	return this->v_texture_;
}
void VertexGL::printAttributes(int choose) {
	if (choose == 0) {
		std::clog << "Axes: " << this->axes_.x << " " << this->axes_.y << " " << this->axes_.z << std::endl;
	}
	else if (choose == 1) {
		std::clog << "Normal vector: " << this->v_normal_.x << " " << this->v_normal_.y << " " << this->v_normal_.z << std::endl;
	}
	else {
		std::clog << "Textures: " << this->v_texture_.x << " " << this->v_texture_.y << std::endl;
	}
}