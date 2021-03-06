
#include <iostream>
#include <string>
#include <algorithm>

#include "interface.hpp"
#include "board.hpp"
#include "board.hpp"
#include "search.hpp"
#include "movegenerator.hpp"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::getline;

namespace ricefish {

void play() {
    Board board;
    string input;
    while (true) {
        cout << '\n' << board << endl;

        // We query the user until she enters a legal move.
        Move m;
        MoveGenerator generator;
        auto move_list = generator.get_moves(board);
        while (!move_list.contains(m)) {
            printf("Your move:  ");
            getline(cin, input);
            try {
                cout << "the input: " << input << endl;
                char fx = input[0], fy = input[1];
                char tx = input[2], ty = input[3];
                m = {{fx - '0', fy - '0'},
                     {tx - '0', ty - '0'}};
            } catch (const std::out_of_range &err) {
                printf("Input a move like 3 for top right (or type q to quit)\n");
            }
        }
        cout << "Parsed: " << m << endl;
        board.make_move(m);

        if (board.get_winner() != Pebble::NO_PEBBLE) {
            printf("You win!\n");
            break;
        }

        std::cout << '\n' << board << std::endl;


//        SearchResult result = search(board, 5);
//        cout << "My move: " << result.move << endl;
//        board.make_move(result.move);

        if (board.get_winner() != Pebble::NO_PEBBLE) {
            printf("I win!\n");
            break;
        }
    }
}

void self_play(Board& board) {
    cout << board << endl;
    do {
//        SearchResult result = search(board);
//        board.make_move(result.move);
//        cout << board << "\nScore: " << board.score_absolute(result.score) << endl;
    } while (board.get_winner() == Pebble::NO_PEBBLE);
    printf("Player %c wins!\n", Pebbles::get_char(board.get_winner()));
}

}
