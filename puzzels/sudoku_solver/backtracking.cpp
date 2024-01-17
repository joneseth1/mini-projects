#include <vector>
#include <array>
#include <bitset>
#include <iostream>


bool solveSudokuHelper(std::vector<std::vector<char>> &board) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] == '.') {
                for (char num = '1'; num <= '9'; ++num) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudokuHelper(board)) {
                            return true;
                        }

                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}


void print_board(std::vector<std::vector<char>> board)
{
    for (std::size_t row = 0; row < 9; ++row)
    {
        for (std::size_t col = 0; col < 9; ++col)
        {
            std::cout << board[row][col] << ", ";
        }
        std::cout << "\n";
    }
}


std::vector<std::vector<char>> flat_board_to_vec_vec(std::array<char, 81> const flat_board)
{
    std::vector<std::vector<char>> board;
    board.reserve(9);
    for (std::size_t row = 0; row < 9; ++row)
    {
        std::vector<char> this_row;
        this_row.reserve(9);
        for (std::size_t col = 0; col < 9; ++col)
        {
            this_row.push_back(flat_board[row * 9 + col]);
        }
        board.push_back(this_row);
    }
    return board;
}

int main()
{
    std::array<char, 81> const flat_board = {'5', '3', '.', '.', '7', '.', '.', '.', '.', '6', '.', '.', '1', '9', '5', '.', '.', '.', '.', '9', '8', '.', '.', '.', '.', '6', '.', '8', '.', '.', '.', '6', '.', '.', '.', '3', '4', '.', '.', '8', '.', '3', '.', '.', '1', '7', '.', '.', '.', '2', '.', '.', '.', '6', '.', '6', '.', '.', '.', '.', '2', '8', '.', '.', '.', '.', '4', '1', '9', '.', '.', '5', '.', '.', '.', '.', '8', '.', '.', '7', '9'};
    std::array<char, 81> const flat_expected = {'5', '3', '4', '6', '7', '8', '9', '1', '2', '6', '7', '2', '1', '9', '5', '3', '4', '8', '1', '9', '8', '3', '4', '2', '5', '6', '7', '8', '5', '9', '7', '6', '1', '4', '2', '3', '4', '2', '6', '8', '5', '3', '7', '9', '1', '7', '1', '3', '9', '2', '4', '8', '5', '6', '9', '6', '1', '5', '3', '7', '2', '8', '4', '2', '8', '7', '4', '1', '9', '6', '3', '5', '3', '4', '5', '2', '8', '6', '1', '7', '9'};
    std::vector<std::vector<char>> board = flat_board_to_vec_vec(flat_board);
    std::vector<std::vector<char>> const expected = flat_board_to_vec_vec(flat_expected);


    std::cout << "initial\n";
    print_board(board);

    std::cout << "expected\n";
    print_board(expected);

    solveSudoku(board);
    std::cout << (board == expected ? "Solved!" : "Not solved!") << std::endl;
    std::cout << "actual\n";
    print_board(board);
    return 0;
}