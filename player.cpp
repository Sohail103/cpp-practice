#include "player.h"

Player::Player() = default;

Player::Player(int gamenum) { this->gamenum = gamenum; }

Player::~Player() = default;

int Player::getgamenum() { return gamenum; }

std::ostream &operator<<(std::ostream &out, Player &p) {
    out << "Name: " << p.getname() << ", Age: " << *(p.getage())
        << ", Game number: " << p.getgamenum() << "\n";
}