#pragma once
#include "pch.h"

#include "board_view.hpp"
#include "board_view_factory.hpp"

std::unique_ptr<BoardView> BoardViewFactory::Create(BoardViewType viewType) {
    switch (viewType) {
    case BoardViewType::NullView:
        return std::make_unique<NullBoardView>();
    case BoardViewType::ConsoleView:
        return std::make_unique<ConsoleBoardView>();
    default:
        throw std::invalid_argument("Unsupported board view type");
    }
}
