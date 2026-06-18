/**
* \file Test.cpp
* Файл с тестами
**/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Fonc.h"
#include "Fonc.cpp"
#include "doctest.h"

std::vector <std::vector <char>> deskT{
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
	{' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
	{' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
	{'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '}
};

TEST_CASE("Turn_of_thr_move_1") {
	CHECK(t1("a3 b4", deskT) == 'w');
}

TEST_CASE("Turn_of_thr_move_2") {
	CHECK(t1("b6 a5", deskT) == 'b');
}

TEST_CASE("ERROR_1_T") {
	CHECK(err("Atack") == "ERROR: Atack");
}

TEST_CASE("ERROR_2_T") {
	CHECK(err("Wrong move") == "ERROR: Wrong move");
}

std::string sd{ "8  |b| |b| |b| |b|\n7 b| |b| |b| |b| |\n6  |b| |b| |b| |b|\n5  | | | | | | | |\n4  | | | | | | | |\n3 w| |w| |w| |w| |\n2  |w| |w| |w| |w|\n1 w| |w| |w| |w| |\n  a b c d e f g h\n" };

TEST_CASE("Print_desk") {
	CHECK(print_desk(deskT) == sd);
}