#include "Score.h"



Score::Score()
{
	_amount = 0;
}

int Score::get_amount() const
{
	return _amount;
}

void Score::update_amount(const int amount)
{
	_amount += amount;
}