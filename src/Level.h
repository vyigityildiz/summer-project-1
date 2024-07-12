#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include "Texture.h"
#include "Character.h"

class Level {
    private:
        int numberOfEnemies_;
        int numberOfFirst_;
        int numberOfSecond_;
        int numberOfThird_;
        std::vector<Character> enemies;
    public:
        Level();
        void createLevel();
        // TODO these methods
        void renderLevel();
};