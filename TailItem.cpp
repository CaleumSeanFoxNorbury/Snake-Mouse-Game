#include "TailItem.h"
#include "Snake.h"

int TailItem::get_x() const {
	return _x;
}

int TailItem::get_y() const {
	return _y;
}

char TailItem::get_symbol() const {
	return _symbol;
}

//setting tail symbol
TailItem::TailItem() {
	_symbol = 'T';
}

//update tail possition
void UpdateTailPossition(){
	//changing the position of the tail one to == snakes old position
	for (int i = 0; i < tail.size(); i++) {
		//need to change arse to body
		//body to head
		tail.at(i) == _x += x_;
		tail.at(i) == _y += y_;

		tail.at(2) == _x += x_ - 1;
		tail.at(2) == _y += y_ - 1;

		tail.at(3) == _x += x_ - 2;
		tail.at(3) == _y += y_ - 2;
	}
}

//moving tail with the snake
void moveTail{
	for(int i = 0; i < tail.size; i++) {
		tail.at(i).updateTailPossition(_x, _y);
	}
}
