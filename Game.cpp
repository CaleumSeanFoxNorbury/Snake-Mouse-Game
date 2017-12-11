#include "Game.h"


Game::Game() {}

void Game::set_up(UserInterface* pui) {
	//prepare game
	//set up the holes
	underground_.set_hole_no_at_position(0, 4, 3);
	underground_.set_hole_no_at_position(1, 15, 10);
	underground_.set_hole_no_at_position(2, 7, 15);
	//mouse state already set up in its contructor
	//set up snake
	snake_.position_at_random();
	snake_.spot_mouse(&mouse_);
	//set up the UserInterface
	p_ui = pui;

	_nut = Nut(8, 9);
}

void Game::reset()
{
	snake_.position_at_random();
	_nut.reappears();
	mouse_.reset();
}

void Game::run() {
	assert(p_ui != nullptr);

	string name;
	cout << "Enter your name: ";
	cin >> name;

	_player = Player(name);


	char carryOn;

	do
	{
		p_ui->draw_grid_on_screen(prepare_grid());
		cout << "Player: " << _player.get_name() << endl;
		cout << "Score: " << _player.get_score_amount() << endl;
		key_ = p_ui->get_keypress_from_user();
		while (!has_ended(key_))
		{
			
			if (is_arrow_key_code(key_))
			{
				mouse_.scamper(key_);
				snake_.chase_mouse();
				snake_.move_tail();
				p_ui->draw_grid_on_screen(prepare_grid());
				cout << "Player: " << _player.get_name() << endl;
				cout << "Score: " << _player.get_score_amount() << endl;
				apply_rules();
			}

			key_ = p_ui->get_keypress_from_user();
		}

		p_ui->show_results_on_screen(prepare_end_message());

		cout << endl << "Do you wish to continue? (Y/N): ";
		cin >> carryOn;

		if (tolower(carryOn) == 'y')
		{
			reset();
		}
		//TODO: Reset state of game

	} while (tolower(carryOn) == 'y');
}

string Game::prepare_grid() {
	//prepare a string that holds the grid information
	ostringstream os;
	for (int row(1); row <= SIZE; ++row)		//for each row (vertically)
	{
		for (int col(1); col <= SIZE; ++col)	//for each column (horizontally)
		{
			
			if ((row == snake_.y_) && (col == snake_.x_))
				os << snake_.symbol_;			//show snake
				else
				{
					if ((row == snake_.tail_.at(0).y_) && (col == snake_.tail_.at(0).x_))
					{
						os << snake_.tail_.at(0).get_symbol();
					}
					else {
						if ((row == mouse_.y_) && (col == mouse_.x_))
						{
							os << mouse_.symbol_;
						}
						else
						{
							if ((row == _nut.get_y() && col == _nut.get_x()) && !_nut.has_been_collected())
								os << _nut.get_symbol();
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
	for (int h_no(0); h_no < underground_.holes_.size(); ++h_no)
		if (underground_.get_hole_no(h_no).is_at_position(x, y))
			return h_no;		//number of the hole
	return -1;				//not a hole
}
void Game::apply_rules() {
	if (snake_.has_caught_mouse())
	{
		mouse_.die();
		_player.update_score_amount(-1);
	}
	else
	{
		if (mouse_.is_at_position(_nut.get_x(), _nut.get_y()))
		{
			_nut.disappears();
		}
		if (mouse_.has_reached_a_hole(underground_) && _nut.has_been_collected())
		{
			mouse_.escape_into_hole();
			_player.update_score_amount(1);
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
