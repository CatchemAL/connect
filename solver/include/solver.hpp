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

				if (board.can_play_col(1))
				{

				}

				return 42;
			}

		};
	}
}