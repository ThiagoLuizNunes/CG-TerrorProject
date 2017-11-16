#ifndef TEXTURE_GL_HPP
#define TEXTURE_GL_HPP

#include <iostream>

class TextureGL {
	
private:
	int width, height, channels;
	unsigned char* data;
public:
	TextureGL(int w, int h, int channels, unsigned char* image);
	~TextureGL();
	
	int getWidth(void);
	int getHeight(void);
	int getChannels(void);
	unsigned char* getData(void);
	void printAtt(void);
};

#endif