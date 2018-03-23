/*
 * Texture.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: master
 */

#include "Texture.h"

Texture::Texture(const std::string fileName){
	int width, height, numComponents;//non texture information

	unsigned char* imageData = stbi_load(fileName.c_str(), &width, &height, &numComponents, 4);

	if(imageData == NULL)
		std::cerr<<"Texture loading failed for texture: "<<fileName<<std::endl;

	glGenTextures(1,&m_texture);
	glBindTexture(GL_TEXTURE_2D,m_texture);

	//will read the texture pixels and wrap after exceeding width and height, or you can use GL_CLAMP
	//which will return black
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	//this essentially interpolates if you are doing minification or magnification, kind of like a
	//filter for rendering
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

	stbi_image_free(imageData);
}

Texture::~Texture() {
	glDeleteTextures(1,&m_texture);
}

void Texture::Bind(unsigned int unit){
	assert(unit>=0 && unit <=31);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}
