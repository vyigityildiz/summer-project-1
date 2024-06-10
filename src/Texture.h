// Loads textures as a surface

#pragma once

#include <SDL2/SDL.h>
#include <string>

SDL_Texture* loadTexture(const std::string &path, SDL_Renderer* renderer);