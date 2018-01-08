// Game.h: UserInterface for the Game class
//////////////////////////////////////////////////////////////////////
#if !defined(GameH)
#define GameH

#include <string>
#include <iostream>
#include <sstream>

#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"
#include "Nut.h"
#include "Player.h"
#include "Tail_Item.h"
#include "FixedGridItem.h"
#include "GridItem.h"
#include "constants.h"

class Game
{
public:
	//constructor
	Game(Player* player);
	//assessors
	void set_up(UserInterface* pui);
	//mutators
	void run();
	
private:
	//data members
	Player* _player;
	string prepare_grid();
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
   	Nut nut_;
	string prepare_end_message();
	int key_;
	bool cheatMode, cheatModeUsed;
	//supporting functions
	void apply_rules();
	void toggle_cheat_mode();
	bool is_arrow_key_code(int keycode);
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	bool tail_position(int const row, int const col);

};

#endif // !defined(GameH)
