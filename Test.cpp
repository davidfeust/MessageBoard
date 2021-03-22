/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * AUTHORS: David Feust
 *
 * Date: 2020-02
 */

#include "Board.hpp"
#include "doctest.h"
#include <iostream>
#include <string>
#include <random>
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
            for (uint k = i; k > 0; --k) {
                        CHECK(board.read(0, 0, direction, k) == word.substr(0, k));
//            cout << "k = " << k << " " << word.substr(0, k) << ", " << i << ", "
//            << to_string(static_cast<int>(direction)) << endl;
            }
        }
    }
}


TEST_CASE ("Post and read many positions") {
    for (unsigned int i = 1; i < 25; ++i) {
        for (int j = 0; j < 2; ++j) {
            Board board;
            int word_len = get_random_num();
            string word = create_word(word_len);
            Direction direction = j == 0 ? Direction::Horizontal : Direction::Vertical;
            int r = get_random_num(100);
            int c = get_random_num(100);
            board.post(r, c, direction, word);
                    CHECK(board.read(r, c, direction, word_len) == word);
                    CHECK(board.read(r, c, direction, word_len - 1) != word);
                    CHECK(board.read(r, c, direction, word_len + 1) != word);
                    CHECK(board.read(r + 1, c, direction, word_len + 1) != word);
                    CHECK(board.read(r - 1, c, direction, word_len + 1) != word);
                    CHECK(board.read(r, c + 1, direction, word_len + 1) != word);
                    CHECK(board.read(r, c - 1, direction, word_len + 1) != word);
//            cout << word << ", " << word_len << ", " << to_string(static_cast<int>(direction)) << ", (" << r << ", "
//                 << c << ")" << endl;
        }
    }
}


TEST_CASE ("Many Posts Together") {
    const int size = 50;
    Board board;
    for (int i = 0; i < size; ++i) {
        int len = get_random_num();
        string message = create_word(len);
        Direction direction = get_random_num(2) == 1 ? Direction::Horizontal : Direction::Vertical;
        int r = get_random_num(20);
        int c = get_random_num(20);
        board.post(r, c, direction, message);
                CHECK(board.read(r, c, direction, len) == message);
//        cout << message << ", " << len << ", " << to_string(static_cast<int>(direction)) << ", (" << r << ", "
//             << c << ")" << endl;
    }
}

TEST_CASE ("Empty message board") {
    Board board;
    for (int i = 0; i < 50; ++i) {
        Direction direction = get_random_num(2) == 1 ? Direction::Horizontal : Direction::Vertical;
        uint len = get_random_num(15);
        string empty_word;
        for (int j = 0; j < len; ++j) {
            empty_word.append("_");
        }
        CHECK(board.read(i, i * 2, direction, len) == empty_word);
    }
}

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




