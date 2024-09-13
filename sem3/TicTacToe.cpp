#include <iostream>
#include <vector>
#include <cctype>
#include "TicTacToe.hpp"


TicTacToe::TicTacToe() : board_size(3) {
    create_board(board_size);
}

std::vector<char> &TicTacToe::operator[](size_t i) {
    return board[i];
}

// метод для создания поля
void TicTacToe::create_board(size_t size) {
    board_size = size;
    board.clear();
    for (size_t i = 0; i < board_size; i++) {
        board.push_back(std::vector<char>(board_size, '-'));
    }
}

const std::vector<std::vector<char>>& TicTacToe::get_board() {
    return board;
}

// метод для проверки валидности хода
bool TicTacToe::is_move_valid(int row, int col) {
    if (row >= board_size || col >= board_size || board[row][col] != '-' ||
        row < 0 || col < 0) {
        return false;
    }
    return true;
}

// метод для хода игрока
bool TicTacToe::make_move(int row, int col, char &player) {
    if (!is_move_valid(row, col)) {
        return false;
    }
    board[row][col] = player;
    return true;
}

// метод для проверки победителя
bool TicTacToe::check_winner(char player) {
    // проверка горизонталей
    for (size_t i = 0; i < board.size(); i++) {
        bool win_row = true;
        for (size_t j = 0; j < board.size(); j++) {
            if (board[i][j] != player) {
                win_row = false;
                break;
            }
        }
        if (win_row) {
            return true;
        }
    }

    // проверка вертикалей
    for (size_t i = 0; i < board.size(); i++) {
        bool win_col = true;
        for (size_t j = 0; j < board.size(); j++) {
            if (board[j][i] != player) {
                win_col = false;
                break;
            }
        }
        if (win_col) {
            return true;
        }
    }

    // проверка главной диагонали
    bool win_main_diag = true;
    for (size_t i = 0; i < board.size(); i++) {
        if (board[i][i] != player) {
            win_main_diag = false;
            break;
        }
    }
    if (win_main_diag) {
        return true;
    }

    // проверка побочной диагонали
    bool win_secondary_diag = true;
    for (size_t i = 0; i < board.size(); i++) {
        if (board[i][board.size() - i - 1] != player) {
            win_secondary_diag = false;
            break;
        }
    }
    if (win_secondary_diag) {
        return true;
    }

    return false;
}

int TicTacToe::moves_count() {
    int count = 0;
    for (size_t i = 0; i < board_size; i++) {
        for (size_t j = 0; j < board_size; j++) {
            if (board[i][j] != '-') {
                count++;
            }
        }
    }
    return count;
}

size_t TicTacToe::get_board_size() {
    return board_size;
}