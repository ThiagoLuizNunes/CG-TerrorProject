#ifndef TEXTURE_GL_HPP
#define TEXTURE_GL_HPP

#include <iostream>
extern "C" {
	 #include <GL/gl.h>
}

class TextureGL {
	
private:
	int width, height, channels;
	unsigned char* data;
    GLint texture_id;
public:
	TextureGL(int w, int h, int channels, unsigned char* image);
	~TextureGL();
	
	int getWidth(void);
	int getHeight(void);
	int getChannels(void);
	unsigned char* getData(void);
	GLint getTextureID(void);

	void setTextureID(GLint id);
	void printAtt(void);
};

#endif