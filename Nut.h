// Nut.h: UserInterface for the Nut class
//////////////////////////////////////////////////////////////////////
#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class Nut :
	public MoveableGridItem
{
public:
	//constructor
	Nut(char symbol);
	//assessors
	bool has_been_collected() const;
	//mutators
	void disappears();
	void reappears();
	void position_at_random();
	static RandomNumberGenerator rng_;

private:
	//data members
	bool _collected;
	//supporting functions
};
#endif	// !defined(NutH)
