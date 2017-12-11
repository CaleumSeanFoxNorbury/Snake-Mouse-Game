#pragma once
class Tail_Item
{
public:
	Tail_Item();
	~Tail_Item();

	int x_;
	int y_;

	int get_x;
	int get_y;
	char symbol_;
	
	bool is_at_position(int x, int y);
	char get_symbol() const;

private:
		
		
		
};

