// FixedGridItem.h: UserInterface for the FixedGridItem class
//////////////////////////////////////////////////////////////////////
#if !defined(FixedGridItemH)
#define FixedGridItemH

#include "GridItem.h"
#include "constants.h"

class FixedGridItem :
	public GridItem
{
public:
	//constructors
	FixedGridItem(int  x, int  y, char symbol);
	~FixedGridItem();
	//assessors
	int get_x();
	int get_y();
	bool is_at_position(const int, const int);
	//mutators

private:
	//data members
	int const _x ;
	int const _y ;
	//supporting functions
};
#endif // !defined(FixedGridItemH)

