
#include "backtracking_solver_test.h"


void normalize_board(sudoku_board::SudokuBoard &board, std::string line){
    int row_count = 0;
    for(int i = 0; i < line.length(); i++){
       if(i % 9 == 0 && i != 0) row_count++;
         board[row_count][i % 9] = line[i] - '0';
    }

}

void backtracking_solver_tester(){
    std::filesystem::path cwd = std::filesystem::current_path();
    cwd = cwd/"Testing/sudoku.csv";
    std::string csv_file = cwd.string();
    std::ifstream is(csv_file);
    int count_sudoku_boards = 150000; // number of sudoku boards to be solved
    int count_solved = 0; // number of sudoku boards solved
    int count = 0; // number of sudoku boards unsolved
    sudoku_board::SudokuBoard board_to_solve;
    sudoku_board::SudokuBoard board_solved;

    if (!is.good())
    {
        std::cout << "Cannot open file \"" << csv_file << "\"" << std::endl;
        exit(8);
    }
    std::string line;
    std::getline(is, line); // skip the first line
    clock_t start_time = clock();
    while(count <= count_sudoku_boards){
        if(is.fail())
        {
            if (is.eof()) break;
            std::cout << "Cannot read from the file" << std::endl;
            exit(8);
        }
        std::string sudoku, solved;
        std::getline(is, sudoku, ';');
        std::getline(is, solved);
        normalize_board(board_to_solve, sudoku);
        normalize_board(board_solved, solved);

        BacktrackingSolver::solve(board_to_solve);
        if(board_to_solve == board_solved) count_solved++;

         count++;
    }
    clock_t end_time = clock();
    double duration = double(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "Execution time of generating a Sudoku Board: " << duration << " seconds\n";

    std::cout << "Number of sudoku boards solved: " << count_solved << " out of: " << count_sudoku_boards << std::endl;

}