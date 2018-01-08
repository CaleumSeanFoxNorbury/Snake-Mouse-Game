// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include<vector>

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include "constants.h"
#include "Tail_Item.h"
#include "MoveableGridItem.h"

class Snake:
	public MoveableGridItem
{
public:
	//constructors
	Snake(char const);
	~Snake();
	//assessors
	bool has_caught_mouse() ;
	//mutators
	void chase_mouse();	
	void position_at_random();	
	void spot_mouse(Mouse* p_mouse);
	vector <Tail_Item> tail_;
	Mouse* p_mouse_;
	static RandomNumberGenerator rng_;

private:
	//data members
	char symbol_;
	//supporting functions
	void set_direction(int& dx, int& dy);

};

#endif // !defined(SnakeH)
