#if !defined(HoleH)
#define HoleH

#include <cassert>
#include <vector>
#include "FixedGridItem.h"
#include "constants.h"
using namespace std;

class Hole 
	: public FixedGridItem 
{
public:
	//constructors
	Hole();
	Hole(int x, int y);
};
#endif // !defined(HoleH) 
