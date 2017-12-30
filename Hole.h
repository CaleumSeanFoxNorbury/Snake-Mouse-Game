#if !defined(HoleH)
#define HoleH

#include <cassert>
#include <vector>
using namespace std;

#include "constants.h"

class Hole {
public:
	//constructors
	Hole();
	Hole(int x, int y);
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
