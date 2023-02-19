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

		BitBoard Board::win_mask() const {

			// Vertical win
			BitBoard wm = (position << 1) & (position << 2) & (position << 3);

			// Horizontals
			wm |= (position << (HEIGHT + 1)) & (position << 2 * (HEIGHT + 1)) & (position << 3 * (HEIGHT + 1));
			wm |= (position >> (HEIGHT + 1)) & (position >> 2 * (HEIGHT + 1)) & (position >> 3 * (HEIGHT + 1));

			// Diagonals
			wm |= (position << (HEIGHT + 2)) & (position << 2 * (HEIGHT + 2)) & (position << 3 * (HEIGHT + 2));
			wm |= (position >> HEIGHT) & (position >> 2 * HEIGHT) & (position >> 3 * HEIGHT);

			return wm & (board_mask ^ mask);
		}

		BitBoard Board::possible_moves_mask() const {
			return (mask + bottom_mask) & board_mask;
		}
	}
}

