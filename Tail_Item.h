#pragma once
class Tail_Item
{
public:
	Tail_Item();
	Tail_Item(int x, int y);
	~Tail_Item();

	int get_x;
	int get_y;	
	char get_symbol() const;

private:
	char symbol_;
	int x_;
	int y_;	
};

