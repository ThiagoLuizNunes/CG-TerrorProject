#include "FileManager.cpp"
#include "ObjectGL.hpp"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"
#include "TextureGL.hpp"
#include "SOIL.h"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

class MakeTriangle {
	
private:
	std::vector<TriangleGL> _triangles;
	TextureGL *_texture = nullptr;
public:
	MakeTriangle(std::string& mypath, std::string& texture_path);
	~MakeTriangle();
	
	std::vector<TriangleGL> getTriangles(void);
	TextureGL* getTexture(void);
};