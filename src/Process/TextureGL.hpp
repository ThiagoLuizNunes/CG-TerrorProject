#ifndef TEXTURE_GL_HPP
#define TEXTURE_GL_HPP

class TextureGL
{
private:
	int width, height;
	unsigned char* image;
public:
	TextureGL(int w, int h, unsigned char* image);
	~TextureGL();
	
	int getWitdhTexture(void);
	int getHeightTexture(void);
	unsigned char* getImage(void);
};

#endif