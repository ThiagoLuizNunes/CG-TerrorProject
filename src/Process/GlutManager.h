#ifndef GLUT_MANAGER_H
#define GLUT_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "TriangleGL.hpp"
#include "TextureGL.hpp"

class GlutManager {

private:
	
public:
	GlutManager(int* argc, char** argv, int width, int height, const std::string& name,
				std::vector< std::vector<TriangleGL> > allObjects, 
				std::vector<TextureGL*> allTextures);
	~GlutManager();
	
};

#endif