#pragma once

#include "board.hpp"
#include "board_view.hpp"


class BoardViewFactory {
public:
    std::unique_ptr<BoardView> Create(BoardViewType viewType);
};
