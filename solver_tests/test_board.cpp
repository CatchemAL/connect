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

TEST(TestBoard, CanPlayMove) {

	// Arrange
	Board sut({2,2,2,2,2,2});

	// Act
	bool can0 = sut.can_play_col(0);
	bool can1 = sut.can_play_col(1);
	bool can2 = sut.can_play_col(2);
	bool can3 = sut.can_play_col(3);
	bool can4 = sut.can_play_col(4);
	bool can5 = sut.can_play_col(5);
	bool can6 = sut.can_play_col(6);

	// Assert
	EXPECT_TRUE(can0);
	EXPECT_TRUE(can1);
	EXPECT_FALSE(can2);
	EXPECT_TRUE(can3);
	EXPECT_TRUE(can4);
	EXPECT_TRUE(can5);
	EXPECT_TRUE(can6);
}

TEST(TestBoard, PlayMove) {

	// Arrange
	Board sut;
	BitBoard move = 0b0001000;

	// Act
	sut.play_move(move);
	auto mask = sut.mask;
	auto position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, move);
	EXPECT_EQ(0, position);
	EXPECT_EQ(1, num_moves);
}

TEST(TestBoard, PlayMoves) {

	// Arrange
	Board sut;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask  = move1 | move2 | move3 | move4;
	BitBoard posn  = move1 |         move3        ;

	// Act
	sut.play_move(move1);
	sut.play_move(move2);
	sut.play_move(move3);
	sut.play_move(move4);

	auto actual_mask = sut.mask;
	auto actual_position = sut.position;
	auto num_moves = sut.num_moves;

	// Assert
	EXPECT_EQ(mask, actual_mask);
	EXPECT_EQ(actual_position, posn);
	EXPECT_EQ(4, num_moves);
}

TEST(TestBoard, PlayCols) {

	// Arrange
	Board sut;
	BitBoard move1 = 0b0000001 << 3 * (Board::HEIGHT + 1);
	BitBoard move2 = 0b0000010 << 3 * (Board::HEIGHT + 1);
	BitBoard move3 = 0b0000100 << 3 * (Board::HEIGHT + 1);
	BitBoard move4 = 0b0000001 << 4 * (Board::HEIGHT + 1);

	BitBoard mask = move1 | move2 | move3 | move4;
	BitBoard posn = move1 | move3;

	// Act
	sut.play_col(3);
	sut.play_col(3);
	sut.play_col(3);
	sut.play_col(4);

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


TEST(TestBoard, WinMask) {

	// Arrange
	Board sut{ { 3, 3, 4, 4, 5, 5 } };
	BitBoard expected{ Board{ {2, 6} }.mask };

	// Act
	BitBoard actual = sut.win_mask();

	// Assert
	EXPECT_EQ(expected, actual);
}
