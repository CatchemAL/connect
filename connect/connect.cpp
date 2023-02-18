// connect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "board.hpp"
#include "board_view.hpp"
#include "board_view_factory.hpp"

using namespace connect::solver;


int main()
{
    Board board{ {0, 1, 1, 2, 3, 2, 2, 3, 5, 3, 3} };

    BoardViewFactory factory;
    auto view = factory.Create(BoardViewType::ConsoleView);
    view->Display(board);

    auto is_win = board.is_won();

    return 0;
}
