#include "FixedGridItem.h"


FixedGridItem::FixedGridItem(int  x, int  y, char symbol):GridItem(symbol), _x(x), _y(y)
{
}

FixedGridItem::~FixedGridItem()
{
}

int FixedGridItem::get_x() const
{
	return _x;
}

int FixedGridItem::get_y() const
{
	return _y;
}

bool FixedGridItem::is_at_position(const int x, const int y)
{
	return _x == x && _y == y;
}
