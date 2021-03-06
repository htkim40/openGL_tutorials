/*
 * Shader.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: master
 */

#include "Shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
static std::string LoadShader(const std::string& filename);
static GLuint CreateShader(const std::string& text, GLenum shaderType);


Shader::Shader(const std::string& filename)
{
	m_program = glCreateProgram();
	m_shaders[0] =CreateShader(LoadShader(filename+".vs"), GL_VERTEX_SHADER);
	m_shaders[1] =CreateShader(LoadShader(filename+".fs"), GL_FRAGMENT_SHADER);

	for(unsigned int i = 0; i <NUM_SHADERS; i++)
	{
		glAttachShader(m_program, m_shaders[i]);
//		std::cout<<"shader "<<i<<" has been attached"<<std::endl;
	}

	glBindAttribLocation(m_program,0,"position");
//	glBindAttribLocation(m_program,1,"texCoord");


	glLinkProgram(m_program);
	CheckShaderError(m_program,GL_LINK_STATUS,true,"Error: Program linking failed: ");

	glValidateProgram(m_program);
	CheckShaderError(m_program,GL_VALIDATE_STATUS,true,"Error: Program is invalid: ");

	m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
}

Shader::~Shader() {
	for(unsigned int i = 0; i <NUM_SHADERS; i++)
	{
		glDetachShader(m_program,m_shaders[i]);
		glDeleteShader(m_shaders[i]);
//		std::cout<<"shader "<<i<<" has been dettached and deleted"<<std::endl;
	}
	glDeleteProgram(m_program);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	if(shader == 0)
		std::cerr<<"Error: shader creation failed"<<std::endl;
	const GLchar* shaderSourceStrings[1];
	GLint shaderSourceStringsLengths[1];
	shaderSourceStrings[0] = text.c_str();
	shaderSourceStringsLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringsLengths);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader Compilation Failed");

	return shader;
}

void Shader::Bind(){
	glUseProgram(m_program);
}

void Shader::Update(const Transform& transform){
	glm::mat4 model = transform.GetModel();
	glUniformMatrix4fv(m_uniforms[TRANSFORM_U],1,GL_FALSE, &model[0][0]);
}


static std::string LoadShader(const std::string& fileName)
{
    std::ifstream file;
    file.open((fileName).c_str());

    std::string output;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		std::cerr << "Unable to load shader: " << fileName << std::endl;
    }

    return output;
}
static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}
