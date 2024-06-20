#include "Character.h"
#include <iostream>

Character::Character() {
    x_ = 200;
    y_ = 200;
    width_ = 32;
    height_ = 32;
    health_ = 100;
    speed_ = 2;
    rect_ = {x_, y_, width_, height_};
}

Character::Character(int xPos, int yPos) {
    x_ = xPos;
    y_ = yPos;
    width_ = 32;
    height_ = 32;
    health_ = 100;
    speed_ = 2;
    rect_ = {x_, y_, width_, height_};
}

// Private Functions

bool Character::doesCollideHelper_(int x, int y, int w, int h) {
    if ((x >= x_ && x <= x_ + width_ && y >= y_ && y <= y_ + height_) || 
        (x + w >= x_ && x + w <= x_ + width_ && y + h >= y_ && y + h <= y_ + height_) ||
        (x + w >= x_ && x + w <= x_ + width_ && y >= y_ && y <= y_ + height_) ||
        (x >= x_ && x <= x_ + width_ && y + h >= y_ && y + h <= y_ + height_)) {
        return true;
    }
    return false;
}

// Public Functions

void Character::randomMove() {
    if (std::rand() % 10 > 5) {
        std::cout << "here" << std::endl;
        moveRight();
    } else {
        moveLeft();
    }

    if (std::rand() % 10 > 5) {
        moveUp();
    } else {
        moveDown();
    }
}

const SDL_Rect* Character::getRect() const{
    return &rect_;
}

void Character::moveRight() {
    x_ += speed_;
    rect_.x = x_;
}

void Character::moveLeft() {
    x_ -= speed_;
    rect_.x = x_;
}

void Character::moveUp() {
    y_ -= speed_;
    rect_.y = y_;
}

void Character::moveDown() {
    y_ += speed_;
    rect_.y = y_;
}

bool Character::doesCollide(Character other) {
    return other.doesCollideHelper_(x_, y_, width_, height_);
}

void Character::setSpeed(int s) {
    speed_ = s;
}

int Character::getHealth() {
    return health_;
}