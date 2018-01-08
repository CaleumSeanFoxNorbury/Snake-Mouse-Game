// MoveableGridItem.h: UserInterface for the MoveableGridItem class
//////////////////////////////////////////////////////////////////////
#if !defined(MoveableGridItemH)
#define MoveableGridItemH

#include "GridItem.h"
#include "constants.h"

class MoveableGridItem :
	public GridItem
{
public:
	//constructor
	MoveableGridItem(int, int, const char);
	~MoveableGridItem();
	//assessors
	int get_x();
	int get_y();
	bool is_at_position(int, int) const;
	//mutators
	void set_xy(int, int);
	void update_position(int, int);

private:
	//data members
	int _x;
	int _y;
	//supporting functions
};

#endif // !defined(MoveableGridItemH)
