// Snake.h: UserInterface for the Snake class 
//////////////////////////////////////////////////////////////////////
#if !defined(SnakeH)
#define SnakeH

#include "Mouse.h"
#include "RandomNumberGenerator.h"
#include"constants.h"
#include <vector>
#include "TailItem.h"

class Snake {
	public:
		Snake();
		~Snake();
		bool is_at_position(int x, int y);  
		bool has_caught_mouse() ;
		void spot_mouse(Mouse* p_mouse);
		void chase_mouse();
		void set_direction(int& dx, int& dy);
		void position_at_random();
		void update_position(int dx, int dy);
		void move_tail();
		char symbol_;
		int x_, y_;
		Mouse* p_mouse_;
		RandomNumberGenerator rng_;

private:
	vector<TailItem> _tail;
};

#endif // !defined(SnakeH)
