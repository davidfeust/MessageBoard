#include <string>
#include <array>
#include <vector>
#include "Direction.hpp"

namespace ariel {
    class Board {

//        std::array<std::array<char, rows>, cols> a;
//        char **chars;

    private:
        std::vector<std::vector<char>> board;
        uint rows;
        uint cols;

        void resize_board(uint new_rows, uint new_cols);


    public:
        Board();

        ~Board();

        void post(uint row, uint column, Direction direction, const std::string &massage);

        std::string read(unsigned int row, unsigned int column, Direction direction, uint length);

        void show();

    };
}