/*
 * Shader.h
 *
 *  Created on: Mar 21, 2018
 *      Author: master
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include "Transform.h"

class Shader
{
public:
	Shader(const std::string& filename);
	void Bind();
	void Update(const Transform& transform);
	virtual ~Shader();

private:
	static const unsigned int NUM_SHADERS=2;
	Shader(const Shader& other){};
	void operator=(const Shader& other){};

	enum
	{
		TRANSFORM_U,

		NUM_UNIFORMS
	};

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
	GLuint m_uniforms[NUM_UNIFORMS];
};

#endif /* SHADER_H_ */
