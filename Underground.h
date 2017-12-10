// Underground.h: UserInterface for the Underground class 
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made & justification (if needed)
//---------------------------------------------------------------------
// 1.11.17   Pascale		TODO: Need to be amended for Assignment 1 [Q1 to 4 and 8]
//                          TODO: Declare class data and function members private where possible.
//                          TODO: Declare const instances, parameters and class functions (wherever possible).
//                          TODO: Create constructors with their initialisation list in same order as declaration list
//                          TODO: Place code in separate module
//                   		TODO: Check design and implementation of relationships to other classes
//                   		TODO: Follow UML design.
//							TODO: etc.
//---------------------------------------------------------------------

#if !defined(UndergroundH)
#define UndergroundH

#include <cassert>
#include <vector>
#include "Hole.h"
using namespace std;

#include "constants.h"


class Underground {
public:
	Underground();
	Hole get_hole_no(int no) const;
	void set_hole_no_at_position(int no, int x, int y);
	bool is_valid_hole_number(int n) const;
	vector<Hole> holes_;
};

#endif // !defined(UndergroundH) 
