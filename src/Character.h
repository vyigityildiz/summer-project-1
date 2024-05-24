#pragma once

#include <SDL2/SDL.h>

class Character {
    private:
        int x_;
        int y_;
        int health_;
        // TODO change this to a proper thing
        SDL_Rect rect_;
    public:
        Character();
        Character(int xPos, int yPos);

        // TODO implement/develop a moving pattern
        void updatePos();
        const SDL_Rect* getRect() const;

        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
};