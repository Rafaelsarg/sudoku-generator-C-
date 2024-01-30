cmake_minimum_required(VERSION 3.25)
project(SudokuGeneratorDigHole)

set(CMAKE_CXX_STANDARD 23)

add_executable(generator main.cpp sudokuboard.cpp sudokuboard.h Solvers/backtracking_solver.cpp Solvers/backtracking_solver.h LasVegasAlgorithm/las_vegas_algorithm.cpp LasVegasAlgorithm/las_vegas_algorithm.h DigHoleAlgorithm/digging_sequences.cpp DigHoleAlgorithm/digging_sequences.h DigHoleAlgorithm/digging.cpp DigHoleAlgorithm/digging.h Testing/backtracking_solver_test.cpp Testing/backtracking_solver_test.h Testing/sudoku.csv)
