#pragma once

#include <string>
#include <iostream>

#include "board.hpp"

enum class BoardViewType {
    NullView,
    ConsoleView
};

class BoardView {
public:
    virtual void Display(const Board& board) = 0;
    virtual ~BoardView() = default;
};

class ConsoleBoardView : public BoardView {
public:
    void Display(const Board& board) override;
};

class NullBoardView : public BoardView {
public:
    void Display(const Board& board) override {}
};
