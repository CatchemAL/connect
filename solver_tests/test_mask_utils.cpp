#include "pch.h"
#include "board.hpp"

using namespace connect::solver;

using iib = std::tuple<col_t, col_t, col_t, BitBoard>;

class MaskUtilsTest : public ::testing::TestWithParam<iib> {};

TEST_P(MaskUtilsTest, TestCase) {

	// Arrange
	const auto& [height, width, offset, expected] = GetParam();

	// Act
	auto actual = MaskUtils::create_row_mask(height, width, offset);

	// Assert
	EXPECT_EQ(expected, actual);
}

INSTANTIATE_TEST_CASE_P(MaskUtilsTestSuite, MaskUtilsTest, testing::Values(
	std::make_tuple(3, 7, 0, 299593 << 0),
	std::make_tuple(3, 7, 1, 299593 << 1),
	std::make_tuple(3, 7, 2, 299593 << 2),
	std::make_tuple(7, 7, 0, 4432676798593 << 0),
	std::make_tuple(7, 7, 5, 4432676798593 << 5),
	std::make_tuple(7, 7, 6, 4432676798593 << 6)
));

