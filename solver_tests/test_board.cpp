#include "pch.h"
#include "board.hpp"

using namespace connect::solver;

TEST(TestBoard, TestCreation) {

	// Arrange
	Board board;

	// Act
	auto mask = board.mask;
	auto position = board.position;
	auto num_moves = board.num_moves;

	// Assert
	EXPECT_EQ(0, mask);
	EXPECT_EQ(0, position);
	EXPECT_EQ(0, num_moves);
}

TEST(TestBoard, MakeMove) {

	// Arrange
	Board board;
	BitBoard move = 0b0001000;

	// Act
	board.make_move(move);
	auto mask = board.mask;
	auto position = board.position;
	auto num_moves = board.num_moves;

	// Assert
	EXPECT_EQ(mask, move);
	EXPECT_EQ(0, position);
	EXPECT_EQ(1, num_moves);
}

TEST(TestBoard, MakeMoves) {

	// Arrange
	Board board;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask  = move1 | move2 | move3 | move4;
	BitBoard posn  = move1 |         move3        ;

	// Act
	board.make_move(move1);
	board.make_move(move2);
	board.make_move(move3);
	board.make_move(move4);

	auto actual_mask = board.mask;
	auto actual_position = board.position;
	auto num_moves = board.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(actual_position, posn);
	EXPECT_EQ(4, num_moves);
}

TEST(TestBoard, MakeColMoves) {

	// Arrange
	Board board;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask  = move1 | move2 | move3 | move4;
	BitBoard posn  = move1 |         move3        ;

	// Act
	board.make_col_move(3);
	board.make_col_move(3);
	board.make_col_move(3);
	board.make_col_move(4);

	auto actual_mask = board.mask;
	auto actual_position = board.position;
	auto num_moves = board.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(actual_position, posn);
	EXPECT_EQ(4, num_moves);
}
