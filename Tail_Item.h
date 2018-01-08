// Tail_Item.h: UserInterface for the Tail_Item class
//////////////////////////////////////////////////////////////////////
#pragma once

#include "constants.h"

class Tail_Item
{
public:
	//constructors
	Tail_Item();
	Tail_Item(int x, int y);
	~Tail_Item();
	//assessors
	int get_x;
	int get_y;	
	char get_symbol() const;
	//mutators

private:
	//data members
	char symbol_;
	int x_;
	int y_;
	//supporting functions

};

