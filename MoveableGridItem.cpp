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
bool MoveableGridItem::is_at_position(int x, int y)
{
	return _x == x && _y == y;
}
