#include "pch.h"
#include "solver.hpp"

using namespace connect::solver;

TEST(TestSolver, Minimax) {

	// Arrange
	Solver sut;
	Board board({ 3,3,4,4 });

	// Act
	auto score = sut.minimax(board);

	// Assert
	EXPECT_EQ(score, 17);
}



