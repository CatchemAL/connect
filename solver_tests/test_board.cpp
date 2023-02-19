#include "pch.h"
#include "board.hpp"

using namespace connect::solver;

TEST(TestBoard, TestCreation) {

	// Arrange
	Board sut;

	// Act
	auto mask = sut.mask;
	auto position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(0, mask);
	EXPECT_EQ(0, position);
	EXPECT_EQ(0, num_moves);
}


TEST(TestBoard, TestCreationFromMoveVector) {

	// Arrange
	Board sut{ { 3, 3, 3, 4 } };

	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask = move1 | move2 | move3 | move4;
	BitBoard posn = move1 | move3;

	// Act
	auto actual_mask = sut.mask;
	auto actual_posn = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(posn, actual_posn);
	EXPECT_EQ(4, num_moves);
}

TEST(TestBoard, MakeMove) {

	// Arrange
	Board sut;
	BitBoard move = 0b0001000;

	// Act
	sut.make_move(move);
	auto mask = sut.mask;
	auto position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, move);
	EXPECT_EQ(0, position);
	EXPECT_EQ(1, num_moves);
}

TEST(TestBoard, MakeMoves) {

	// Arrange
	Board sut;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask  = move1 | move2 | move3 | move4;
	BitBoard posn  = move1 |         move3        ;

	// Act
	sut.make_move(move1);
	sut.make_move(move2);
	sut.make_move(move3);
	sut.make_move(move4);

	auto actual_mask = sut.mask;
	auto actual_position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(actual_position, posn);
	EXPECT_EQ(4, num_moves);
}

TEST(TestBoard, MakeColMoves) {

	// Arrange
	Board sut;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask = move1 | move2 | move3 | move4;
	BitBoard posn = move1 | move3;

	// Act
	sut.make_col_move(3);
	sut.make_col_move(3);
	sut.make_col_move(3);
	sut.make_col_move(4);

	auto actual_mask = sut.mask;
	auto actual_position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(actual_position, posn);
	EXPECT_EQ(4, num_moves);
}


TEST(TestBoard, IsGameWon) {

	// Arrange
	Board sut { { 3, 3, 3, 4 } };
	bool expected = false;

	// Act
	bool actual = sut.is_won();

	// Assert
	EXPECT_EQ(expected, actual);
}

