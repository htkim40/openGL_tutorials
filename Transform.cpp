/*
 * Transform.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: master
 */

#include "Transform.h"

Transform::Transform(const glm::vec3& pos , const glm::vec3& rot ,const glm::vec3& scale):
m_pos(pos),m_rot(rot),m_scale(scale)
{}

Transform::~Transform() {
	// TODO Auto-generated destructor stub
}

