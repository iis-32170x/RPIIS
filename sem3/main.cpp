#include <iostream>
#include <vector>
#include <cctype>
#include "TicTacToe.hpp"

using namespace std;

// метод для вывода поля
void TicTacToe::print_board() {
    cout << "  ";
    for (size_t i = 0; i < board_size; ++i) {
        cout << i + 1 << " ";
    }
    cout << endl;

    for (size_t i = 0; i < board_size; ++i) {
        cout << i + 1 << " ";
        for (size_t j = 0; j < board_size; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

pair<int, int> type_move(char &player) {
    int row, col;
    cout << "Игрок " << player << ", введите номер строки: ";
    cin >> row;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод! Попробуйте еще раз." << endl;
        return make_pair(-1, -1);
    }
    cout << "Игрок " << player << ", введите номер столбца: ";
    cin >> col;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Некорректный ввод! Попробуйте еще раз." << endl;
        return make_pair(-1, -1);
    }
    row--; col--;
    return make_pair(row, col);
}

int main() {
    cout << "Игра крестики-нолики" << endl;
    TicTacToe game;

    while (true) {
        int choice;
        cout << R"(
Выберите действие:
0. Завершить программу
1. Начать игру
2. Изменить размер поля (по умолчанию 3)
Ваш выбор: )";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                exit(0);
            }
            case 1: 
            {
                game.create_board(game.get_board_size());
                char player;
                player = rand() % 2 == 0 ? 'X' : 'O';
                cout << "Игра началась! Сейчас ходит игрок " << player << endl;
                game.print_board();

                while (true) {
                    pair<int, int> move = type_move(player);
                    if (move.first == -1 || move.second == -1) {
                        continue;
                    }
                    if (!game.is_move_valid(move.first, move.second)) {
                        cout << "Некорректный ход! Попробуйте еще раз." << endl;
                        continue;
                    }
                    game.make_move(move.first, move.second, player);
                    if (game.check_winner(player) || game.moves_count() == game.get_board_size() * game.get_board_size()) {
                        break;
                    }
                    game.print_board();
                    player = player == 'X' ? 'O' : 'X';
                }
    
                if (game.check_winner(player)) {
                    cout << "Игра окончена. Победил игрок " << player << "!" << endl;
                    game.print_board();
                }
                else if (game.moves_count() == game.get_board_size() * game.get_board_size()) { 
                    cout << "Игра окончена. Ничья!" << endl;
                    game.print_board();
                }
                break;
            }
            case 2:
            {
                int board_size;
                cout << "Введите новый размер поля: ";
                cin >> board_size;
                game.create_board(board_size);
                break;
            }
            default:
            {
                cout << "Некорректный выбор, попробуйте еще раз." << endl;
                break;
            }
        }
    }
}