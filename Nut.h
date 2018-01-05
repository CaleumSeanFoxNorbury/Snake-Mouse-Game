#if !defined(NutH)
#define NutH

#include "MoveableGridItem.h"
#include "constants.h"

class Nut :
	public MoveableGridItem
{
public:
	
	Nut(int const  x, int const  y, char const symbol);
	bool has_been_collected() const;
	
	void disappears();
	void reappears();
private:

	bool _collected;
};
#endif
