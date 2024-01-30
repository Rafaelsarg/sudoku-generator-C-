#include <iostream>
#include <ctime>
#include <string>
#include "sudokuboard.h"
#include "LasVegasAlgorithm/las_vegas_algorithm.h"
#include "DigHoleAlgorithm/digging.h"
#include "Testing/backtracking_solver_test.h"

void generateSudoku(){
    std::random_device rd;
    std::mt19937 gen(rd());

    std::cout << "Welcome to Sudoku Generator!" << std::endl;
    while(true) {
        std::cout << "Would you like to generate a Sudoku puzzle? Please answer with 'yes' or 'no': ";
        std::string answer;
        std::getline(std::cin, answer);
        if (answer == "no") {
            break;
        }
        else if(answer == "yes") {
            int difficulty;
            while (true) {
                std::string line;
                std::cout << "Enter difficulty (1-5): ";
                std::getline(std::cin, line);
                try {
                    difficulty = std::stoi(line);
                    if (difficulty >= 1 && difficulty <= 5) {
                        break;
                    } else {
                        std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
                    }
                } catch (std::invalid_argument &e) {
                    std::cout << "Invalid input. Please enter a number between 1 and 5." << std::endl;
                }
            }
            clock_t start_time = clock();
            // Create a board object and generator
            sudoku_board::SudokuBoard b2;
            Digging digger;

            // Generate a filled board
            LasVegasAlgorithm::generate_filled_board(b2, gen);

            // Dig holes in the board
            SudokuBoard a = digger.dig_hole(b2, gen, difficulty);

            // Print the board
            a.print();

            std::cout << "Would you like to see the solved puzzle? Please answer with 'yes' or 'no': ";
            BacktrackingSolver::solve(a);

            clock_t end_time = clock();

            while (true) {
                std::string answer_solved;
                std::getline(std::cin, answer_solved);
                if (answer_solved == "yes") {
                    a.print();
                    break;
                } else if (answer_solved == "no") {
                    break;
                } else {
                    std::cout << "Invalid input. Please enter yes or no." << std::endl;
                }
            }

            double duration = double(end_time - start_time) / CLOCKS_PER_SEC;
            std::cout << "Execution time of generating a Sudoku Board: " << duration << " seconds\n";

        }
        else {
            std::cout << "Invalid input. Please enter yes or no." << std::endl;
        }
    }
}

int main() {
    generateSudoku();
    return 0;
}

