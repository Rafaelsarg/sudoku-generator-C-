#include "backtracking_solver.h"

using namespace sudoku_board;

bool BacktrackingSolver::solve(sudoku_board::SudokuBoard &board) {
    int row, col;
    std::tie(row, col) = board.get_next_empty_cell();

    if (board.is_board_full()) {
        board.fill_dig_allowance();
        return true;
    }

    for (int num : sudoku_board::SudokuBoard::value_range()) {
        if((board.is_row_valid(row, num) && board.is_column_valid(col, num) && board.is_box_valid(row, col, num))){
            board[row][col] = num;
            if(solve(board)) return true;
        }
    }
    board[row][col] = 0;
    return false;
}


