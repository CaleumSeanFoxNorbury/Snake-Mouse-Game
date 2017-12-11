#pragma once

#include "constants.h"
class Nut
{
public:
	Nut();
	Nut(const int, const int);
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
	bool has_been_collected() const;
	bool is_at_position(const int, const int) const;
	void disappears();
	void reappears();
private:
	int _x, _y;
	char _symbol;
	bool _collected;
};

