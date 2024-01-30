#ifndef SRC_SUDOKU_BOARD_H
#define SRC_SUDOKU_BOARD_H

#include <iostream>
#include <array>
#include <ranges>
#include <numeric>

namespace sudoku_board {

    const int block_length = 3;
    const int board_length = block_length * block_length;
    using Board = std::array<std::array<int, board_length>, board_length>;
    using Dig_allowance = std::array<std::array<bool, board_length>, board_length>;

    class SudokuBoard {
    private:
        Board board;
        Dig_allowance dig_allowance{};

    public:
        // Constructors
        SudokuBoard();
        explicit SudokuBoard(Board b) : board(b) {};

        // Overload = operator
        explicit operator Board()  { return board; }

        // Overload [] operator to access elements in 2D array
        std::array<int, board_length> &operator[](int row) { return board[row]; }
        const std::array<int, board_length> &operator[](int row) const { return board[row]; }

        // Board Operations
        bool is_row_valid(int row, int num); // Check if a number is valid in a row
        bool is_column_valid(int col, int num); // Check if a number is valid in a column
        bool is_box_valid(int row, int col, int num); // Check if a number is valid in a box
        bool is_board_full(); // Check if the board is full
        std::pair<int, int> get_next_empty_cell(); // Get the next empty cell in the board
        bool operator==(const SudokuBoard &rhs) const; // Overload == operator to compare two boards


        // Digging Operations
        void fill_dig_allowance(); // Fill dig_allowance with true
        [[maybe_unused]] void print_dig_allowance(); // For debugging
        bool can_dig(int row, int col); // Check if a cell can be dug

        // Print Board
        void print();


        static auto coord_range() {
            return std::ranges::iota_view(0, board_length);
        }

        static auto value_range() {
            return std::ranges::iota_view(1, board_length + 1);
        }


    };
}
#endif //SRC_SUDOKU_BOARD_H
