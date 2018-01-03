// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include"constants.h"
#include "Tail_Item.h"
#include "MoveableGridItem.h"
class Snake
	//public MoveableGridItem
{
public:

	Snake();
	~Snake();
	bool has_caught_mouse() ;

	void chase_mouse();	
	void position_at_random();	
	void spot_mouse(Mouse* p_mouse);
	vector <Tail_Item> tail_;
	Mouse* p_mouse_;
	static RandomNumberGenerator rng_;
	bool is_at_position(int x, int y);
	char get_symbol();
	int get_x();
	int get_y();
private:
	int x_, y_;
	
	void set_direction(int& dx, int& dy);
	char symbol_;
	void update_position(int dx, int dy);


};

#endif // !defined(SnakeH)
