#include "Nut.h"

Nut::Nut(const int x, const int y)
{
	_x = x;
	_y = y;
	_symbol = NUT;
	_collected = false;
}

Nut::Nut() {}

int Nut::get_x() const 
{
	return _x;
}
int Nut::get_y() const
{
	return _y;
}
char Nut::get_symbol() const
{
	return _symbol;
}
bool Nut::has_been_collected() const
{
	return _collected;
}
bool Nut::is_at_position(const int x, const int y) const
{
	return _x == x && _y == y;
}

void Nut::disappears()
{
	_collected = true;
}

void Nut::reappears()
{
	_collected = false;
}
