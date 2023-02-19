#include "pch.h"
#include "board.hpp"

namespace connect {
	namespace solver {

		using vb = std::pair<std::vector<uint8_t>, bool>;
		using vv = std::pair<std::vector<uint8_t>, std::vector<uint8_t>>;

		class BoardTestSuite : public ::testing::Test {};
		class IsWonBoardTestSuite : public ::testing::TestWithParam<vb> {};
		class WinMaskBoardTestSuite : public ::testing::TestWithParam<vv> {};

		TEST_P(IsWonBoardTestSuite, TestIsWon) {

			// Arrange
			const auto& [input, expected] = GetParam();
			Board sut = { input };

			// Act
			bool actual = sut.is_won();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		INSTANTIATE_TEST_CASE_P(BoardTestSuite, IsWonBoardTestSuite, testing::Values(
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

		static constexpr BitBoard ONE(1);
		static constexpr col_t H1(Board::HEIGHT + 1);

		TEST_P(WinMaskBoardTestSuite, TestWinMask) {

			// Arrange
			const auto& [input, expected_vec] = GetParam();
			BitBoard expected(0);
			for (const uint8_t exp : expected_vec)
				expected |= ONE << exp;

			Board sut = { input };

			// Act
			BitBoard actual = sut.win_mask();

			// Assert
			EXPECT_EQ(actual, expected);
		}

		INSTANTIATE_TEST_CASE_P(BoardTestSuite, WinMaskBoardTestSuite, testing::Values(
			std::make_pair(std::vector<uint8_t>{3, 3, 4, 4, 5, 5   },                std::vector<uint8_t>{ 2 * H1, 6 * H1 }),
			std::make_pair(std::vector<uint8_t>{3, 3, 4, 4, 6, 6   },                std::vector<uint8_t>{ 5 * H1 }),
			std::make_pair(std::vector<uint8_t>{3, 3, 5, 5, 6, 6   },                std::vector<uint8_t>{ 4 * H1 }),
			std::make_pair(std::vector<uint8_t>{3, 4, 3, 4, 3, 4   },                std::vector<uint8_t>{ 3 * H1 + 3}),
			std::make_pair(std::vector<uint8_t>{3, 4, 3, 4, 2, 4   },                std::vector<uint8_t>{}),
			std::make_pair(std::vector<uint8_t>{3, 4, 3, 4, 2, 4, 3},                std::vector<uint8_t>{H1 * 4 + 3}),
			std::make_pair(std::vector<uint8_t>{3                  },                std::vector<uint8_t>{}),
			std::make_pair(std::vector<uint8_t>{3, 3, 3, 4         },                std::vector<uint8_t>{}),
			std::make_pair(std::vector<uint8_t>{0, 0, 1, 1, 2, 2, 3},                std::vector<uint8_t>{H1 * 3 + 1}),
			std::make_pair(std::vector<uint8_t>{2, 3, 4, 2, 3, 4, 2, 3, 4, 2},       std::vector<uint8_t>{H1 + 3, H1 * 5 + 3}),
			std::make_pair(std::vector<uint8_t>{2, 6, 3, 2, 4, 4, 3, 3, 6, 2, 6, 4}, std::vector<uint8_t>{H1, H1 * 5}),
			std::make_pair(std::vector<uint8_t>{2, 2, 3, 6, 4, 4, 3, 3, 2, 6, 4, 6}, std::vector<uint8_t>{H1, H1 + 3, H1 * 5, H1 * 5 + 3}),
			std::make_pair(std::vector<uint8_t>{2, 2, 3, 6, 4, 4, 3, 3, 2, 6, 4, 5}, std::vector<uint8_t>{H1, H1 + 3, H1 * 5 + 3}),
			std::make_pair(std::vector<uint8_t>{2, 3, 4, 4, 4, 5, 5, 5, 5, 6},       std::vector<uint8_t>{H1 * 3 + 1}),
			std::make_pair(std::vector<uint8_t>{2, 3, 3, 5, 5, 5, 5, 6},             std::vector<uint8_t>{H1 * 4 + 2}),
			std::make_pair(std::vector<uint8_t>{5, 4, 3, 3, 3, 2, 2, 2, 2, 1},       std::vector<uint8_t>{H1 * 4 + 1}),
			std::make_pair(std::vector<uint8_t>{4, 3, 3, 1, 1, 1, 1, 0},             std::vector<uint8_t>{H1 * 2 + 2})
		));
	}
}
