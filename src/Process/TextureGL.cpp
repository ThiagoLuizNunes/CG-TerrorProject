#include "TextureGL.hpp"

TextureGL::TextureGL(int w, int h, unsigned char* img) {
	this->width = w;
	this->height = h;
	this->image = img;
}
TextureGL::~TextureGL() {}

int TextureGL::getWitdhTexture(void){
	return this->width;
}
int TextureGL::getHeightTexture(void){
	return this->height;
}
unsigned char* TextureGL::getImage(void){
	return this->image;
}