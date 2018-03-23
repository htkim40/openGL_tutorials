/*
 * main.cpp
 *
 *  Created on: Mar 21, 2018
 *      Author: master
 */




#include <iostream>
#include <GL/glew.h>
#include "Display.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"



int main(void)
{
	Display display(800,600, "HelloWorld");
	Shader shader("./res/basicShader");
	Vertex vertices[] = {	Vertex(glm::vec3(-0.5, -0.5, 0), 	glm::vec2(0.0, 0.0)),
							Vertex(glm::vec3(0, 0.5, 0),		glm::vec2(0.5, 1.0)),
							Vertex(glm::vec3(0.5, -0.5, 0),		glm::vec2(1.0, 0.0)),	};
	Mesh mesh(vertices, sizeof(vertices)/sizeof(vertices[0]));
	Texture texture("./res/bricks.jpg");
	Transform transform;

	float counter = 0.01f;
	while(!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.3f, 1.0f);
		float sincounter = sinf(counter);
		float coscounter = cosf(counter);

		transform.GetPos().x = sinf(counter);
		transform.GetRot().z = counter;
		transform.GetRot().x = 5*counter;
		transform.GetScale() =glm::vec3(sincounter, sincounter, coscounter);

		shader.Bind();
		texture.Bind(0);

		mesh.Draw();
		shader.Update(transform);
		display.Update();
		counter+= 0.01f;
	}

	return 0;
}
