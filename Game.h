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

class Game
{
public:
	Game();
	Mouse mouse_;
	Snake snake_;
	Underground underground_;
	UserInterface* p_ui;
	Nut _nut;
	void set_up(UserInterface* pui);
	void reset();
	void run();
	bool is_arrow_key_code(int keycode);
	int find_hole_number_at_position(int x, int y);
	bool has_ended(char key);

private:
	Player _player;
	string prepare_grid();
	int key_;
	void apply_rules();
	string prepare_end_message();
};

#endif
