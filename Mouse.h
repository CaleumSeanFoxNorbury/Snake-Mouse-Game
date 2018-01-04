// Mouse.h: UserInterface for the Mouse class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(MouseH)
#define MouseH

#include "constants.h"
#include "Underground.h"
#include "MoveableGridItem.h"

class Mouse:
			public MoveableGridItem
{
	public:
		//constructor
		Mouse::Mouse(char const);
		//assessors

		bool is_alive() const;
		bool has_escaped() const;
		bool has_reached_a_hole(Underground ug);
		//mutators
		void die();
		void escape_into_hole();
		void scamper(char k);
		void reset();

	private:
		//data members
		bool alive_;
		bool escaped_;
		int mouse_dx_;
		int mouse_dy_; 
		//supporting functions 
		int position_in_middle_of_grid();

};

#endif // !defined(MouseH)
