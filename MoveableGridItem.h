#if !defined(MoveableGridItemH)
#define MoveableGridItemH

#include "GridItem.h"
#include "constants.h"
class MoveableGridItem :
	public GridItem
{
public:
	MoveableGridItem(int, int, const char);
	~MoveableGridItem();
	int get_x();
	int get_y();
	void set_xy();
	
	bool is_at_position(int, int) const;
	void update_position(int, int);

private:
	int _x;
	int _y;
};

#endif
