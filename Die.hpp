/*********************************************************************
** Author: Ryan Peters
** Date: 09/29/15
** Description: Die class is used for rolling a die
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
	int numSides;
public:
	Die();
	Die(int);
	void setNumSides(int);
	int rollResult();
};

#endif  