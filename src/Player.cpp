#include "Player.h"

Player::Player() : Character() {
    stamina_ = 100;
}

Player::Player(int x, int y) : Character(x, y) {
    stamina_ = 100;
}

void Player::speedBoost() {
    setSpeed(3);
}

void Player::normalSpeed() {
    setSpeed(2);
}

void Player::renderHealth(SDL_Texture* fontTexture, int charW, int charH, SDL_Renderer* renderer, std::unordered_map<char, int> charMap) {
    renderText("Health:" + std::to_string(getHealth()), 10, 10, fontTexture, 32, 32, renderer, charMap);
    renderText("Stamina:" + std::to_string(stamina_), 10, 30, fontTexture, 32, 32, renderer, charMap);
}

void Player::decreaseStamina() {
    if (stamina_ > 0) {
        --stamina_;
    }
}

void Player::increaseStamina() {
    if (stamina_ < 100) {
        ++stamina_;
    }
}