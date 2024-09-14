#include <iostream>
#include <vector>
#include <cctype>
#include "TicTacToe.hpp"


TicTacToe::TicTacToe() : board_size(3) {
    create_board(board_size);
}

std::vector<char> &TicTacToe::operator[](std::size_t i) {
    return board[i];
}

// метод для создания поля
void TicTacToe::create_board(std::size_t size) {
    board_size = size;
    if (board_size < 2 || board_size > 10) {
        std::cout << "Неверный размер поля. Укажите размер >2 и <10" << std::endl;
        return;
    }
    board.clear();
    for (std::size_t i = 0; i < board_size; i++) {
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
    for (std::size_t i = 0; i < board.size(); i++) {
        bool win_row = true;
        for (std::size_t j = 0; j < board.size(); j++) {
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
    for (std::size_t i = 0; i < board.size(); i++) {
        bool win_col = true;
        for (std::size_t j = 0; j < board.size(); j++) {
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
    for (std::size_t i = 0; i < board.size(); i++) {
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
    for (std::size_t i = 0; i < board.size(); i++) {
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
    for (std::size_t i = 0; i < board_size; i++) {
        for (std::size_t j = 0; j < board_size; j++) {
            if (board[i][j] != '-') {
                count++;
            }
        }
    }
    return count;
}

std::size_t TicTacToe::get_board_size() {
    return board_size;
}