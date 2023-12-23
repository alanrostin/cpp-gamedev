#pragma once
#include "Rectangle.h"
#include <SDL2/SDL.h>
#include "Window.h"

class Renderer
{
public:
	Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	bool initialize(Window& window);

    // erase the screen
	void beginDraw();
	void drawRect(Rectangle& rect);

    // swap buffers
	void endDraw();
	void close();

private:
	SDL_Renderer* SDLRenderer = nullptr;

};