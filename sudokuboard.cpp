#include "sudokuboard.h"

using namespace sudoku_board;

SudokuBoard::SudokuBoard() {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            board[row][col] = 0;
        }
    }

    for (int row : coord_range()) {
        for (int col : coord_range()) {
            dig_allowance[row][col] = false;
        }
    }
}


bool SudokuBoard::is_row_valid(const int row, const int num) {
    for (int col : coord_range()) {
        if(board[row][col] == num) return false;
    }
    return true;
}


bool SudokuBoard::is_column_valid(const int col, const int num) {
    for (int row : coord_range()) {
        if(board[row][col] == num) return false;
    }
    return true;
}

bool SudokuBoard::is_box_valid(const int row, const int col, const int num) {
    int box_row = row - row % block_length;
    int box_col = col - col % block_length;
    for(int i = box_row; i < (box_row + block_length); i++){
        for(int j = box_col; j < (box_col + block_length); j++){
            if(board[i][j] == num) return false;
        }
    }
    return true;
}

bool SudokuBoard::is_board_full() {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            if(board[row][col] == 0) return false;
        }
    }
    return true;
}

bool SudokuBoard::operator==(const sudoku_board::SudokuBoard &rhs) const {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            if(board[row][col] != rhs.board[row][col]) return false;
        }
    }
    return true;
}

std::pair<int, int> SudokuBoard::get_next_empty_cell() {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            if(board[row][col] == 0) return std::make_pair(row, col);
        }
    }
    return std::make_pair(-1, -1);
}

void SudokuBoard::fill_dig_allowance() {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            dig_allowance[row][col] = true;
        }
    }
}

bool SudokuBoard::can_dig(const int row, const int col) {
    return dig_allowance[row][col];
}

[[maybe_unused]] void SudokuBoard::print_dig_allowance() {
    for (int row : coord_range()) {
        for (int col : coord_range()) {
            std::cout << dig_allowance[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void SudokuBoard::print() {
    std::cout << "+-------+-------+-------+" << std::endl;
    for(int row : coord_range()){
        if(row % block_length == 0 && row != 0) std::cout << "+-------+-------+-------+" << std::endl;
        std::cout << "| ";
        for(int col : coord_range()){
            if(col % block_length == 0 && col != 0) std::cout << "| ";
            std::cout << SudokuBoard::board[row][col] << " ";
        }
        std::cout << "|";
        std::cout << std::endl;
    }
    std::cout << "+-------+-------+-------+" << std::endl;
}

