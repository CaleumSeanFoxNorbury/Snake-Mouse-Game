#if !defined(HoleH)
#define HoleH

#include <cassert>
#include <vector>
//#include "FixedGridItem.h"
#include "constants.h"
using namespace std;

class Hole //: public FixedGridItem 
{
public:
	//constructors
	Hole();
	Hole(int const x, int const y);
	//assessors
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool is_at_position(int x, int y);
private:
	static const int MAXHOLES; //number of holes in underground						   
	char symbol_;
	int x_, y_;
};
#endif // !defined(HoleH) 
