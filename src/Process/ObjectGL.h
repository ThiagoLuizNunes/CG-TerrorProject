#ifdef OBJECT_CLASS_H
#define OBJECT_CLASS_H

#include <iostream>
#include <string>
#include <vector>

class ObjectGL {

private:
	std::vector<std::string> vertices_;
	std::vector<std::string> textures_;

public:
	ObjectGL(std::vector<std::string>& vertices, std::vector<std::string>& textures);
	~ObjectGL();

	std::vector<std::string> getVertices(void);
	std::vector<std::string> getTextures(void);
};

#endif