#include "pch.h"

#include "board.hpp"

namespace connect {
	namespace solver {



		void Board::make_move(BitBoard move) {
			position ^= mask;
			mask |= move;
			++num_moves;
		}

		bool Board::can_make_col_mov(col_t col) const {
			// return (mask & top_mask_col(col)) == 0;
			return true;
		}

		void Board::make_col_move(col_t col) {
			position ^= mask;
			int offset = col * (HEIGHT + 1);
			auto col_bit = BitBoard(1) << offset;
			mask |= mask + col_bit;
			++num_moves;
		}

		bool Board::is_won() const {

			constexpr std::array<uint8_t, 4> directions = { HEIGHT, HEIGHT + 1, HEIGHT + 2, 1 };
			
			auto bitboard = position ^ mask;
			for (const uint8_t dir : directions) {
				BitBoard bitmask = bitboard & (bitboard >> dir);
				if (bitmask & (bitmask >> 2 * dir))
					return true;
			}

			return false;
		}

		//   // return a bitmask containg a single 1 corresponding to the top cel of a given column
		//   static constexpr position_t top_mask_col(int col) {
		//   	return UINT64_C(1) << ((HEIGHT - 1) + col * (HEIGHT + 1));
		//   }
	}
}

