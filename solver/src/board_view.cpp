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
    constexpr uint8_t HEIGHT = 6, WIDTH = 7;

    BitBoard bitboard = board.mask;

    for (int i = HEIGHT - 1; i >= 0; i--) {
        for (int j = 0; j < WIDTH; j++) {
            auto index = i + j * (HEIGHT + 1);
            auto bit_flag = 1ull << index;
            std::cout << ((bitboard & bit_flag) ? " X" : " .");
        }
        std::cout << std::endl;
    }
}
