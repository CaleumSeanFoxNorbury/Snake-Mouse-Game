#pragma once
class Tail_Item
{
public:
	Tail_Item();
	Tail_Item(int x, int y);
	~Tail_Item();

	int get_x;
	int get_y;
	char symbol_;
	
	void move_tail() ;
		
	char get_symbol() const;

private:
		
	int x_;
	int y_;	
};

