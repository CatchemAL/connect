#pragma once

#include <cstdint>

using BitBoard = uint64_t;

class Board {
public:
	BitBoard mask;
	BitBoard position;
	uint8_t num_moves;

	Board(BitBoard mask, BitBoard position)
		: mask(mask), position(position), num_moves(0)
	{
	}

	bool is_win();
};