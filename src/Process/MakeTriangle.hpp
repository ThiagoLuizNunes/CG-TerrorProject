#ifndef MAKE_TRIANGLE_HPP
#define MAKE_TRIANGLE_HPP

#include "FileManager.cpp"
#include "ObjectGL.h"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"
#include "TextureGL.hpp"
#include "SOIL.h" 

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>
#include <string>

class MakeTriangle
{
private:
	std::vector<TriangleGL> _triangles;
	TextureGL *_texture = nullptr;
public:
	MakeTriangle(std::string& obj_path, std::string& texture_path);
	~MakeTriangle();
	
	std::vector<TriangleGL> getTriangles(void);
	TextureGL* getTexture(void);
};

#endif