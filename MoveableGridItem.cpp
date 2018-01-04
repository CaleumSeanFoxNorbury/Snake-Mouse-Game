#include "MoveableGridItem.h"



MoveableGridItem::MoveableGridItem(int x, int y, char symbol): GridItem(symbol), _x(x), _y(y)
{
}


MoveableGridItem::~MoveableGridItem()
{
}
int MoveableGridItem::get_x()
{
	return _x;
}
int  MoveableGridItem::get_y()
{
	return _y;

}

void MoveableGridItem::set_xy()
{
	_x = SIZE / 2;
	_y = SIZE / 2;
}

bool MoveableGridItem::is_at_position(int x, int y) const
{
	return _x == x && _y == y;
}

void MoveableGridItem::update_position(int dx, int dy) {

	_x += dx;
	_y += dy;
}
