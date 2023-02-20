#include "pch.h"

#include "board.hpp"
#include "solver.hpp"

namespace connect {
	namespace solver {

		using si = std::pair<std::string, int>;

		class SolverTestSuite : public ::testing::Test {};
		class MinimaxSolverTestSuite : public ::testing::TestWithParam<si> {};

		TEST_P(MinimaxSolverTestSuite, MinimaxAlgorithm) {

			// Arrange
			Solver sut;
			const auto& [moves_str, expected] = GetParam();
			std::vector<col_t> moves;
			for (const char move : moves_str)
				moves.push_back(move - '1');

			Board board(moves);

			// Act
			auto actual = sut.minimax(board, INT_MIN + 2, INT_MAX - 1);

			// Assert
			EXPECT_EQ(expected, actual);
		}

		INSTANTIATE_TEST_CASE_P(SolverTestSuite, MinimaxSolverTestSuite, testing::Values(
			std::make_pair("5273153636415176", 5),
			std::make_pair("347436735144364224356", -3),
			std::make_pair("173535161356514575166664377", 0),
			std::make_pair("622131447544633632157215552", 1),
			std::make_pair("12211221122137477577675665566556", 4),
			std::make_pair("245436534133154164526212", -2),
			std::make_pair("512766432311321547131", 2),
			std::make_pair("662166212444136762231357153", 0)
		));
	}
}