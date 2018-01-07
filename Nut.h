#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"
#include "RandomNumberGenerator.h"

class Nut :
	public MoveableGridItem
{
public:
	
	Nut(char symbol);
	bool has_been_collected() const;
	
	void disappears();
	void reappears();
	void position_at_random();
	static RandomNumberGenerator rng_;
private:

	bool _collected;
};
#endif
