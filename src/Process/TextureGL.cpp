#include "TextureGL.hpp"

TextureGL::TextureGL(int w, int h, int ch ,unsigned char* img) {
	this->width = w;
	this->height = h;
	this->channels = ch;
	this->data = img;
}
TextureGL::~TextureGL() {}

int TextureGL::getWidth(void){
	return this->width;
}
int TextureGL::getHeight(void){
	return this->height;
}
int TextureGL::getChannels(void){
	return this->channels;
}
unsigned char* TextureGL::getData(void){
	return this->data;
}
GLint TextureGL::getTextureID(void) {
	return this->texture_id;
}
void TextureGL::setTextureID(GLint id) {
	this->texture_id = id;
}
void TextureGL::printAtt(void) {
	std::clog << "SOIL texture loading with succes!" << std::endl;
	std::clog << "    Image width........ : " << this->width << std::endl;
	std::clog << "    Image height....... : " << this->height << std::endl;
	std::clog << "    Image channels..... : " << this->channels << std::endl;
}
