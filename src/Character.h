#pragma once

#include <SDL2/SDL.h>

class Character {
    private:
        int x;
        int y;
        int health;
        // TODO change this to a proper thing
        SDL_Rect rect;
    public:
        Character();
        Character(int xPos, int yPos);

        // TODO implement/develop a moving pattern
        void updatePos();
};