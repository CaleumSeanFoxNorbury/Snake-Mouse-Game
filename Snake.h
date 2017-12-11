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
	void spot_mouse(Mouse* p_mouse);
	void chase_mouse();
	void set_direction(int& dx, int& dy);
	void position_at_random();
	void update_position(int dx, int dy);
	char symbol_;
	void move_tail();
	vector <Tail_Item> tail_;

	
	int x_, y_;
	Mouse* p_mouse_;
	static RandomNumberGenerator rng_;

private:

	bool is_at_position(int x, int y);
	char tail_symbol;

};

#endif // !defined(SnakeH)
