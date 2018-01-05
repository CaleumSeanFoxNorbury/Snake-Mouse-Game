#include "MoveableGridItem.h"



MoveableGridItem::MoveableGridItem(int x, int y, char symbol): GridItem(symbol), _x(x), _y(y)
{
}


MoveableGridItem::~MoveableGridItem()
{
}
int MoveableGridItem::get_x() const
{
	return _x;
}
int  MoveableGridItem::get_y() const
{
	return _y;

}

void MoveableGridItem::set_xy(int x, int y)
{
	_x = x;
	_y = y;
}

bool MoveableGridItem::is_at_position(int x, int y) const
{
	return _x == x && _y == y;
}

void MoveableGridItem::update_position(int dx, int dy) {

	_x += dx;
	_y += dy;
}
