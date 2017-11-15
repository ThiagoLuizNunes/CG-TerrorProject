#include "FileManager.cpp"
#include "ObjectGL.h"
#include "VertexGL.hpp"
#include "TriangleGL.hpp"

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>

#include <vector>

class MakeTriangle
{
private:
	std::vector<TriangleGL> _triangles;
public:
	MakeTriangle(std::string& mypath);
	~MakeTriangle();
	
	std::vector<TriangleGL> getTriangles(void);
};