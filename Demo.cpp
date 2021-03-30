/**
 * Demo program for message-board exercise.
 *
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>

using ariel::Direction;
using namespace std;


int main() {



//    for (uint i = 0; i < board.size(); ++i) {
//        for (uint j = 0; j < board.at(i).size(); ++j) {
//            std::cout << board.at(i).at(j);
//        }
//    }

    ariel::Board board;
//    board.post(0,3,Direction::Horizontal, "abcdefgh");
//    board.post(2,0,Direction::Horizontal, "abcde");
//    board.post(4,0,Direction::Horizontal, "abcdef");
//    board.post(1,3,Direction::Horizontal, "abc");
//    board.post(3,8,Direction::Horizontal, "abc");
//    board.post(0,7,Direction::Vertical, "abcdefgh");
//    board.show();


    board.post(/*row=*/10, /*column=*/20, Direction::Horizontal, "abcd");
    cout << board.read(/*row=*/99, /*column=*/201, Direction::Vertical,
                       /*length=*/3)
         << endl;
//    // prints "_b_" (starts at row 99 which is empty; then at row 100 there is
//    // "b"; then row 101 is empty again).
//    board.post(/*row=*/99, /*column=*/202, Direction::Vertical, "xyz");
//    cout << board.read(/*row=*/100, /*column=*/200, Direction::Horizontal,
//                       /*length=*/6)
//         << endl;
//    // prints "abyd__" (First letters are ab; then y from the "xyz"; then d;
//    // then two empty cells).
//
    board.show();  // shows the board in a reasonable way. For example:
                   //    98:  _________
                   //    99:  ____x____
                   //    100: __abyd___
                   //    101: ____z____
                   //    102: _________
}
