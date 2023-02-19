#pragma once

#include <cstdint>
#include <vector>

#include "mask_utils.hpp"

namespace connect {
	namespace solver {

		using BitBoard = uint64_t;
		using col_t = uint8_t;



		class Board {
		public:

			static constexpr col_t HEIGHT = 6, WIDTH = 7;

			BitBoard mask = 0, position = 0;
			uint8_t num_moves = 0;

			Board() {}

			Board(const std::vector<col_t> cols)
			{
				for (const int col : cols)
					make_col_move(col);
			}

			Board(BitBoard mask, BitBoard position)
				: mask(mask), position(position)
			{
			}

			bool can_make_col_mov(col_t col) const;
			void make_move(BitBoard move);
			void make_col_move(col_t col);
			bool is_won() const;

		private:
			static constexpr int bottom_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, 0);
			static constexpr int top_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, HEIGHT - 1);
			static constexpr int padding_mask = MaskUtils::create_row_mask(HEIGHT + 1, WIDTH, HEIGHT);
		};
	}
}