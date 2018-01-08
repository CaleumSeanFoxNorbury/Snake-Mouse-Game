// Score.h: UserInterface for the Score class
//////////////////////////////////////////////////////////////////////
#if !defined(ScoreH)
#define ScoreH

class Score
{
public:
	//constructor
	Score();
	//assessors
	int get_amount() const;
	//mutators
	void update_amount(const int amount);

private:
	//data members
	int _amount;
	//supporting functions
};
#endif // !defined(ScoreH)
