#include "Character.h"

Character::Character() {
    x_ = 200;
    y_ = 200;
    width_ = 32;
    height_ = 32;
    health_ = 100;
    rect_ = {x_, y_, width_, height_};
}

Character::Character(int xPos, int yPos) {
    x_ = xPos;
    y_ = yPos;
    width_ = 32;
    height_ = 32;
    health_ = 100;
    rect_ = {x_, y_, width_, height_};
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

bool Character::doesCollideHelper_(int x, int y, int w, int h) {
    if ((x > x_ && x < x_ + width_ && y > y_ && y < y_ + height_) || (x + w > x_ && x + w < x_ + width_ && y + h > y_ && y + h < y_ + height_)) {
        return true;
    }
    return false;
}

bool Character::doesCollide(Character other) {
    return other.doesCollideHelper_(x_, y_, width_, height_);
}