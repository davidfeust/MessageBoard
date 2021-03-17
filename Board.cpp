#include "Board.hpp"

namespace ariel {

    Board::Board() : rows(0), cols(0), chars(nullptr) {}

    Board::~Board() {
        delete chars;
    }

    void Board::post(uint row, uint column, Direction direction, std::string message) {

    }

    std::string Board::read(uint row, uint column, Direction direction, uint length) {
        return "";
    }

    void Board::show() {

    }
}
