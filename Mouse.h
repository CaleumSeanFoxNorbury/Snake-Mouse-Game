// Mouse.h: UserInterface for the Mouse class
//////////////////////////////////////////////////////////////////////
#if !defined(MouseH)
#define MouseH

#include "constants.h"
#include "Underground.h"
#include "MoveableGridItem.h"
#include "RandomNumberGenerator.h"

class Mouse:
	public MoveableGridItem
{
public:
	//constructor
	Mouse::Mouse(char const);
	//assessors
	bool is_alive() const;
	bool has_escaped() const;
	bool has_reached_a_hole(Underground ug);	
	//mutators
	void die();
	void escape_into_hole();
	void scamper(char k);
	void reset();
	void position_at_random();	
	static RandomNumberGenerator rng_;

private:
	//data members
	bool alive_;
	bool escaped_;
	int mouse_dx_;
	int mouse_dy_; 
	//supporting functions
};

#endif // !defined(MouseH)
