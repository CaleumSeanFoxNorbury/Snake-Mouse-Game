#include "Hole.h"


Hole::Hole()
{}
Hole::Hole(int const x, int const y): x_(x), y_(y), symbol_(HOLE) {

}
int Hole::get_x() const {
	return x_;
}
int Hole::get_y() const {
	return y_;
}
char Hole::get_symbol() const {
	return symbol_;
}
bool Hole::is_at_position(int x, int y) {
	return (x_ == x) && (y_ == y);
}