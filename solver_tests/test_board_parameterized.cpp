#include "pch.h"
#include "board.hpp"

using namespace connect::solver;

using vb = std::pair<std::vector<uint8_t>, bool>;

class ParameterisedBoardTest : public ::testing::TestWithParam<vb> {};

TEST_P(ParameterisedBoardTest, TestIsWon) {

	// Arrange
	const auto& [input, expected] = GetParam();
	Board sut = { input };

	// Act
	bool actual = sut.is_won();

	// Assert
	EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_CASE_P(BoardTestSuite, ParameterisedBoardTest, testing::Values(
	std::make_pair(std::vector<uint8_t>{}, false),
	std::make_pair(std::vector<uint8_t>{3}, false),
	std::make_pair(std::vector<uint8_t>{3, 3, 3, 4}, false),
	std::make_pair(std::vector<uint8_t>{3, 4, 3, 4, 3, 4, 3}, true),
	std::make_pair(std::vector<uint8_t>{0, 0, 1, 1, 2, 2, 3}, true),
	std::make_pair(std::vector<uint8_t>{0, 1, 1, 2, 3, 2, 2, 3, 5, 3, 3}, true),
	std::make_pair(std::vector<uint8_t>{0, 1, 1, 2, 3, 2, 2, 3, 5, 3, 4}, false),
	std::make_pair(std::vector<uint8_t>{5, 4, 4, 3, 2, 3, 3, 2, 0, 2, 2}, true),
	std::make_pair(std::vector<uint8_t>{5, 4, 4, 3, 2, 3, 3, 2, 0, 2, 1}, false)
));
