#include <iostream>
#include <string>
#include "Board.hpp"

namespace ariel {

    Board::Board() : board(std::vector<std::vector<char>>('_')) {}

    Board::~Board() {
//        delete board;
//        for (int i = 0; i < board.size(); ++i) {
//            delete board.at(i).;
//        }
    }

    void Board::post(uint row, uint column, Direction direction, const std::string &massage) {
        uint index = 0;
        if (direction == Direction::Horizontal) {
            while (index < massage.size()) {
                board.at(row).at(column + index) = massage.at(index++);
            }
        } else {
            while (index < massage.size()) {
                board.at(row + index).at(column) = massage.at(index++);
            }
        }
    }

    std::string Board::read(uint row, uint column, Direction direction, uint length) {
        return "";
    }

    void Board::show() {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.at(i).size(); ++j) {
                std::cout << board.at(i).at(j);
            }
        }
    }
}
