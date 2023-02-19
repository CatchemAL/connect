#pragma once

#include <cstdint>
#include <vector>
#include <iostream>

#include "mask_utils.hpp"

namespace connect {
	namespace solver {

		using BitBoard = uint64_t;
		using col_t = uint8_t;



		class Board {
		public:

			static constexpr col_t HEIGHT = 6, WIDTH = 7, NUM_SLOTS = HEIGHT * WIDTH;

			BitBoard mask = 0, position = 0;
			uint8_t num_moves = 0;

			Board() {}

			Board(const std::vector<col_t> cols)
			{
				for (const int col : cols)
					play_col(col);
			}

			Board(BitBoard mask, BitBoard position)
				: mask(mask), position(position)
			{
			}

			bool can_play_col(col_t col) const;
			void play_col(col_t col);
			void play_move(BitBoard move);
			bool is_winning_move(col_t col) const;
			BitBoard win_mask() const;
			BitBoard possible_moves_mask() const;
			bool is_won() const;

		private:
			static constexpr BitBoard bottom_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, 0);
			static constexpr BitBoard top_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, HEIGHT - 1);
			static constexpr BitBoard padding_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, HEIGHT);
			static constexpr BitBoard board_mask = bottom_mask * ((BitBoard(1) << HEIGHT) - 1);

			static constexpr Masks<HEIGHT + 1, WIDTH> row_masks2{};
		};
	}
}