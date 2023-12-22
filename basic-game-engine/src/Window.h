#pragma once

#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 1024;
const int WINDOW_HEIGHT = 768;

class Window
{
public:
	Window();

    // always delete copy constructor and assignment operator if you don't need them.
    // c++ may use them even if you think you didn't ask for
	Window(const Window&) = delete;
    
    // the assignment operator for the Window class is not allowed 
    // and attempting to use it will result in a compilation error.
    // when the assignment operator is deleted, any attempt to assign one Window object 
    // to another will result in a compile-time error,
    // preventing unintended or unsafe operations like shallow copying of objects.
	Window& operator=(const Window&) = delete;

	bool initialize();
	void close();

    // const correctness: getters do not modify the object
	SDL_Window* getSDLWindow() const { return SDLWindow; }
	int getWidth() const { return width; }
	int getHeight() const { return height; }

private:
    // we store the SDL_Window pointer
    // into our wrapper class
	SDL_Window* SDLWindow;
	int width;
	int height;
};