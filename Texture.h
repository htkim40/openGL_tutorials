/*
 * Texture.h
 *
 *  Created on: Mar 22, 2018
 *      Author: master
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <assert.h>

#include "stb_image.h"


class Texture
{
public:
	Texture(const std::string fileName);
	void Bind(unsigned int unit);
	virtual ~Texture();

private:
	Texture(const Texture& other){};
	void operator=(const Texture& other){};

	GLuint m_texture;
};

#endif /* TEXTURE_H_ */
