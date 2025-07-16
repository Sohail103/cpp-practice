#include "player.h"

Player::Player() = default;

Player::Player(int gamenum) { this->gamenum = gamenum; }

Player::~Player() = default;

int Player::getgamenum() { return gamenum; }