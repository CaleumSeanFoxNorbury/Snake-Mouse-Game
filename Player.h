// Player.h: UserInterface for the Player class
//////////////////////////////////////////////////////////////////////
#pragma once

#include <string>

#include "Score.h"

using namespace std;

class Player
{
public:
	//constructor
	Player(const string);
	//assessors
	string get_name() const;
	int get_score_amount() const;
	//mutators
	void update_score_amount(const int);

private:
	//data members
	const string _name;
	Score _score;
	//supporting functions
};

