#include "Nut.h"

Nut::Nut(int  x, int  y, char const symbol):MoveableGridItem(x,y,symbol)
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
