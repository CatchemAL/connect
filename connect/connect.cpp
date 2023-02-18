// connect.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "board.hpp"
#include "board_view.hpp"
#include <board_view_factory.hpp>

using namespace connect::solver;


int main()
{
    BitBoard mask = 517'281'465'216, position = 137'977'922'432;
    Board board(mask, position);

    BoardViewFactory factory;
    auto view = factory.Create(BoardViewType::ConsoleView);
    view->Display(board);

    auto is_win = board.is_win();

    return 0;
}
