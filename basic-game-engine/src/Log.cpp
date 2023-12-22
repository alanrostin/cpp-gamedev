#include "Log.h"
#include <SDL2/SDL_error.h>

void Log::info(const std::string& message)
{
    SDL_Log(message.c_str());
}

void Log::error(LogCategory category, const std::string& message)
{
    SDL_LogError(static_cast<int>(category), "%s | SDL: %s", message.c_str(), SDL_GetError());
}