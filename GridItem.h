// GridItem.h: UserInterface for the GridItem class
//////////////////////////////////////////////////////////////////////
#if !defined(GridItemH)
#define GridItemH

#include "constants.h"

class GridItem
{
public:
	//constructors
	GridItem(char const symbol);
	~GridItem();
	//assessor
	char get_symbol();
	//mutators

private:
	//data members
	char const symbol_;
	//supporting functions
};

#endif // !defined(GridItemH)

