#if !defined(FixedGridItemH)
#define FixedGridItemH
#include "GridItem.h"
#include "constants.h"
class FixedGridItem :
	public GridItem
{
public:

	FixedGridItem(int  x, int  y, char symbol);
	~FixedGridItem();

	int get_x();
	int get_y();
	bool is_at_position(const int, const int);
private:
	int const _x ;
	int const _y ;
};
#endif

