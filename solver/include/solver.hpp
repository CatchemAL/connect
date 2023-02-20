#pragma once
#include "pch.h"

#include <cassert>

#include "board.hpp"
#include "transposition_table.hpp"

namespace connect {
	namespace solver {

		class Solver {
		public:
			
			Solver() : table_(8'388'593) {}


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

			int minimax(const Board& board, int alpha, int beta) {
				assert(alpha < beta);

				if (board.num_moves == Board::NUM_SLOTS)
					return 0;

				BitBoard win_mask = board.win_mask();
				BitBoard possible_moves = board.possible_moves_mask();
				if (win_mask & possible_moves)
					return (Board::NUM_SLOTS - board.num_moves + 1) / 2;

				int max_possible_score = (Board::NUM_SLOTS - board.num_moves - 1) / 2;
				if (const auto val = table_.get(board.key()); val != INT8_MIN) {
					assert(val <= max_possible_score); // potentially max_possible_score = std::min(max_possible_score, val); ???
					max_possible_score = val;
				}

				if (max_possible_score <= alpha)
					return max_possible_score;

				beta = std::min(beta, max_possible_score);

				for (col_t col : move_order_)
				{
					if (board.can_play_col(col)) // todo mask col with possible moves and fire that in instead
					{
						Board b(board);
						b.play_col(col);
						int score = -minimax(b, -beta, -alpha);
						alpha = std::max(alpha, score);
						if (score >= beta)
							return score;
					}
				}

				table_.put(board.key(), alpha); // save the upper bound of the position
				return alpha;
			}

		private:
			TranspositionTable table_;
			constexpr static std::array<col_t, Board::WIDTH> move_order_ = MaskUtils::create_order<Board::WIDTH>();
		};
	}
}