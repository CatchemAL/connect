#pragma once

#include <cstdint>

namespace connect {
	namespace solver {

		using BitBoard = uint64_t;

		class Board {
		public:

			static constexpr uint8_t HEIGHT = 6, WIDTH = 7;

			BitBoard mask;
			BitBoard position;
			uint8_t num_moves = 0;

			Board() : Board(0, 0)
			{
			}

			Board(BitBoard mask, BitBoard position)
				: mask(mask), position(position)
			{
			}

			void make_move(BitBoard move);
			void make_col_move(int col);
			bool is_won();
		};
	}
}