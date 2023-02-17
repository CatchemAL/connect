#include "pch.h"

#include "board_view.hpp"


void ConsoleBoardView::Display(const Board& board) {

    /*
        0 1 2 3 4 5 6
        · · · · · · ·
        · · · · · · ·
        · O · · X · ·
        X X X X O · ·
        O O O X O · ·
        X O O O X · ·
    */

    BitBoard bitboard = board.mask;

    for (int i = 8 - 1; i >= 0; i--) {
        for (int j = 0; j < 8; j++) {
            int index = i + j * 8;
            int bit_flag = 1ull << index;
            std::cout << ((bitboard & bit_flag) ? "X " : ". ");
        }
        std::cout << std::endl;
    }
}
