#include "player.h"

Player::Player() = default;

Player::Player(std::string_view name, int age, int gamenum) : Person(name, age), gamenum(gamenum) {
    // this->name = name;
    // this->age = new int{age};
    // this->gamenum = gamenum;
}

Player::~Player() = default;

int Player::getgamenum() { return gamenum; }

Player::Player(const Player &p) : Person(p), gamenum(p.gamenum) {
    std::cout << "copy constructor called\n";
}

std::ostream &operator<<(std::ostream &out, Player &p) {
    out << "Name: " << p.getname() << ", Age: " << *(p.getage())
        << ", Game number: " << p.getgamenum() << "\n";
    return out;
}