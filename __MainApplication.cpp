//--------------------------------
//include standard libraries
#include <iostream>		//for output and input
#include <string>		//for string
#include <sstream>		//for streamstring
using namespace std;

//include class modules
#include "Game.h"
#include "Mouse.h"
#include "Snake.h"
#include "Underground.h"
#include "UserInterface.h"

//using OO approach
//---------------------------------
UserInterface ui;

int main()
{

	string name;
	cout << "Enter your name: ";
	cin >> name;

	Player player(name);

	char carry_on;

	do
	{
		Game game(&player);
		game.set_up(&ui);
		game.run();

		cout << "Play again? (Y/N): ";
		cin >> carry_on;

	} while (tolower(carry_on) == 'y');

	ui.hold_window();
	return 0;
}