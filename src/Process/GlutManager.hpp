#ifndef GLUT_MANAGER_HPP
#define GLUT_MANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "TriangleGL.hpp"
#include "TextureGL.hpp"

class GlutManager {

public:
	GlutManager(int* argc, char** argv, int width, int height, const std::string& name,
				std::vector< std::vector<TriangleGL> > allObjects, 
				std::vector<TextureGL*> allTextures);
	~GlutManager();
	
};

#endif