#ifndef SUDOKUGENERATORDIGHOLE_LAS_VEGAS_ALGORITHM_H
#define SUDOKUGENERATORDIGHOLE_LAS_VEGAS_ALGORITHM_H

#include <random>
#include <vector>
#include <utility>
#include <algorithm>
#include "../sudokuboard.h"
#include "../Solvers/backtracking_solver.h"

namespace LasVegasAlgorithm {
    bool las_vegas_algorithm(sudoku_board::SudokuBoard &board, std::mt19937& gen, int givens = 11);
    bool fill_random_cells(sudoku_board::SudokuBoard &board, std::mt19937& gen, std::vector<std::pair<int, int>> positions, int index);
    void generate_filled_board(sudoku_board::SudokuBoard &board, std::mt19937& gen);

};

#endif //SUDOKUGENERATORDIGHOLE_LAS_VEGAS_ALGORITHM_H
