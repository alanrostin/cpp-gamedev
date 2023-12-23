#pragma once
#include "Window.h"
#include "Renderer.h"

class Game
{
public:
    // since c++11, this will ensure the existence and
    // unicity of the Game instance(inst)
    static Game& instance() 
    {
        static Game inst;
        return inst;
    }

    Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

    bool initialize();
	void loop();
	void close();

private:
    // singleton's constructor is private
    Game() : isRunning(true) {}
    void processInput();
	void update();
	void render();

	Window window;
	bool isRunning;
    Renderer renderer;
};