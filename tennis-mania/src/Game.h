#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Vector2.h"

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
    Game() :
		isRunning(true),
		ballPos({ 100, 100 }),
		ballVelocity({ 500, 500 }),
		paddlePos({ 50, 100 }),
		paddleVelocity({ 0, 450 }),
		paddleDirection(0),
		wallThickness(10),
		topWall(Rectangle()),
		bottomWall(Rectangle()),
		rightWall(Rectangle())
	{}
    
    void processInput();
	void update();
	void render();

	Window window;
	bool isRunning;
    Renderer renderer;

    Rectangle topWall;
	Rectangle bottomWall;
	Rectangle rightWall;
	const float wallThickness = 10;

	Vector2 ballPos;
	Vector2 ballVelocity;
	const float ballSize = 10;

	Vector2 paddlePos;
	Vector2 paddleVelocity;
	const float paddleWidth = 10;
	const float paddleHeight = 64;
	float paddleDirection;
};