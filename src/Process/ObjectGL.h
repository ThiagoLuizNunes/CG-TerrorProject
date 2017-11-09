#ifndef OBJECT_GL_H
#define OBJECT_GL_H

#include <iostream>
#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

class ObjectGL {

private:
	std::vector<glm::vec3> vertices_; /* v */
	std::vector<glm::vec2> textures_; /* vt */
	std::vector<glm::vec3> normals_; /* vn */
	std::vector<glm::vec3> triangles_; /* vn */

public:
	ObjectGL ();
	~ObjectGL ();

	std::vector<glm::vec3> getVertices(void);
	std::vector<glm::vec2> getTextures(void);
	std::vector<glm::vec3> getNormals(void);
};

#endif