/*
 * Mesh.h
 *
 *  Created on: Mar 21, 2018
 *      Author: master
 */

#ifndef MESH_H_
#define MESH_H_

#include <glm/glm.hpp>
#include <GL/glew.h>

class Vertex
{
public:
	Vertex(const glm::vec3& pos)
	{
		this->pos = pos;
	}
protected:

private:
	glm::vec3 pos;

};


class Mesh {
public:
	Mesh(Vertex* vertices, unsigned int numVertices);

	void Draw();

	virtual ~Mesh();

private:
	Mesh(const Mesh& other);
	void operator = (const Mesh& other);

	enum
	{	POSITION_VB,
		NUM_BUFFERS
	};

	GLuint m_vertexArrayObject;
	GLuint m_vertexArrayBuffers[NUM_BUFFERS];
	unsigned int m_drawCount;
};

#endif /* MESH_H_ */
