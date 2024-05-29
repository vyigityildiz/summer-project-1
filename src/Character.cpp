#include "Character.h"

Character::Character() {
    x_ = 200;
    y_ = 200;
    health_ = 100;
    rect_ = {x_, y_, 32, 32};
}

Character::Character(int xPos, int yPos) {
    x_ = xPos;
    y_ = yPos;
    health_ = 100;
    rect_ = {x_, y_, 32, 32};
}

void Character::updatePos() {
    return;
}

const SDL_Rect* Character::getRect() const{
    return &rect_;
}

void Character::moveRight() {
    ++x_;
    rect_.x = x_;
}

void Character::moveLeft() {
    --x_;
    rect_.x = x_;
}

void Character::moveUp() {
    --y_;
    rect_.y = y_;
}

void Character::moveDown() {
    ++y_;
    rect_.y = y_;
}