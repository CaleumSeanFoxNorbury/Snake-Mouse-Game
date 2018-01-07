#include "Nut.h"

RandomNumberGenerator Nut::rng_;
Nut::Nut(char const symbol):MoveableGridItem(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE), symbol)
{

	_collected = false;
}




bool Nut::has_been_collected() const
{
	return _collected;
}


void Nut::disappears()
{
	_collected = true;
}

void Nut::reappears()
{
	_collected = false;
}

void Nut::position_at_random()
{
	set_xy(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
}

