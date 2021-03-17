#include <string>
#include "Direction.hpp"

namespace ariel {
    class Board {
        char **chars;
        uint rows;
        uint cols;
    public:
        Board();

        ~Board();

        void post(uint row, uint column, Direction direction, std::string message);

        std::string read(unsigned int row, unsigned int column, Direction direction, uint length);

        void show();
    };
}