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
#include "constants.h"

class Game
{
public:
	Game();
	void set_up(UserInterface* pui);
	void reset();
	void run();

private:
	Player _player;
	string prepare_grid();
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
   	Nut _nut;
	string prepare_end_message();
	int key_;
	void apply_rules();
	bool is_arrow_key_code(int keycode);
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);
	bool tail_position(int const row, int const col);
};

#endif
