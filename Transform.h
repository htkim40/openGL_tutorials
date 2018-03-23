/*
 * Transform.h
 *
 *  Created on: Mar 22, 2018
 *      Author: master
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>


class Transform {
public:
	Transform(const glm::vec3& pos = glm::vec3(0.0f,0.0f,0.0f), const glm::vec3& rot = glm::vec3(0.0f,0.0f,0.0f),const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f));
	virtual ~Transform();

	inline glm::mat4 GetModel()const
	{
		glm::mat4 posMatrix = glm::translate(m_pos);
		glm::mat4 rotXMatrix = glm::rotate(m_rot.x, glm::vec3(1,0,0));
		glm::mat4 rotYMatrix = glm::rotate(m_rot.y, glm::vec3(0,1,0));
		glm::mat4 rotZMatrix = glm::rotate(m_rot.z, glm::vec3(0,0,1));
		glm::mat4 scaleMatrix = glm::scale(m_scale);
		//we should use quaternions to do this, but with the euler angles
		//we apply a matrix about the x, then y, then z matrix
		//recall that matrix multiplication is not communitive
		glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline glm::vec3& GetPos(){return m_pos;}
	inline glm::vec3& GetRot(){return m_rot;}
	inline glm::vec3& GetScale(){return m_scale;}

private:
	Transform(const Transform& other){};
	void operator = (const Transform& other){};

	glm::vec3 m_pos;
	glm::vec3 m_rot;
	glm::vec3 m_scale;
};

#endif /* TRANSFORM_H_ */
