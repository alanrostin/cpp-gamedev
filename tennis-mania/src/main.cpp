#include "Game.h"

int main(int argc, char** argv)
{
    bool isGameInit = Game::instance().initialize(); // use of the singleton
	if (isGameInit)
	{
		Game::instance().loop();
	}
	Game::instance().close();

    return 0;
}