#include <iostream>
#include <string>
#include "Board.hpp"

namespace ariel {

    Board::Board() : board(std::vector<std::vector<char>>()), rows(0), cols(0) {}

    Board::~Board() = default;

    void Board::post(uint row, uint column, Direction direction, const std::string &massage) {
        uint index = 0;
        unsigned long massage_len = massage.size();
        if (direction == Direction::Horizontal) {
            if (massage_len + column > cols) {
                resize_board(rows, (massage_len + column));
            }
            if (row >= rows) {
                resize_board(row + 1, cols);
            }
            while (index < massage_len) {
                board.at(row).at(column + index) = massage.at(index);
                index++;
            }
        } else { // Direction::Vertical
            if (massage_len + row > rows) {
                resize_board((massage_len + row), cols);
            }
            if (column >= cols) {
                resize_board(rows, column + 1);
            }
            while (index < massage_len) {
                board.at(row + index).at(column) = massage.at(index);
                index++;
            }
        }
    }

    std::string Board::read(uint row, uint column, Direction direction, uint length) {
        std::string ans;
        if (direction == Direction::Horizontal) {
            if (row >= rows) {
                std::string temp(length, '_');
                ans = temp;
            } else {
                for (uint i = column; i < column + length; ++i) {
                    if (i < cols) {
                        char &cell = board.at(row).at(i);
                        ans += cell != 0 ? cell : '_';
                    } else {
                        ans += '_';
                    }
                }
            }
        } else { // Direction::Vertical
            if (column >= cols) {
                std::string temp(length, '_');
                ans = temp;
            } else {
                for (uint i = row; i < row + length; ++i) {
                    if (i < rows) {
                        char &cell = board.at(i).at(column);
                        ans += cell != 0 ? cell : '_';
                    } else {
                        ans += '_';
                    }
                }
            }
        }
        return ans;
    }

    void Board::show() {
        std::cout << "(" << rows << ", " << cols << ")" << std::endl;
        for (uint i = 0; i < board.size(); ++i) {
            for (uint j = 0; j < board.at(i).size(); ++j) {
                char &cell = board.at(i).at(j);
                if (cell == 0) {
                    std::cout << '_';
                } else {
                    std::cout << cell;
                }
            }
            std::cout << std::endl;
        }
    }


    void Board::resize_board(uint new_rows, uint new_cols) {
        board.resize(new_rows);
        for (uint i = 0; i < new_rows; ++i) {
            board.at(i).resize(new_cols);
        }
        rows = new_rows;
        cols = new_cols;
    }
}
