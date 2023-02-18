#include "pch.h"

#include "board.hpp"

namespace connect {
	namespace solver {

		void Board::make_move(BitBoard move) {
			position ^= mask;
			mask |= move;
			++num_moves;
		}

		void Board::make_col_move(int col) {
			position ^= mask;
			int offset = col * (HEIGHT + 1);
			int col_bit = 1 << offset;
			mask |= mask + col_bit;
			++num_moves;
		}

		bool Board::is_win() {
			return true;
		}
	}
}

