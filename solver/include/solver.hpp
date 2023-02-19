#pragma once
#include "pch.h"

#include "board.hpp"

namespace connect {
	namespace solver {

		class Solver {
		public:

			static int minimax(const Board& board) {

				if (board.num_moves == Board::NUM_SLOTS) 
					return 0;

				BitBoard win_mask = board.win_mask();
				BitBoard possible_moves = board.possible_moves_mask();

				if (win_mask & possible_moves)
					return (Board::NUM_SLOTS - board.num_moves + 1) / 2;

				int score = INT_MIN;
				for (col_t col = 0; col < Board::WIDTH; ++col)
				{
					if (board.can_play_col(col)) // todo mask col with possible moves and fire that in instead
					{
						Board b(board);
						b.play_col(col);
						int opponent_score = minimax(b);
						score = std::max(score, -opponent_score);
					}
				}

				return score;
			}
		};
	}
}