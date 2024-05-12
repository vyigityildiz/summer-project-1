#pragma once

#include <SDL2/SDL.h>
#include "Character.h"

class Player : Character {
    private:
        // TODO change this to the real player
        int x;
        int y;
    public:
        Player();
        Player(int xPos, int yPos);
        
        // TODO move methods
        void moveRight();
        void moveLeft();
        void moveUp();
        void moveDown();
};