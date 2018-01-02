#if !defined(NutH)
#define NutH

#include "FixedGridItem.h"

#include "constants.h"
class Nut :
	public FixedGridItem
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
