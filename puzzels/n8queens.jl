function is_safe(board, row, col, N)
    # Check if there is a queen in the same column
    for i in 1:row-1
        if board[i] == col || abs(board[i] - col) == abs(i - row)
            return false
        end
    end
    return true
end

function solve_nqueens(board, row, N)
    if row > N
        # All queens are placed successfully
        println(board)
        return
    end

    for col in 1:N
        if is_safe(board, row, col, N)
            # Place queen and move to the next row
            board[row] = col
            solve_nqueens(board, row + 1, N)
            # Backtrack: Remove the queen if placing it leads to no solution
            board[row] = 0
        end
    end
end

function nqueens(N)
    board = zeros(Int, N)
    solve_nqueens(board, 1, N)
end


nqueens(8)
