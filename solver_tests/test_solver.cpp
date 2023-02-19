#include "pch.h"
#include "solver.hpp"

using namespace connect::solver;

TEST(TestSolver, Minimax1) {

	// Arrange
	Solver sut;

	std::string moves_str = "37313333717124171162542";
	std::vector<col_t> moves;
	for (const char move : moves_str)
		moves.push_back(move - '1');

	int expected = 3;
	Board board(moves);

	// Act
	auto actual = sut.minimax(board);

	// Assert
	EXPECT_EQ(expected, actual);
}

TEST(TestSolver, Minimax2) {

	// Arrange
	Solver sut;

	std::string moves_str = "12211221122137477577675665566556";
	std::vector<col_t> moves;
	for (const char move : moves_str)
		moves.push_back(move - '1');

	int expected = 4;
	Board board(moves);

	// Act
	auto actual = sut.minimax(board);

	// Assert
	EXPECT_EQ(expected, actual);
}



