// Mouse.cpp: implementation of the Mouse class
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
RandomNumberGenerator Mouse::rng_;
Mouse::Mouse(char symbol): MoveableGridItem(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE), symbol),
                alive_(true), escaped_(false), 
				mouse_dx_(0), mouse_dy_(0) {
	
}

//////////////////////////////////////////////////////////////////////
// Public functions
//////////////////////////////////////////////////////////////////////


bool Mouse::is_alive() const {
	return alive_;
}
bool Mouse::has_escaped() const {
	return escaped_;
}
bool Mouse::has_reached_a_hole(Underground ug) {
	for (int h_no(0); h_no < ug.holes_.size(); ++h_no)
	{
		Hole h = ug.get_hole_no(h_no);
		if (is_at_position(h.get_x(), h.get_y()))
			return true;
	}
	return false;
}
void Mouse::die()
{
	alive_ = false;
}
void Mouse::escape_into_hole() 
{
	escaped_ = true;
}


void Mouse::scamper(char k) { //move mouse in required direction
  //pre: Key is an arrow representing the direction in which the mouse moves
	//find direction indicated by key
	switch(k)               //...depending on the selected key...
	{
		case LEFT:           //when LEFT arrow pressed...
			mouse_dx_ = -1;    //decrease the X coordinate
			mouse_dy_ = 0;
			break;
		case RIGHT:          //when RIGHT arrow pressed...
			mouse_dx_ = +1;    //increase the X coordinate
			mouse_dy_ = 0;
			break;
		case UP:             //when UP arrow pressed...
			mouse_dx_ = 0;
			mouse_dy_ = -1;    //decrease the Y coordinate
			break;
		case DOWN:           //when DOWN arrow pressed...
			mouse_dx_ = 0;
			mouse_dy_ = +1;    //increase the Y coordinate
			break;
	}
	//update mouse coordinates if move is possible
	if (((get_x() + mouse_dx_) >= 1) && ((get_x() + mouse_dx_) <= SIZE) &&
		 ((get_y() + mouse_dy_) >= 1) && ((get_y() + mouse_dy_) <= SIZE) )
	{
		update_position(mouse_dx_, mouse_dy_);		//go in that direction
	}
}

void Mouse::position_at_random()
{
	set_xy(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
}

void Mouse::reset()
{	alive_ = true;
	escaped_ = false;
	set_xy(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
}

//////////////////////////////////////////////////////////////////////
// Private functions
//////////////////////////////////////////////////////////////////////
