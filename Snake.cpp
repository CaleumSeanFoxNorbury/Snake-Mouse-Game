// Snake.cpp: implementation of the Snake class
////////////////////////////////////////////////////////////////////// 

//////////////////////////////////////////////////////////////////////
#include<vector>

#include "Snake.h"
#include"Tail_Item.h"
static const int Maxtails(3);
Snake::Snake(): tail_(3) {
	symbol_ = SNAKEHEAD;
	position_at_random();
	p_mouse_ = nullptr; //to make the pointer is safe before the snake spots the mouse
	
}
Snake::~Snake()
{}

bool Snake::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}

bool Snake::has_caught_mouse() {
	return is_at_position(p_mouse_->x_, p_mouse_->y_);
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
	update_position(snake_dx, snake_dy);
}


void Snake::set_direction(int& dx, int& dy)
{
	assert(p_mouse_ != nullptr);  //Pre-condition: The snake needs to know where the mouse is 
	//assume snake only move when necessary
	dx = 0; dy = 0;
		//update coordinate if necessary
	if (x_ < p_mouse_->get_x())             //if snake on left of mouse
		dx = 1;                          //snake should move right
	else                                    //otherwise
		if (x_ > p_mouse_->get_x())         //if snake on left of mouse
			dx = -1;                     //snake should move left
	if (y_ < p_mouse_->get_y())             //if snake is above mouse
		dy = 1;                          //snake should move down
	else                                    //otherwise
		if (y_ > p_mouse_->get_y())         //if snake is below mouse
			dy = -1;                     //snake should move up
}

void Snake::update_position(int dx, int dy) {

	tail_.at(2).get_x = tail_.at(1).get_x;
	tail_.at(2).get_y = tail_.at(1).get_y;

	tail_.at(1).get_x = tail_.at(0).get_x;
	tail_.at(1).get_y = tail_.at(0).get_y;
	
	tail_.at(0).get_x = x_;
	tail_.at(0).get_y = y_;
		 
	x_ += dx;
	y_ += dy;
	

	
}

RandomNumberGenerator Snake::rng_;

void Snake::position_at_random() {
	x_ = rng_.get_random_value(SIZE);        //WARNING: may fall on mouse
	y_ = rng_.get_random_value(SIZE);
	for(int i = 0; i < 3; i++)
	{
		tail_.at(i).get_x = x_;
		tail_.at(i).get_y = y_;
	}

	

}