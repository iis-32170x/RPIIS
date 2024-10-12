#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include <iostream>

class TicTacToe {
private:
    std::vector<std::vector<char>> board;
    std::size_t board_size;

public:
    TicTacToe();
    std::vector<char> &operator[](std::size_t i);
    void create_board(std::size_t size);
    const std::vector<std::vector<char>>& get_board();
    bool is_move_valid(int row, int col);   
    bool check_winner(char player);
    bool make_move(int row, int col, char &player);
    int moves_count();
    std::size_t get_board_size();
};

#endif 