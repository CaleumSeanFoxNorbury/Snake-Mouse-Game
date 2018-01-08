#include "Game.h"

Game::Game(Player* player):nut_(NUT),snake_(SNAKEHEAD),mouse_(MOUSE), _player(player), cheatMode(false) 
{
	 
}

void Game::set_up(UserInterface* pui) {
	//prepare game
	//set up the holes
	//underground_.set_hole_no_at_position(0, 4, 3);
	//underground_.set_hole_no_at_position(1, 15, 10);
	//underground_.set_hole_no_at_position(2, 7, 15);
	//mouse state already set up in its contructor
	//set up snake
	snake_.spot_mouse(&mouse_);
	//set up the UserInterface
	p_ui = pui;
}

void Game::run() {
	assert(p_ui != nullptr);

	//Mouse, Nut, Snake collsion check
	while(mouse_.is_at_position(snake_.get_x(), snake_.get_y()) == true)
	{
		mouse_.position_at_random();
	}

	while ((nut_.is_at_position(snake_.get_x(), snake_.get_y()) == true) || (nut_.is_at_position(mouse_.get_x(), mouse_.get_y())))
	{
		nut_.position_at_random();
	}


	p_ui->draw_grid_on_screen(prepare_grid());
	cout << "Player: " << _player->get_name() << endl;
	cout << "Score: " << to_string(_player->get_score_amount()) << endl;

	key_ = p_ui->get_keypress_from_user();
	while (!has_ended(key_))
	{
		if (key_ == 'C')
		{
			cheatModeUsed = true;
			toggle_cheat_mode();
		}

		if (is_arrow_key_code(key_))
		{
			mouse_.scamper(key_);

			if (!cheatMode)
			{
				snake_.chase_mouse();
			}
				
			p_ui->draw_grid_on_screen(prepare_grid());
			if (cheatMode)
			{
				cout << "CHEAT MODE ACTIVATED" << endl;
			}
			cout << "Player: " << _player->get_name() << endl;
			cout << "Score: " << to_string(_player->get_score_amount()) << endl;
			apply_rules();
		}

		key_ = p_ui->get_keypress_from_user();
	}

	p_ui->show_results_on_screen(prepare_end_message());
}

string Game::prepare_grid() {
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)		//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			
			if ((row == snake_.get_y()) && (col == snake_.get_x()))
				os << snake_.get_symbol();			//show snake
			else {
				if (tail_position(row, col))
				{
					os << snake_.tail_.at(0).get_symbol();
				}
				else {
					if ((row == mouse_.get_y()) && (col == mouse_.get_x()))
					{
						os << mouse_.get_symbol();
					}
					else
					{
						if ((row == nut_.get_y() && col == nut_.get_x()) && !nut_.has_been_collected())
							os << nut_.get_symbol();
						else
						{
							const int hole_no(find_hole_number_at_position(col, row));
							if (hole_no != -1)
								os << underground_.get_hole_no(hole_no).get_symbol();	//show hole
							else
								os << FREECELL;	//show free grid cell
						}
					}
				}
			}
				
			
		} //end of col-loop
		os << endl;
	} //end of row-loop
	return os.str();
} //end prepare_grid

bool Game::is_arrow_key_code(int keycode) {
	return (keycode == LEFT) || (keycode == RIGHT) || (keycode == UP) || (keycode == DOWN);
}
int Game::find_hole_number_at_position(int x, int y) {
	for (int h_no(0); h_no < 3; ++h_no)
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	return -1;				//not a hole
}
void Game::apply_rules() {
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
		if (!cheatModeUsed)
		{
			_player->update_score_amount(-1);
		}
	}
	
	else
	
	{
		if (mouse_.is_at_position(nut_.get_x(), nut_.get_y()))
		{
			nut_.disappears();
		}
		if (mouse_.has_reached_a_hole(underground_) && nut_.has_been_collected())
		{
			mouse_.escape_into_hole();
			if (!cheatModeUsed)
			{
				_player->update_score_amount(1);
			}
		}

	}
}
bool Game::has_ended(char key) {
	return ((key == 'Q') || (!mouse_.is_alive()) || (mouse_.has_escaped()));
}


string Game::prepare_end_message() {
	ostringstream os;
	if (mouse_.has_escaped())
		os << "\n\nEND OF GAME: THE MOUSE ESCAPED UNDERGROUND!";
	else
		if (!mouse_.is_alive())
			os << "\n\nEND OF GAME: THE SNAKE ATE THE MOUSE!";
		else
			os << "\n\nEND OF GAME: THE PLAYER ENDED THE GAME!";
	return os.str();
}

bool Game::tail_position(int const row, int const col)
{
	bool tail_at_pos = false;
	for (int x(0); x < snake_.tail_.size(); x++)
	{
		if ((row == snake_.tail_.at(x).get_y) && (col == snake_.tail_.at(x).get_x))
		{
			tail_at_pos = true;
		}
	}
	return tail_at_pos;
}

void Game::toggle_cheat_mode()
{
	cheatMode = !cheatMode;
}