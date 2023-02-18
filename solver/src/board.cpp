#include "pch.h"

#include "board.hpp"

namespace connect {
	namespace solver {

		void Board::play(BitBoard move) {
			position ^= mask;
			mask |= move;
			++num_moves;
		}

		void Board::play_col(int col) {
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

