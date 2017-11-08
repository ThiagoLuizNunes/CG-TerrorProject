#ifndef GLUT_MANAGER_H
#define GLUT_MANAGER_H

#include <iostream>
#include <string>

class GlutManager {

private:
	
public:
	GlutManager(int* argc, char** argv, int width, int height, const std::string& name);
	~GlutManager();
	
};

#endif