#pragma once
class Score
{
public:
	Score();
	int get_amount() const;
	void update_amount(const int amount);
private:
	int _amount;
};

