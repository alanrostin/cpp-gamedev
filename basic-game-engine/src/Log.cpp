#include "Log.h"
#include <SDL2/SDL_log.h>
#include <SDL2/SDL_error.h>

void Log::info(const std::string& message)
{
    // c_str() ends a string with a \0 character, to make it compatible with c
    SDL_Log(message.c_str());
}

void Log::error(LogCategory category, const std::string& message)
{
    SDL_LogError(static_cast<int>(category), "%s | SDL: %s", message.c_str(), SDL_GetError());
}