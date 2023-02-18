#include "pch.h"

#include <string>
#include <sstream>

#include "board_view.hpp"




namespace connect {
    namespace solver {


        void ConsoleBoardView::Display(const Board& board) {

            std::cout << " Player1=X  Player2=O" << std::endl << std::endl;

            std::string grid = GridView(board);
            std::cout << grid << std::endl;
            int remainder = board.num_moves & 1;

            if (board.is_won())
                std::cout << " Player" << 2 - remainder << " wins!" << std::endl;
            else
                std::cout << " Player" << 1 + remainder << " to move..." << std::endl;
        }

        std::string ConsoleBoardView::GridView(const Board& board) {

            std::stringstream ss;
            constexpr BitBoard one = 1;
            BitBoard x_posn = (board.num_moves & 1) ? board.mask ^ board.position : board.position;

            for (int i = Board::HEIGHT; i >= 0; i--) {
                ss << "   ";
                for (int j = 0; j < Board::WIDTH; j++) {

                    if (i == Board::HEIGHT) {
                        ss << " " << j;
                        continue;
                    }

                    auto index = i + j * (Board::HEIGHT + 1);
                    auto bit_flag = one << index;

                    if (board.mask & bit_flag)
                        ss << (x_posn & bit_flag ? " X" : " O");
                    else
                        ss << " .";
                }
                ss << std::endl;
            }

            return ss.str();
        }

    }
}