#ifndef SUDOKUGENERATORDIGHOLE_DIGGING_H
#define SUDOKUGENERATORDIGHOLE_DIGGING_H

#include "../sudokuboard.h"
#include "digging_sequences.h"
#include "../Solvers/backtracking_solver.h"

using namespace sudoku_board;

class Digging {
public:
    Digging() = default;

    SudokuBoard dig_hole(const SudokuBoard &board, std::mt19937& gen, int difficulty);
    static bool check_another_solution(SudokuBoard board, const int row, const int col, const int num);

private:
    int max_holes;
};
#endif //SUDOKUGENERATORDIGHOLE_DIGGING_H
