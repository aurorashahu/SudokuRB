// Project5.cpp: Write a Sudoku solver that uses recursive backtracking.
// The program should display the original puzzle and the solved puzzle.

#include <iostream>
#include <cmath>
using namespace std;

int back_track_counter = 0; // Number of backtracks

// Function to check if the input is valid
bool valid_move(int array[9][9], int row, int col, int val) // Parameters the 2D array, row number, col number, and value we want to input
{
    int startRow = (row / 3) * 3; // Find the top-left corner of the sub-grid
    int startCol = (col / 3) * 3; // Find the col of the sub grid

    for (int i = 0; i < 9; i++) // loop through
    {
        if (val == array[row][i] || val == array[i][col]) // if value is in the corresponsing row or column
        {
            return false; // action is invalid
        }
    }

    // loop through 3x3 subgrid
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (array[startRow + i][startCol + j] == val) // If val is in sub grid
            {
                return false; // action is invalid
            }
        }
    }

    return true; // Action is valid and passed all constraints
}

// FUNCTION TO PRINT CURRENT STATE OF PUZZLE
void printSudoku(int array[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (array[i][j] == 0)
                cout << ". ";
            else
                cout << array[i][j] << " ";

            if ((j + 1) % 3 == 0 && j != 8)
                cout << "| "; // Separate 3x3 blocks with a vertical bar
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i != 8)
            cout << "---------------------" << endl; // Separate 3x3 blocks with a horizontal line
    }
}

/* ----------------- SOLVING GOING ROW BY ROW --------------------- */
// FUNCTION WITHOUT PRINTING
bool backtrack(int (&array)[9][9], int row, int col) // Pass array and current row and col position values
{
    // Solving row by row
    if (row == 9) // if we finished processing the last row
    {
        cout << "Amount of times there was backtracking needed: " << back_track_counter << endl;
        // reset counter for next time use of function
        back_track_counter = 0;
        return true;
    }
    else if (col == 9) // If we reached the last column in the row go on to the next
    {
        return backtrack(array, row + 1, 0); // Recursive call with updated row
    }
    else if (array[row][col] != 0) // If element is not empty in the puzzle
    {
        return backtrack(array, row, col + 1); // Recursive call with updated row
    }
    else // If
    {
        for (int i = 1; i <= 9; i++)
        {
            if (valid_move(array, row, col, i))
            {
                array[row][col] = i;
                if (backtrack(array, row, col + 1))
                {
                    return true;
                }
                else
                {
                    array[row][col] = 0;
                    // update coutner when a value was changed back to zero
                    back_track_counter++;
                }
            }
        }
        return false;
    }
}

// FUNCTION WITH PRINTING TO VISUALIZE PROCESS
bool backtrack_with_print(int (&array)[9][9], int row, int col) // Pass array and current row and col position values
{
    // Solving row by row
    // update coutner
    if (row == 9) // if we finished processing the last row
    {
        cout << "Amount of times there was backtracking needed: " << back_track_counter << endl;
        // reset counter for next time use of function
        back_track_counter = 0;
        return true;
    }
    else if (col == 9) // If we reached the last column in the row go on to the next
    {
        return backtrack_with_print(array, row + 1, 0); // Recursive call with updated row
    }
    else if (array[row][col] != 0) // If element is not empty in the puzzle
    {
        return backtrack_with_print(array, row, col + 1); // Recursive call with updated row
    }
    else // If
    {
        for (int i = 1; i <= 9; i++)
        {
            if (valid_move(array, row, col, i))
            {
                array[row][col] = i;
                cout << "\nAdding number " << i << " at (" << row << ", " << col << ")" << endl;
                printSudoku(array);
                if (backtrack_with_print(array, row, col + 1))
                {
                    return true;
                }
                else
                {
                    array[row][col] = 0;
                    cout << endl;
                    cout << "Backtracking at (" << row << ", " << col << ") - Removing " << i << endl;
                    printSudoku(array);
                    back_track_counter++;
                }
            }
        }
        return false;
    }
}

