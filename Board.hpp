#include <string>
#include <array>
#include <vector>
#include "Direction.hpp"

namespace ariel {
    class Board {

//        uint rows;
//        uint cols;
//        char **chars;
//        std::array<std::array<char, rows>, cols> a;

    private:
        std::vector<std::vector<char>> board;

    public:
        Board();

        ~Board();

        void post(uint row, uint column, Direction direction, const std::string &massage);

        std::string read(unsigned int row, unsigned int column, Direction direction, uint length);

        void show();
    };
}