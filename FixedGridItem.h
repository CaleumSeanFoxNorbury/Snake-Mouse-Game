#if !defined(FixedGridItemH)
#define FixedGridItemH
#include "GridItem.h"
#include "constants.h"
class FixedGridItem :
	public GridItem
{
public:

	FixedGridItem(int const  x, int const  y, char const symbol);
	~FixedGridItem();

	int get_x() const;
	int get_y() const;
	bool is_at_position(const int, const int);
private:
	int const _x ;
	int const _y ;
};
#endif

