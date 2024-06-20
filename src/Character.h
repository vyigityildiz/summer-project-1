#pragma once

#include <SDL2/SDL.h>

class Character {
    private:
        int x_;
        int y_;
        int width_;
        int height_;
        int health_;
        int speed_;
        // TODO change this to a proper thing
        SDL_Rect rect_;
        
        bool doesCollideHelper_(int x, int y, int w, int h);
    public:
        Character();
        Character(int xPos, int yPos);

        // TODO implement/develop a moving pattern
        void randomMove();
        const SDL_Rect* getRect() const;

        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
        bool doesCollide(Character other);
        void setSpeed(int s);
        int getHealth();
};