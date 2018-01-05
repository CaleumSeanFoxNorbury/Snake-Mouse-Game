#if !defined(PlayerH)
#define PlayerH

#include <string>

#include "Score.h"

using namespace std;

class Player
{
public:
	Player(const string);
	string get_name() const;
	int get_score_amount() const;
	void update_score_amount(const int);
private:
	const string _name;
	Score _score;
};

#endif
