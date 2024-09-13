#include <gtest/gtest.h>
#include "TicTacToe.hpp"

// create board test
TEST(TicTacToe_test, create_board_test) {
    TicTacToe game1;
    ASSERT_EQ(game1.get_board_size(), 3);
    for (size_t i = 0; i < game1.get_board_size(); ++i) {
        for (size_t j = 0; j < game1.get_board_size(); ++j) {
            ASSERT_EQ(game1[i][j], '-');
        }
    }
}

// is_move_valid test
TEST(TicTacToe_test, is_move_valid_test) {
    TicTacToe game2;
    ASSERT_EQ(game2.is_move_valid(0, 0), true);
    ASSERT_EQ(game2.is_move_valid(3, 3), false);
    ASSERT_EQ(game2.is_move_valid(-1, 0), false);
    ASSERT_EQ(game2.is_move_valid(0, -1), false);
}

// make_move test
TEST(TicTacToe_test, make_move_test) {
    TicTacToe game3;
    char player = 'X';
    ASSERT_EQ(game3.make_move(0, 0, player), true);
    ASSERT_EQ(game3[0][0], 'X');
    ASSERT_EQ(game3.make_move(0, 0, player), false);
}

// check_winner test
TEST(TicTacToe_test, check_winner_test) {
    TicTacToe game4;
    char player = 'X';
    game4.make_move(0, 0, player);
    game4.make_move(0, 1, player);
    game4.make_move(0, 2, player);
    ASSERT_EQ(game4.check_winner(player), true);

    TicTacToe game5;
    game5.make_move(0, 0, player);
    game5.make_move(1, 1, player);
    game5.make_move(2, 2, player);
    ASSERT_EQ(game5.check_winner(player), true);

    TicTacToe game6;
    game6.make_move(0, 2, player);
    game6.make_move(1, 1, player);
    game6.make_move(2, 0, player);
    ASSERT_EQ(game6.check_winner(player), true);

    TicTacToe game7;
    game7.make_move(0, 0, player);
    game7.make_move(1, 0, player);
    game7.make_move(2, 0, player);
    ASSERT_EQ(game7.check_winner(player), true);
}

// moves_count test
TEST(TicTacToe_test, moves_count_test) {
    TicTacToe game8;
    char player = 'X';
    game8.make_move(0, 0, player);
    game8.make_move(1, 1, player);
    ASSERT_EQ(game8.moves_count(), 2);
}

TEST(TicTacToe_test, different_board_size) {
    TicTacToe game9;
    game9.create_board(5);
    ASSERT_EQ(game9.get_board_size(), 5);
    for (size_t i = 0; i < game9.get_board_size(); ++i) {
        for (size_t j = 0; j < game9.get_board_size(); ++j) {
            ASSERT_EQ(game9[i][j], '-');
        }
    }
}

TEST(TicTacToe_test, different_board_size_check_winner) {
    TicTacToe game10;
    char player = 'X';
    game10.create_board(5);
    game10.make_move(0, 0, player);
    game10.make_move(0, 1, player);
    game10.make_move(0, 2, player);
    game10.make_move(0, 3, player);
    game10.make_move(0, 4, player);
    ASSERT_EQ(game10.check_winner(player), true);
}

TEST(TicTacToe_test, different_board_size_moves_count) {
    TicTacToe game11;
    char player = 'X';
    game11.create_board(5);
    game11.make_move(0, 0, player);
    game11.make_move(1, 1, player);
    game11.make_move(2, 2, player);
    game11.make_move(3, 3, player);
    game11.make_move(4, 4, player);
    ASSERT_EQ(game11.moves_count(), 5);
}

TEST(TicTacToe_test, draw_end_test) {
    TicTacToe game12;
    char playerx = 'X';
    char playero = 'O';
    game12.create_board(3);
    game12.make_move(0, 0, playero);
    game12.make_move(0, 1, playerx);
    game12.make_move(0, 2, playerx);
    game12.make_move(1, 0, playerx);
    game12.make_move(1, 1, playerx);
    game12.make_move(1, 2, playero);
    game12.make_move(2, 0, playero);
    game12.make_move(2, 1, playero);
    game12.make_move(2, 2, playerx);
    game12.print_board();
    ASSERT_EQ(game12.check_winner(playero), false);
    ASSERT_EQ(game12.check_winner(playerx), false);
    ASSERT_EQ(game12.moves_count(), 9);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
