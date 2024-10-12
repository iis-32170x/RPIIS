#include <iostream>
#include <vector>
#include <cctype>
#include "TicTacToe.hpp"

/*!
 * \brief Конструктор по умолчанию.
 *
 * Инициализирует игровое поле стандартным размером 3x3.
 */
TicTacToe::TicTacToe() : board_size(3) {
    create_board(board_size);
}

/*!
 * \brief Оператор доступа к строкам игрового поля.
 *
 * Позволяет получить доступ к строке игрового поля по индексу.
 *
 * \param i Индекс строки.
 * \return Ссылка на вектор, представляющий строку игрового поля.
 */
std::vector<char> &TicTacToe::operator[](std::size_t i) {
    return board[i];
}

/*!
 * \brief Метод для создания игрового поля.
 *
 * Создает игровое поле заданного размера и инициализирует его пустыми символами.
 * Поле должно быть размером от 3 до 10.
 *
 * \param size Размер игрового поля.
 */
void TicTacToe::create_board(std::size_t size) {
    board_size = size;
    board.clear();
    for (std::size_t i = 0; i < board_size; i++) {
        board.push_back(std::vector<char>(board_size, '-'));
    }
}

/*!
 * \brief Получение текущего игрового поля.
 *
 * Возвращает текущее состояние игрового поля в виде двумерного вектора.
 *
 * \return Константная ссылка на игровое поле.
 */
const std::vector<std::vector<char>>& TicTacToe::get_board() {
    return board;
}

/*!
 * \brief Проверка валидности хода.
 *
 * Проверяет, допустим ли ход в заданную ячейку поля. Ход считается валидным,
 * если строка и колонка находятся в пределах игрового поля, и выбранная ячейка пуста.
 *
 * \param row Номер строки.
 * \param col Номер колонки.
 * \return true, если ход допустим, иначе false.
 */
bool TicTacToe::is_move_valid(int row, int col) {
    if (row >= board_size || col >= board_size || board[row][col] != '-' || row < 0 || col < 0) {
        return false;
    }
    return true;
}

/*!
 * \brief Метод для выполнения хода игрока.
 *
 * Если ход допустим, устанавливает символ игрока в указанную ячейку.
 *
 * \param row Номер строки.
 * \param col Номер колонки.
 * \param player Символ игрока ('X' или 'O').
 * \return true, если ход успешно выполнен, иначе false.
 */
bool TicTacToe::make_move(int row, int col, char &player) {
    if (!is_move_valid(row, col)) {
        return false;
    }
    board[row][col] = player;
    return true;
}

/*!
 * \brief Проверка победителя.
 *
 * Проверяет, победил ли указанный игрок, проверяя строки, столбцы и диагонали на наличие одинаковых символов.
 *
 * \param player Символ игрока ('X' или 'O').
 * \return true, если игрок победил, иначе false.
 */
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

/*!
 * \brief Получить количество сделанных ходов.
 *
 * Подсчитывает количество ходов на игровом поле, то есть количество непустых ячеек.
 *
 * \return Количество ходов.
 */
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

/*!
 * \brief Получить размер игрового поля.
 *
 * Возвращает текущий размер игрового поля.
 *
 * \return Размер игрового поля.
 */
std::size_t TicTacToe::get_board_size() {
    return board_size;
}