#ifdef GLUT_MANAGER_H
#define GLUT_MANAGER_H

#include <iostream>
#include <string>

class GlutManager {

private:
	const ind width_, height_;
	const std::string window_name_;
public:
	GlutManager(const int argc, const std::string& argv, const int width, const int height, 
		const std::string& name) : width_(width), height_(height), window_name_(name);
	~GlutManager();
	
};

#endif