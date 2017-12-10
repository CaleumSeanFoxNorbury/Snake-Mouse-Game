#pragma once

class TailItem {
public:
	TailItem();
	int get_x() const;
	int get_y() const;
	char get_symbol() const;
private:
	char _symbol;
	int _x, _y;
};