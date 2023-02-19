// connect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "board.hpp"
#include "board_view.hpp"
#include "board_view_factory.hpp"

using namespace connect::solver;


int get_column() {
    int col;
    while (true) {
        std::cout << "Enter a number between 0-6: ";
        std::cin >> col;

        if (col >= 0 && col <= 6) {
            break;
        }
        else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
    return col;
}

int main()
{
    Board board;

    BoardViewFactory factory;
    auto view = factory.Create(BoardViewType::ConsoleView);

    for (;;)
    {
        view->Display(board);
        if (board.is_won()) break;

        int col = get_column();
        board.play_col(col);
    }
}

