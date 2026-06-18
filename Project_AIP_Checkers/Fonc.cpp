/**
* \file Fonc.cpp
* Файл с описанием всех функций
**/
#include <iostream>
#include <vector>
#include "Fonc.h"

/**
* Функция вывода ошибки
* \param[in] s первое слагаемое
* \return текст ошибки 
**/
std::string err(std::string s) {
	return "ERROR: "  + s;
}

/**
* Функция вывода доски
* \param[in] desk
* \return доску
**/
std::string print_desk(std::vector <std::vector <char>> desk) {
	std::string s{ "" };
	for (int i{ 0 }; i < 9; ++i) {
		if (i == 8)
			s += "  a b c d e f g h";
		else
			for (int k{ 0 }; k < 9; ++k) {
				if (k == 0)
					s += std::to_string(8 - i) + " ";
				else {
					std::string s2(1, desk[i][k - 1]);
					s += s2 + "|";
				}
			}
		s += "\n";
	}
	return s;
}

/**
* Функция обработки атаки
* \param[in] hod ход
* \param[in] desk доска
**/
void atack(std::string hod, std::vector <std::vector <char>>& desk) {
	if ((std::tolower(desk[((8 - (hod[1] - '0')) + (8 - (hod[4] - '0'))) / 2][((hod[0] - 'a') + (hod[3] - 'a')) / 2]) == 'w' and
		std::tolower(desk[8 - (hod[1] - '0')][hod[0] - 'a']) == 'b' or
		std::tolower(desk[((8 - (hod[1] - '0')) + (8 - (hod[4] - '0'))) / 2][((hod[0] - 'a') + (hod[3] - 'a')) / 2]) == 'b' and
		std::tolower(desk[8 - (hod[1] - '0')][hod[0] - 'a']) == 'w') and
		desk[8 - (hod[4] - '0')][hod[3] - 'a'] == ' ')
	{
		desk[8 - (hod[4] - '0')][hod[3] - 'a'] = desk[8 - (hod[1] - '0')][hod[0] - 'a'];
		desk[8 - (hod[1] - '0')][hod[0] - 'a'] = ' ';
		desk[((8 - (hod[1] - '0')) + (8 - (hod[4] - '0'))) / 2][((hod[0] - 'a') + (hod[3] - 'a')) / 2] = ' ';
		if (hod[4] == '8' and desk[8 - (hod[4] - '0')][hod[3] - 'a'] == 'w') {
			desk[8 - (hod[4] - '0')][hod[3] - 'a'] = 'W';
		}
		else if (hod[4] == '1' and desk[8 - (hod[4] - '0')][hod[3] - 'a'] == 'b') {
			desk[8 - (hod[4] - '0')][hod[3] - 'a'] = 'B';
		}
	}
	else
		std::cout << err("Atack") << std::endl;
}

/**
* Функция определения шашки, которой хотят сдлать ход
* \param[in] hod ход
* \param[in] desk доска
* \return шашки, которой хотят сдлать ход
**/
char t1(std::string hod, std::vector <std::vector <char>>& desk) {
	if (desk[8 - (hod[1] - '0')][hod[0] - 'a'] == 'w')
		return 'w';
	else if (desk[8 - (hod[1] - '0')][hod[0] - 'a'] == 'W')
		return 'W';
	else if (desk[8 - (hod[1] - '0')][hod[0] - 'a'] == 'b')
		return 'b';
	else
		return 'B';
}

/**
* Функция хода
* \param[in] hod ход
* \param[in] desk доска
**/
void move(std::string hod, std::vector <std::vector <char>>& desk, bool& per) {
	if (t1(hod, desk) == 'w') {
		if ((hod[4] - '0') - (hod[1] - '0') == 1) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 1) {
				if (desk[8 - (hod[4] - '0')][hod[3] - 'a'] == ' ') {
					desk[8 - (hod[4] - '0')][hod[3] - 'a'] = desk[8 - (hod[1] - '0')][hod[0] - 'a'];
					desk[8 - (hod[1] - '0')][hod[0] - 'a'] = ' ';
					if (hod[4] == '8' and desk[8 - (hod[4] - '0')][hod[3] - 'a'] == 'w') {
						desk[8 - (hod[4] - '0')][hod[3] - 'a'] = 'W';
					}
				}
				else {
					std::cout << err("Wrong move") << std::endl;
					return;
				}
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else if (abs((hod[4] - '0') - (hod[1] - '0')) == 2) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 2) {
				if (hod.size() > 5) {
					for (int i{ 0 }; i < hod.size() - 3; i += 3) {
						std::string hod2{ "" };
						hod2 += hod[i];
						hod2 += hod[i + 1];
						hod2 += " ";
						hod2 += hod[i + 3];
						hod2 += hod[i + 4];
						move(hod2, desk, per);
					}
				}
				else {
					atack(hod, desk);
				}
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else {
			std::cout << err("Wrong move") << std::endl;
			return;
		}
	}
	else if (t1(hod, desk) == 'b') {
		if ((hod[1] - '0') - (hod[4] - '0') == 1) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 1) {
				desk[8 - (hod[4] - '0')][hod[3] - 'a'] = desk[8 - (hod[1] - '0')][hod[0] - 'a'];
				desk[8 - (hod[1] - '0')][hod[0] - 'a'] = ' ';
				if (hod[4] == '1' and desk[8 - (hod[4] - '0')][hod[3] - 'a'] == 'b') {
					desk[8 - (hod[4] - '0')][hod[3] - 'a'] = 'B';
				}
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else if (abs((hod[4] - '0') - (hod[1] - '0')) == 2) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 2) {
				if (hod.size() > 5) {
					for (int i{ 0 }; i < hod.size() - 3; i += 3) {
						std::string hod2{ "" };
						hod2 += hod[i];
						hod2 += hod[i + 1];
						hod2 += " ";
						hod2 += hod[i + 3];
						hod2 += hod[i + 4];
						move(hod2, desk, per);
					}
				}
				else {
					atack(hod, desk);
				}
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else {
			std::cout << err("Wrong move") << std::endl;
			return;
		}
	}
	else if (t1(hod, desk) == 'W') {
		if (hod.size() > 5) {
			for (int i{ 0 }; i < hod.size() - 3; i += 3) {
				std::string hod2{ "" };
				hod2 += hod[i];
				hod2 += hod[i + 1];
				hod2 += " ";
				hod2 += hod[i + 3];
				hod2 += hod[i + 4];
				move(hod2, desk, per);
			}
		}
		else if (abs((hod[4] - '0') - (hod[1] - '0')) == 1) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 1) {
				if (desk[8 - (hod[4] - '0')][hod[3] - 'a'] == ' ') {
					desk[8 - (hod[4] - '0')][hod[3] - 'a'] = desk[8 - (hod[1] - '0')][hod[0] - 'a'];
					desk[8 - (hod[1] - '0')][hod[0] - 'a'] = ' ';
				}
				else {
					std::cout << err("Wrong move") << std::endl;
					return;
				}
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else if (abs((hod[4] - '0') - (hod[1] - '0')) == 2) {
			if (abs((hod[3] - 'a') - (hod[0] - 'a')) == 2) {
				atack(hod, desk);
			}
			else {
				std::cout << err("Wrong move") << std::endl;
				return;
			}
		}
		else {
			std::cout << err("Wrong move") << std::endl;
			return;
		}
	}
	per = true;
}