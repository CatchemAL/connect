#pragma once

#include <cstdint>

using BitBoard = uint64_t;

class Board {
public:

	static constexpr uint8_t HEIGHT = 6, WIDTH = 7;

	BitBoard mask;
	BitBoard position;
	uint8_t num_moves;

	Board(BitBoard mask, BitBoard position)
		: mask(mask), position(position), num_moves(0)
	{
	}

	void play(BitBoard move);
	void play_col(int col);
	bool is_win();
};