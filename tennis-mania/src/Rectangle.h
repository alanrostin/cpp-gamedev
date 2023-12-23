#pragma once
#include <SDL2/SDL_rect.h>

// structs are used to hold data types
struct Rectangle
{
    float x;
    float y;
    float width;
    float height;

    // our struct wraps the SDL structs
    SDL_Rect toSDLRect() const
    {
        return SDL_Rect
        {
            static_cast<int>(x),
            static_cast<int>(y),
            static_cast<int>(width),
            static_cast<int>(height)
        };
    }
};