#include "Player.h"
Player::Player(const string name) : _name(name)
{
}

string Player::get_name() const
{
	return _name;
}

int Player::get_score_amount() const
{
	return _score.get_amount();
}

void Player::update_score_amount(const int amount)
{
	_score.update_amount(amount);
}
