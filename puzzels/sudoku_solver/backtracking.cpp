#include <vector>
#include <array>
#include <bitset>
#include <iostream>



// Function to check if placing 'num' at position (row, col) is valid
bool isValid(const std::vector<std::vector<char>> &board, int row, int col, char num) {
    // Check if 'num' is not present in the current row and column
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // Check if 'num' is not present in the current 3x3 subgrid
    int startRow = 3 * (row / 3);
    int startCol = 3 * (col / 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku puzzle using backtracking
bool solveSudokuHelper(std::vector<std::vector<char>> &board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        // Place 'num' at (row, col)
                        board[row][col] = num;

                        // Recursively try to solve the rest of the puzzle
                        if (solveSudokuHelper(board)) {
                            return true;
                        }

                        // If the current placement doesn't lead to a solution, backtrack
                        board[row][col] = '.';
                    }
                }
                // No valid number found for the current cell, backtrack
                return false;
            }
        }
    }
    // All cells filled, puzzle solved
    return true;
}

// Function to print the Sudoku board
void print_board(std::vector<std::vector<char>> board) {
    for (std::size_t row = 0; row < 9; ++row) {
        for (std::size_t col = 0; col < 9; ++col) {
            std::cout << board[row][col] << ", ";
        }
        std::cout << "\n";
    }
}

// Function to convert a flat representation to a 2D vector
std::vector<std::vector<char>> flat_board_to_vec_vec(std::array<char, 81> const flat_board) {
    std::vector<std::vector<char>> board;
    board.reserve(9);
    for (std::size_t row = 0; row < 9; ++row) {
        std::vector<char> this_row;
        this_row.reserve(9);
        for (std::size_t col = 0; col < 9; ++col) {
            this_row.push_back(flat_board[row * 9 + col]);
        }
        board.push_back(this_row);
    }
    return board;
}

int main() {
    // Initial Sudoku board
    std::array<char, 81> const flat_board = {'5', '3', '.', '.', '7', '.', '.', '.', '.', '6', '.', '.', '1', '9', '5', '.', '.', '.', '.', '9', '8', '.', '.', '.', '.', '6', '.', '8', '.', '.', '.', '6', '.', '.', '.', '3', '4', '.', '.', '8', '.', '3', '.', '.', '1', '7', '.', '.', '.', '2', '.', '.', '.', '6', '.', '6', '.', '.', '.', '.', '2', '8', '.', '.', '.', '.', '4', '1', '9', '.', '.', '5', '.', '.', '.', '.', '8', '.', '.', '7', '9'};
    // Expected solution
    std::array<char, 81> const flat_expected = {'5', '3', '4', '6', '7', '8', '9', '1', '2', '6', '7', '2', '1', '9', '5', '3', '4', '8', '1', '9', '8', '3', '4', '2', '5', '6', '7', '8', '5', '9', '7', '6', '1', '4', '2', '3', '4', '2', '6', '8', '5', '3', '7', '9', '1', '7', '1', '3', '9', '2', '4', '8', '5', '6', '9', '6', '1', '5', '3', '7', '2', '8', '4', '2', '8', '7', '4', '1', '9', '6', '3', '5', '3', '4', '5', '2', '8', '6', '1', '7', '9'};
    
    // Convert to 2D vectors
    std::vector<std::vector<char>> board = flat_board_to_vec_vec(flat_board);
    std::vector<std::vector<char>> const expected = flat_board_to_vec_vec(flat_expected);

    std::cout << "Initial Board:\n";
    print_board(board);

    std::cout << "\nExpected Solution:\n";
    print_board(expected);

    solveSudokuHelper(board);

    // Check if the solution is correct
    std::cout << "\n" << (board == expected ? "Solved!" : "Not solved!") << std::endl;

    std::cout << "\nActual Solution:\n";
    print_board(board);

    return 0;
}
