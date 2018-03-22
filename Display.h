/*
 * Display.h
 *
 *  Created on: Mar 21, 2018
 *      Author: master
 */

#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/glew.h>

class Display {
public:
	Display(int width, int height, const std::string& title);
	virtual ~Display();
	void Update();
	void Clear(float r, float g, float b, float a);
	bool IsClosed();


private:
	Display(const Display& other){};
	void operator=(const Display& other){};

	SDL_Window* m_window;
	SDL_GLContext m_glContext;
	bool m_isClosed;

};

#endif /* DISPLAY_H_ */
