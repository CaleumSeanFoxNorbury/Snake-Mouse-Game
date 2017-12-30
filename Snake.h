// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include"constants.h"
#include "Tail_Item.h"
class Snake {
public:

	Snake();
	~Snake();
	bool has_caught_mouse() ;
	int get_x();
	int get_y();
	char get_symbol();
	void chase_mouse();	
	void position_at_random();	
	void spot_mouse(Mouse* p_mouse);
	vector <Tail_Item> tail_;
	Mouse* p_mouse_;
	static RandomNumberGenerator rng_;

private:
	char symbol_;
	bool is_at_position(int x, int y);
	void set_direction(int& dx, int& dy);
	int x_, y_;
	void update_position(int dx, int dy);


};

#endif // !defined(SnakeH)
