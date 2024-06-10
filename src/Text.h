// Writes text on screen

#pragma once

#include "Texture.h"
#include <map>

SDL_Rect getCharRect(char c, int charW, int charH, std::unordered_map<char, int> charMap);

void renderText(const std::string &text, int x, int y, SDL_Texture* fontTexture, int charW, int charH, SDL_Renderer* renderer, std::unordered_map<char, int> charMap);
