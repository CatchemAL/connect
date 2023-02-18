#include "pch.h"

#include <string>
#include <sstream>

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
    std::cout << " Player1=X  Player2=O" << std::endl << std::endl;

    std::string grid = GridView(board);
    std::cout << grid << std::endl;
    int num = 1 + (board.num_moves & 1);
    std::cout << "Player" << num << " to move..." << std::endl;
}

std::string ConsoleBoardView::GridView(const Board& board) {

    std::stringstream ss;

    for (int i = Board::HEIGHT - 1; i >= 0; i--) {
        ss << "   ";
        for (int j = 0; j < Board::WIDTH; j++) {
            auto index = i + j * (Board::HEIGHT + 1);
            auto bit_flag = 1ull << index;

            if (board.mask & bit_flag)
                if ((board.num_moves & 1) ^ (board.position & bit_flag))
                    ss << " X";
                else
                    ss << " O";
            else
                ss << " .";
        }
        ss << std::endl;
    }

    return ss.str();
}

