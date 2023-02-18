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
			constexpr BitBoard one = 1;
			position ^= mask;
			int offset = col * (HEIGHT + 1);
			BitBoard col_bit = one << offset;
			mask |= mask + col_bit;
			++num_moves;
		}

		bool Board::is_won() {

			auto bitboard = position ^ mask;
			std::array<uint8_t, 4> directions = { HEIGHT, HEIGHT + 1, HEIGHT + 2, 1 };
			
			for (const uint8_t dir : directions) {
				BitBoard bitmask = bitboard & (bitboard >> dir);
				if (bitmask & (bitmask >> 2 * dir))
					return true;
			}
			return false;
		}
	}
}

