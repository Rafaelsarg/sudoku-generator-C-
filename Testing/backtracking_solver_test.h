//
// Created by Rafael Sargsyan on 04.05.23.
//

#ifndef SUDOKUGENERATORDIGHOLE_BACKTRACKING_SOLVER_TEST_H
#define SUDOKUGENERATORDIGHOLE_BACKTRACKING_SOLVER_TEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <filesystem>
#include "../sudokuboard.h"
#include "../Solvers//backtracking_solver.h"

void normalize_board(sudoku_board::SudokuBoard &board, std::string line);
void backtracking_solver_tester();

#endif //SUDOKUGENERATORDIGHOLE_BACKTRACKING_SOLVER_TEST_H
