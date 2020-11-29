# How to use

To use, simply input your puzzle into the puzzle array, any empty spaces should be inputted as 0, and
run. Solved puzzle will be printed to console! This Sudoku Solver uses a backtracking algorithm to
determine the solution, therefore this has the possibility of not working for select complex puzzles.

# How it works

The program starts at the top left of the puzzle and moves row by row until it reaches the last
element. During this, every cell is checked based on the common sudoku rules (each column must
include numbers 1-9 with no duplicates, same with each row, as well as each sub box of 9 must contain
all numbers 1-9 with again no duplicates). If the cell is found to violate these rules it is incremented by 1
and checked again. If the cell reaches 9 and is still found to violate the rules it is set back to 0 and the
previous cell is incremented by 1 until it either ‘matches’ again or hits 9, in which case it would also be
set to 0 and we would move back to the previous cell and repeat.

This is a very brute force way of solving the sudoku puzzle however in most cases this strategy
works perfectly fine.
