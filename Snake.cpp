// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////

#include "Snake.h"
static const int Maxtails(3);
RandomNumberGenerator Snake::rng_;
Snake::Snake(char const symbol):MoveableGridItem(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE), symbol), tail_(3),p_mouse_(nullptr){
	 
	for (int i = 0; i < 3; i++)
	{
		tail_.at(i).get_x = get_x();
		tail_.at(i).get_y = get_y();
	}
	
}
Snake::~Snake()
{}

bool Snake::has_caught_mouse() {
	return is_at_position(p_mouse_->get_x(), p_mouse_->get_y());
}

void Snake::spot_mouse(Mouse* p_mouse) {
	assert(p_mouse != nullptr);	 //Pre-condition: The mouse needs to exist 
	p_mouse_ = p_mouse;
}

void Snake::chase_mouse() {	 
	int snake_dx, snake_dy;
	//identify direction of travel
	set_direction(snake_dx, snake_dy);
	//go in that direction
	tail_.at(2).get_x = tail_.at(1).get_x;
	tail_.at(2).get_y = tail_.at(1).get_y;

	tail_.at(1).get_x = tail_.at(0).get_x;
	tail_.at(1).get_y = tail_.at(0).get_y;

	tail_.at(0).get_x = get_x();
	tail_.at(0).get_y = get_y();
	update_position(snake_dx, snake_dy);
}


void Snake::set_direction(int& dx, int& dy)
{
	assert(p_mouse_ != nullptr);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (get_x() < p_mouse_->get_x())             //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (get_x() > p_mouse_->get_x())         //if snake on left of mouse
			dx = -1;                     //snake should move left
	if (get_y() < p_mouse_->get_y())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (get_y() > p_mouse_->get_y())         //if snake is below mouse
			dy = -1;                     //snake should move up
}

void Snake::position_at_random() {
	
	set_xy(rng_.get_random_value(SIZE), rng_.get_random_value(SIZE));
	for (int i = 0; i < 3; i++)
	{
		tail_.at(i).get_x = get_x();
		tail_.at(i).get_y = get_y();
	}

}