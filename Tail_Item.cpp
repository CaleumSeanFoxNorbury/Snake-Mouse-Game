#include "Tail_Item.h"


static const int Maxtails(3);
Tail_Item::Tail_Item(): symbol_(TAIL), x_(0), y_(0)
{
}

Tail_Item::Tail_Item(int x, int y)
{

}
Tail_Item::~Tail_Item()
{
}

char Tail_Item::get_symbol() const
{
	return symbol_;
}
