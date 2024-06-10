#include "Text.h"

SDL_Rect getCharRect(char c, int charW, int charH, std::unordered_map<char, int> charMap) {
    int index = charMap[c];
    SDL_Rect charRect;
    charRect.w = charW;
    charRect.h = charH;
    charRect.x = (index % 26) * charW;
    charRect.y = (index / 26) * charH;
    return charRect;
}

void renderText(const std::string &text, int x, int y, SDL_Texture* fontTexture, int charW, int charH, SDL_Renderer* renderer, std::unordered_map<char, int> charMap) {
    for (size_t i = 0; i < text.size(); ++i) {
        SDL_Rect srcRect = getCharRect(text[i], charW, charH, charMap);
        SDL_Rect dstRect = {x + static_cast<int>(i * (charW / 2)), y, charW / 2, charH / 2};
        SDL_RenderCopy(renderer, fontTexture, &srcRect, &dstRect);
    }
}