#include "las_vegas_algorithm.h"

namespace LasVegasAlgorithm {
    bool las_vegas_algorithm(sudoku_board::SudokuBoard &board, std::mt19937& gen, const int givens) {

        // Generate random positions for givens
        std::uniform_int_distribution<> dis(0, sudoku_board::board_length - 1);

        int chosenCount = 0;
        std::vector<std::pair<int, int>> chosenPositions;
        while (chosenCount < givens) {
            int row = dis(gen); // Generate a random row index
            int col = dis(gen); // Generate a random column index

            auto it = std::find(chosenPositions.begin(), chosenPositions.end(), std::make_pair(row, col));
            if (it == chosenPositions.end()) {
                chosenPositions.emplace_back(row, col);
                chosenCount++;
            }

        }

        if (fill_random_cells(board, gen, chosenPositions, 0)) {
            if (BacktrackingSolver::solve(board)) return true;
        }

        return false;
    }


    bool fill_random_cells(sudoku_board::SudokuBoard &board, std::mt19937& gen, std::vector<std::pair<int, int>> positions,
                           int index) {
        if (index >= positions.size()) {
            return true;
        }

        std::pair<int, int> position = positions[index];
        std::vector<int> possible_values(sudoku_board::board_length);
        std::iota(possible_values.begin(), possible_values.end(), 1);
        std::shuffle(possible_values.begin(), possible_values.end(), gen);

        for (int possible_value: possible_values) {
            if (board.is_row_valid(position.first, possible_value) &&
                board.is_column_valid(position.second, possible_value) &&
                board.is_box_valid(position.first, position.second, possible_value)) {
                board[position.first][position.second] = possible_value;
                bool a = fill_random_cells(board, gen, positions, index + 1);
                if (a) return true;
            }
        }
        return false;
    }

    void generate_filled_board(sudoku_board::SudokuBoard &board, std::mt19937& gen) {
        while (!las_vegas_algorithm(board, gen));
    }
}