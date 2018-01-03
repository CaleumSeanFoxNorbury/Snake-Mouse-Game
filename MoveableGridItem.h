#if !defined(MoveableGridItemH)
#define MoveableGridItemH

#include "GridItem.h"
#include "constants.h"
class MoveableGridItem :
	public GridItem
{
public:
	MoveableGridItem(int, int, char);
	~MoveableGridItem();
	int get_x();
	int get_y();
	bool is_at_position(int, int);

private:
	int _x;
	int _y;
};

#endif
