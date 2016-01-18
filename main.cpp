/********************************************************************
** Author: Ryan Peters
** Date: 11/07/15
** Description: Main function is used to choose the combatants. 
**    Battle function executes the fight until one combatant loses.
********************************************************************/
#include "Tournament.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <limits>

/********************************************************************
** Description: Has do..while loops for choosing the combatants
********************************************************************/	
int main()
{
	std::vector<Creature*> team1Creature;
	std::vector<Creature*> team2Creature;
	Tournament tournament;
	int numFighters;
	bool validNumFighters;
	char fighter;
	char displayFullList;
	int fight = 1;
	
	srand(time(NULL));
	
	std::cout << "Creature Combat" << std::endl;
	/*Get Number Of Fighters*/
	do
	{
		std::cout << "Enter the number of fighters: ";
		std::cin >> numFighters;

		if (std::cin.good() && numFighters > 0)
		{
			tournament.setNumberFighters(numFighters);
			validNumFighters = true;
		}
		else
		{
			std::cout << "Invalid input.  Please enter a positive integer." << std::endl;
			validNumFighters = false;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!validNumFighters);
	
	/*Create Teams*/
	/*Team 1*/
	for (int i = 0; i < numFighters; i++)
	{
		do
		{
			std::cout << "Choose the fighter for team 1." << std::endl;
			std::cout << "1) Goblin" << std::endl;
			std::cout << "2) Barbarian" << std::endl;
			std::cout << "3) Reptile People" << std::endl;
			std::cout << "4) Blue Men" << std::endl;
			std::cout << "5) The Shadow" << std::endl;
			std::cin >> fighter;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (fighter != '1' && fighter != '2' && fighter != '3'
				&& fighter != '4' && fighter != '5')
			{
				std::cout << "Invalid Choice. Choose 1 - 5" << std::endl;
			}

		} while (fighter != '1' && fighter != '2' && fighter != '3'
			&& fighter != '4' && fighter != '5');

		if (fighter == '1')
		{
			team1Creature.push_back(new Goblin("Team 1"));
			tournament.addFighterTeam1(team1Creature.at(i));
		}
		else if (fighter == '2')
		{
			team1Creature.push_back(new Barbarian("Team 1"));
			tournament.addFighterTeam1(team1Creature.at(i));
		}
		else if (fighter == '3')
		{
			team1Creature.push_back(new Reptile("Team 1"));
			tournament.addFighterTeam1(team1Creature.at(i));
		}
		else if (fighter == '4')
		{
			team1Creature.push_back(new Bluemen("Team 1"));
			tournament.addFighterTeam1(team1Creature.at(i));
		}
		else if (fighter == '5')
		{
			team1Creature.push_back(new Shadow("Team 1"));
			tournament.addFighterTeam1(team1Creature.at(i));
		}
	}
	/*Team 2*/
	for (int i = 0; i < numFighters; i++)
	{
		do
		{
			std::cout << "Choose the fighter for team 2." << std::endl;
			std::cout << "1) Goblin" << std::endl;
			std::cout << "2) Barbarian" << std::endl;
			std::cout << "3) Reptile People" << std::endl;
			std::cout << "4) Blue Men" << std::endl;
			std::cout << "5) The Shadow" << std::endl;
			std::cin >> fighter;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (fighter != '1' && fighter != '2' && fighter != '3'
				&& fighter != '4' && fighter != '5')
			{
				std::cout << "Invalid Choice. Choose 1 - 5" << std::endl;
			}

		} while (fighter != '1' && fighter != '2' && fighter != '3'
			&& fighter != '4' && fighter != '5');

		if (fighter == '1')
		{
			team2Creature.push_back(new Goblin("Team 2"));
			tournament.addFighterTeam2(team2Creature.at(i));
		}
		else if (fighter == '2')
		{
			team2Creature.push_back(new Barbarian("Team 2"));
			tournament.addFighterTeam2(team2Creature.at(i));
		}
		else if (fighter == '3')
		{
			team2Creature.push_back(new Reptile("Team 2"));
			tournament.addFighterTeam2(team2Creature.at(i));
		}
		else if (fighter == '4')
		{
			team2Creature.push_back(new Bluemen("Team 2"));
			tournament.addFighterTeam2(team2Creature.at(i));
		}
		else if (fighter == '5')
		{
			team2Creature.push_back(new Shadow("Team 2"));
			tournament.addFighterTeam2(team2Creature.at(i));
		}
	}
	/*End Create Team*/
	
	/*Execute Tournament*/
	while (!tournament.checkEnd())
	{
		std::cout << "Fight " << fight++ << std::endl;
		std::cout << "+------------------------------+" << std::endl;
		tournament.battle(tournament.getFighterTeam1(), tournament.getFighterTeam2());
		std::cout << "Press ENTER to continue..." << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/*Display Resuts*/
	std::cout << "Do you want to display the full list of fighters? (y or n)" << std::endl;
	do
	{
		std::cin >> displayFullList;

		if (displayFullList != 'y' && displayFullList != 'n')
		{
			std::cout << "Invalid Input. Please enter y or n" << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (displayFullList != 'y' && displayFullList != 'n');
	std::cout << tournament.endGame() << " Wins" << std::endl;
	if (displayFullList == 'y')
	{
		tournament.displayResults(true);
	}
	else if (displayFullList == 'n')
	{
		tournament.displayResults(false);
	}

	for (int i = 0; i < numFighters; i++)
	{
		delete team1Creature.at(i);
		delete team2Creature.at(i);
	}

	return 0;
}

