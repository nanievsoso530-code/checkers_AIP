/**
* \file main.cpp
* Главный файл программы
**/
#include <iostream>
#include <vector>
#include <string>
#include "Fonc.h"

char turn{ 'w' };

std::vector <std::vector <char>> deskIn{
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
	{' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
};

std::vector <std::vector <char>> desk{
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
	{' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
};

int main()
{
	std::cout << "Hello, this is a game of checkers, all the rules are like in a normal game, write down when you hand over - surrender \nWrite your names(W B):";
	std::string name1, name2;
	int sch1{ 0 }, sch2{ 0 };
	getline(std::cin, name1);
	getline(std::cin, name2);
	std::cout << print_desk(desk);
	bool per{false};
	while (true) {
		if (turn == 'w')
			std::cout << "Now move: " << name1 << std::endl;
		else
			std::cout << "Now move: " << name2 << std::endl;
		std::string hod;
		getline(std::cin, hod);
		if (hod == "surrender") {
			if (turn == 'w') {
				std::cout << "Won: " << name1 << std::endl;;
				sch1++;
			}
			else {
				std::cout << "Won: " << name2 << std::endl;
				sch2++;
			}
			std::cout << "The score is now " << sch1 << " " << sch2 << std::endl;
			desk = deskIn;
			turn = 'w';
			continue;
		}
		else if (hod.size() < 2) {
			std::cout << err("Wrong move") << std::endl;
		}
		else if (std::tolower(desk[8 - (hod[1] - '0')][hod[0] - 'a']) == turn) {
			move(hod, desk, per);
		}
		else {
			std::cout << err("Move order") << std::endl;
		}
		if (per == true) {
			if (turn == 'w' or turn == 'W')
				turn = 'b';
			else
				turn = 'w';
			per = false;
		}
		std::cout << print_desk(desk);
	}
}