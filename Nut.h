#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"

class Nut :
	public MoveableGridItem
{
public:
	
	Nut(int  x, int  y, char symbol);
	bool has_been_collected() const;
	
	void disappears();
	void reappears();
private:

	bool _collected;
};
#endif
