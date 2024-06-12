#include "Player.h"

Player::Player() : Character() {
}

Player::Player(int x, int y) : Character(x, y) {
}

void Player::speedBoost() {
    setSpeed(3);
}

void Player::normalSpeed() {
    setSpeed(2);
}