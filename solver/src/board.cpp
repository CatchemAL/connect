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

		bool Board::is_won() {

			auto bitboard = position;
			std::array<uint8_t, 4> directions = { HEIGHT, HEIGHT + 1, HEIGHT + 2, 1 };
			
			for (const uint8_t dir : directions) {
				BitBoard bitmask = bitboard & (bitboard >> dir);
				if (bitmask & (bitboard >> 2 * dir))
					return true;
			}
			return false;
		}
	}
}

