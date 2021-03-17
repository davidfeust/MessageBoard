/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and
 * are not complete.
 *
 * AUTHORS: David Feust
 *
 * Date: 2020-02
 */

#include "Board.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
//#include <array>

using namespace ariel;

using namespace std;

string create_word(unsigned int len);

int get_random_num(unsigned int range = 10);


/*
TEST_CASE ("just a test") {
    Board board;
            CHECK_NOTHROW(board.post(100, 200, Direction::Horizontal, "abcd"));
}
*/

TEST_CASE ("Post and read many lengths") {
    for (uint i = 1; i < 25; ++i) {
        for (int j = 0; j < 2; ++j) {
            Board board;
            string word = create_word(i);
            Direction direction = j == 0 ? Direction::Horizontal : Direction::Vertical;
            board.post(0, 0, direction, word);
//                    CHECK(board.read(0, 0, direction, i) == word);
            for (uint k = i; k >= 0; --k) {
                CHECK(board.read(0, 0, direction, k) == word.substr(0, k));
            cout << "k = " << k << " " << word.substr(0, k) << ", " << i << ", "
            << to_string(static_cast<int>(direction)) << endl;
            }

        }
    }
}
//
//
//TEST_CASE ("Post and read many positions") {
//    for (unsigned int i = 1; i < 25; ++i) {
//        for (int j = 0; j < 2; ++j) {
//            Board board;
//            int word_len = get_random_num();
//            string word = create_word(word_len);
//            Direction direction = j == 0 ? Direction::Horizontal : Direction::Vertical;
//            int r = get_random_num(100);
//            int c = get_random_num(100);
//            board.post(r, c, direction, word);
//                    CHECK(board.read(r, c, direction, word_len) == word);
//                    CHECK(board.read(r, c, direction, word_len - 1) != word);
//                    CHECK(board.read(r, c, direction, word_len + 1) != word);
//                    CHECK(board.read(r + 1, c, direction, word_len + 1) != word);
//                    CHECK(board.read(r - 1, c, direction, word_len + 1) != word);
//                    CHECK(board.read(r, c + 1, direction, word_len + 1) != word);
//                    CHECK(board.read(r, c - 1, direction, word_len + 1) != word);
//            cout << word << ", " << word_len << ", " << to_string(static_cast<int>(direction)) << ", (" << r << ", "
//                 << c << ")" << endl;
//        }
//    }
//}
//
//
//TEST_CASE ("Many Posts Together") {
//    const int size = 50;
//    Board board;
//    for (int i = 0; i < size; ++i) {
//        int len = get_random_num();
//        string message = create_word(len);
//        Direction direction = get_random_num(2) == 1 ? Direction::Horizontal : Direction::Vertical;
//        int r = get_random_num(20);
//        int c = get_random_num(20);
//        board.post(r, c, direction, message);
//                CHECK(board.read(r, c, direction, len) == message);
////        cout << message << ", " << len << ", " << to_string(static_cast<int>(direction)) << ", (" << r << ", "
////             << c << ")" << endl;
//    }
//}
//
//
//TEST_CASE ("Negative position inputs") {
//    Board board;
//    // post method
//            CHECK_THROWS(board.post(-1, 1, Direction::Vertical, create_word(3)));
//            CHECK_THROWS(board.post(-1, 1, Direction::Horizontal, create_word(3)));
//            CHECK_THROWS(board.post(1, -1, Direction::Vertical, create_word(3)));
//            CHECK_THROWS(board.post(1, -1, Direction::Horizontal, create_word(3)));
//
//    // read method
//            CHECK_THROWS(board.read(-1, 1, Direction::Vertical, 2));
//            CHECK_THROWS(board.read(-1, 1, Direction::Horizontal, 2));
//            CHECK_THROWS(board.read(1, -1, Direction::Vertical, 2));
//            CHECK_THROWS(board.read(1, -1, Direction::Horizontal, 2));
//            CHECK_THROWS(board.read(1, 1, Direction::Vertical, -1));
//            CHECK_THROWS(board.read(1, 1, Direction::Horizontal, -1));
//}

/**
 * Create a word with length of len, when the letters chooses randomly.
 * @param len length of the word.
 * @return random word, when |word| = len.
 */
string create_word(unsigned int len) {
//    srand(time(NULL));
    string ans;
    for (int i = 0; i < len; i++) {
        ans += (char) (rand() % 26) + 'a';
    }
    return ans;
}

/**
 * Returns Random number in range [1, range]
 * Default value for max range is 15.
 * @return random number
 */
int get_random_num(unsigned int range) {
//    srand(time(NULL));
    return (int) (rand() % range) + 1;
}




