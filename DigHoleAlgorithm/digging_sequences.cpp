#include "digging_sequences.h"

namespace DiggingSequences {
    std::vector<std::pair<int, int>> randomized_sequence(std::mt19937& gen) {
        std::vector<std::pair<int, int>> sequence;
        for (int row : sudoku_board::SudokuBoard::coord_range()) {
            for (int col : sudoku_board::SudokuBoard::coord_range()) {
                sequence.emplace_back(row, col);
            }
        }

        std::shuffle(sequence.begin(), sequence.end(), gen);
        return sequence;
    }

    std::vector<std::pair<int, int>> left_to_right_sequence(std::mt19937& gen) {
        std::vector<std::pair<int, int>> sequence;
        std::vector<int> rows(sudoku_board::board_length);
        std::iota(rows.begin(), rows.end(), 0);
        std::shuffle(rows.begin(), rows.end(), gen);

        //reversed coord range

        for (int i  : rows) {
            for (int j : sudoku_board::SudokuBoard::coord_range() | std::views::reverse) {
                sequence.emplace_back(i, j);
            }
        }

        return sequence;
    }

    std::vector<std::pair<int, int>> wandering_along_S(std::mt19937& gen) {
        std::vector<std::pair<int, int>> sequence;
        std::vector<int> rows(sudoku_board::board_length);
        std::iota(rows.begin(), rows.end(), 0);
        std::shuffle(rows.begin(), rows.end(), gen);

        for (int i : rows) {
            if (i % 2 == 1) {
                for (int j : sudoku_board::SudokuBoard::coord_range() | std::views::reverse) {
                    sequence.emplace_back(i, j);
                }
            } else {
                for (int j : sudoku_board::SudokuBoard::coord_range()) {
                    sequence.emplace_back(i, j);
                }
            }
        }
        return sequence;
    }

    std::vector<std::pair<int, int>> jumping_one_cell() {
        std::vector<std::pair<int, int>> sequence;
        for (int i : sudoku_board::SudokuBoard::coord_range()) {
            if (i % 2 == 1) {
                for (int j = 7; j > 0; j -= 2) {
                    sequence.emplace_back(i, j);
                }
            } else {
                for (int j = 0; j <= 9; j += 2) {
                    sequence.emplace_back(i, j);
                }
            }
        }
        return sequence;
    }
}