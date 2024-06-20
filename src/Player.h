#pragma once

#include <map>
#include "Character.h"
#include "Text.h"

class Player : public Character {
    private:
        int stamina_;
    public:
        Player();
        Player(int xPos, int yPos);

        void speedBoost();
        void normalSpeed();
        void renderHealth(SDL_Texture* fontTexture, int charW, int charH, SDL_Renderer* renderer, std::unordered_map<char, int> charMap);
        void decreaseStamina();
        void increaseStamina();
        bool haveStamina();
};