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

				for (col_t col = 0; col < Board::WIDTH; col++)
				{
					if (board.can_play_col(col) && board.is_winning_move(col))
					{
						return (Board::NUM_SLOTS - board.num_moves + 1) / 2;
					}
				}
				


				return 42;
			}

		};
	}
}