#include "Tail_Item.h"
#include "constants.h"


static const int Maxtails(3);
Tail_Item::Tail_Item(): symbol_(TAIL), x_(0), y_(0)
{
}


Tail_Item::~Tail_Item()
{
}

char Tail_Item::get_symbol() const
{
	return symbol_;
}

bool Tail_Item::is_at_position(int x, int y)
{
	return (x_ == x) && (y_ == y);
}