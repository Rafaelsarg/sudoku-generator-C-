#include "digging.h"
#include <random>

SudokuBoard Digging::dig_hole(const sudoku_board::SudokuBoard &board, std::mt19937& gen, const int difficulty){
    SudokuBoard new_board = board;
    std::vector<std::pair<int, int>> sequence;

    int count  = 0;

    if(difficulty == 1) {
        sequence = DiggingSequences::randomized_sequence(gen);
        std::uniform_int_distribution<> dis(26, 31);
        max_holes = dis(gen);
    } else if(difficulty == 2){
        sequence = DiggingSequences::randomized_sequence(gen);
        std::uniform_int_distribution<> dis(32, 45);
        max_holes = dis(gen);
    } else if(difficulty == 3){
        sequence = DiggingSequences::jumping_one_cell();
        std::uniform_int_distribution<> dis(46, 49);
        max_holes = dis(gen);
    } else if(difficulty == 4){
        sequence = DiggingSequences::wandering_along_S(gen);
        std::uniform_int_distribution<> dis(50, 52);
        max_holes = dis(gen);
    } else if(difficulty == 5){
        sequence = DiggingSequences::left_to_right_sequence(gen);
        std::uniform_int_distribution<> dis(53, 55);
        max_holes = dis(gen);
    }

    for (const auto &cell : sequence) {
        int row = cell.first;
        int col = cell.second;
        if(!new_board.can_dig(row, col)) continue;

        int num = new_board[row][col];
        new_board[row][col] = 0;

        if(!check_another_solution(new_board, row, col, num)){
            new_board[row][col] = num;
        }
        else {
            new_board[row][col] = 0;
            count++;
        }

        if(count >= max_holes) {
            return new_board;
        }

    }

    return new_board;
}

bool Digging::check_another_solution(sudoku_board::SudokuBoard board, const int row, const int col, const int num) {
    for (int i : board.value_range()) {
        if(i == num) continue;
        if(board.is_row_valid(row, i) && board.is_column_valid(col, i) && board.is_box_valid(row, col, i)) {
            board[row][col] = i;
            if(BacktrackingSolver::solve(board)) return false;
        }
    }
    return true;
}