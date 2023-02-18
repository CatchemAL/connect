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

			auto bitboard = position;
			uint8_t h1 = HEIGHT + 0, h2 = HEIGHT + 1, h3 = HEIGHT + 2, h4 = 1;

			if (bitboard & (bitboard >> h1) & (bitboard >> 2 * h1) & (bitboard >> 3 * h1))
				return true;
			if (bitboard & (bitboard >> h2) & (bitboard >> 2 * h2) & (bitboard >> 3 * h2))
				return true;
			if (bitboard & (bitboard >> h3) & (bitboard >> 2 * h3) & (bitboard >> 3 * h3)) 
				return true;
			if (bitboard & (bitboard >> h4) & (bitboard >> 2 * h4) & (bitboard >> 3 * h4))
				return true;

			return false;
		}
	}
}

