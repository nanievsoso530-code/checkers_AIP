/**
* \file Fonc.h
* Заголовочный файл программы
**/
#ifndef FOC
#define FOC
#include <iostream>
#include <vector>

/**
* Функция вывода доски
* \param[in] desk
* \return доску
**/
std::string print_desk(std::vector <std::vector <char>> desk);

/**
* Функция обработки атаки
* \param[in] hod ход
* \param[in] desk доска
**/
void atack(std::string hod, std::vector <std::vector <char>>& desk);

/**
* Функция хода
* \param[in] hod ход
* \param[in] desk доска
**/
void move(std::string hod, std::vector <std::vector <char>>& desk, bool& per);

/**
* Функция определения шашки, которой хотят сдлать ход
* \param[in] hod ход
* \param[in] desk доска
* \return шашки, которой хотят сдлать ход
**/
char t1(std::string hod, std::vector <std::vector <char>>& desk);

/**
* Функция вывода ошибки
* \param[in] s первое слагаемое
* \return текст ошибки
**/
std::string err(std::string s);
#endif