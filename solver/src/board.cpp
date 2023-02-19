#include "pch.h"

#include "board.hpp"

namespace connect {
	namespace solver {

		bool Board::can_play_col(col_t col) const {
			col_t offset = (col + 1) * (HEIGHT + 1) - 2;
			auto top_col_bit = BitBoard(1) << offset;
			return (mask & top_col_bit) == 0;
		}

		void Board::play_col(col_t col) {
			col_t offset = col * (HEIGHT + 1);
			auto col_bit = BitBoard(1) << offset;
			play_move(mask + col_bit);
		}

		void Board::play_move(BitBoard move) {
			position ^= mask;
			mask |= move;
			++num_moves;
		}

		bool Board::is_winning_move(col_t col) const {
			return true;
		}

		BitBoard Board::winning_mask(col_t col) const {
			return BitBoard(1);
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

