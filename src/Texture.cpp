#include <iostream>
#include "Texture.h"

SDL_Texture* loadTexture(const std::string &path, SDL_Renderer* renderer) {
    SDL_Texture* texture = nullptr;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path.c_str());
    if (loadedSurface == nullptr) {
        std::cerr << "Can't load surface at " << path << " SDL Error: " << SDL_GetError() << std::endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == nullptr) {
            std::cerr << "Unable to create texture from " << path << " SDL Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(loadedSurface);
    }
    return texture;
}