int main()
{
    int sudoku[9][9] = {
        {0, 0, 0, 9, 0, 2, 6, 0, 4},
        {6, 0, 4, 3, 0, 0, 0, 7, 0},
        {0, 7, 0, 1, 0, 4, 0, 0, 0},

        {0, 0, 3, 0, 1, 9, 8, 0, 0},
        {1, 5, 0, 0, 4, 0, 0, 9, 7},
        {0, 0, 7, 8, 2, 0, 3, 0, 0},

        {0, 0, 0, 2, 0, 6, 0, 5, 0},
        {0, 3, 0, 0, 0, 7, 1, 0, 2},
        {9, 0, 2, 5, 0, 1, 0, 0, 0}};

    cout << "----------------------------- PUZZLE 1---------------------------------" << endl;
    printSudoku(sudoku);

    if (!backtrack(sudoku, 0, 0))
    {
        cout << "No solution for this puzzle" << endl;
    }
    else
    {
        cout << "------------------------Solution----------------------------- \n";
        printSudoku(sudoku);
    }

    int sudoku2[9][9] = {
        {6, 8, 0, 0, 0, 0, 0, 5, 0},
        {0, 0, 0, 0, 0, 5, 0, 0, 0},
        {0, 0, 3, 8, 0, 0, 2, 6, 0},

        {1, 0, 7, 0, 2, 0, 0, 0, 0},
        {0, 0, 9, 5, 0, 8, 6, 0, 0},
        {0, 0, 0, 0, 1, 0, 7, 0, 2},

        {0, 2, 1, 0, 0, 9, 4, 0, 0},
        {0, 0, 0, 4, 0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0, 0, 0, 2, 8}};

    cout << "----------------------------------------- PUZZLE 2 --------------------- " << endl;
    printSudoku(sudoku2);
    if (!backtrack(sudoku2, 0, 0))
    {
        cout << "No solution for this puzzle" << endl;
    }
    else
    {
        cout << "------------------------------------------Solution-------------------------------------- \n";
        printSudoku(sudoku2);
    }

    int sudoku3[9][9] = {
        {4, 0, 2, 6, 3, 8, 1, 0, 0},
        {0, 8, 0, 9, 5, 0, 3, 0, 0},
        {3, 1, 0, 0, 7, 2, 5, 0, 6},

        {0, 7, 0, 1, 2, 3, 6, 5, 0},
        {8, 0, 0, 7, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 8, 0, 0, 0, 0},

        {0, 4, 3, 8, 1, 0, 0, 0, 2},
        {6, 0, 0, 0, 0, 4, 0, 1, 0},
        {1, 9, 0, 0, 0, 5, 0, 0, 7}};

    cout << "\n************** EASY PUZZLE TO SHOW MOVEMENTS ********************* " << endl;
    printSudoku(sudoku3);

    if (!backtrack_with_print(sudoku3, 0, 0))
    {
        cout << "No solution for this puzzle" << endl;
    }
    else
    {
        cout << "----------Solution------------- \n";
        printSudoku(sudoku3);
    }

    int unsolvableSudoku[9][9] = {
        {5, 1, 6, 8, 4, 9, 7, 3, 2},
        {3, 0, 7, 6, 0, 5, 0, 0, 0},
        {8, 0, 9, 7, 0, 0, 0, 6, 5},

        {1, 3, 5, 0, 6, 0, 9, 0, 7},
        {4, 7, 2, 5, 9, 1, 0, 0, 0},
        {9, 6, 8, 3, 7, 0, 0, 5, 0},

        {2, 5, 3, 1, 8, 6, 0, 7, 4},
        {6, 8, 4, 9, 2, 7, 5, 0, 0},
        {7, 9, 1, 0, 5, 0, 6, 8, 3} // 6 appears twice in column 9
    };

    cout << "\n~~~~~~~~~~~~~~~~~~~UNSOLVABLE PUZZLE ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    printSudoku(unsolvableSudoku);
    if (!backtrack(unsolvableSudoku, 0, 0))
    {
        cout << "No solution for this puzzle" << endl;
    }
    else
    {
        cout << "------------------------------------------Solution-------------------------------------- \n";
        printSudoku(unsolvableSudoku);
    }

    return 0;
}
