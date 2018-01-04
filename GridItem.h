
#if !defined(GridItemH)
#define GridItemH
#include "constants.h"

class GridItem
{
public:
	
	GridItem(char const symbol);
	~GridItem();
	
	char get_symbol();
private:
	char const symbol_;
};
#endif

