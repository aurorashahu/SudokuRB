# SudokuRB

Solving sudoku puzzle using recursive backtracking

Data structures used:
~ Two dimentional array to represent 9x9 sudodku puzzle
Functions used:
~ Valid move - Check if the value that we want to insert in a specific row and column is valid. To do this, the function checks the constrainsts/rules of the puzzle. Same value can not be in any row, column, or subgrid.
~ Print Sudoku - Displaying the puzzle in a nice format
~ Backtrack - Returns a boolean value, true if we reached a solution and false if we havent - Solving the puzzle using recursive backtracking - The function goes row by row untill it has reached the end. - Function included a few condition statements inorder to make the recursion work. If the row count is 9 then we have reached the end and return solution. If we have reached a column 9 then go onto the next row. If none of those conditions fit then we subsitiute a value 1-9 into the current location and call the function again. - If the function returns true, we return true. The 2D array is passed by reference so it has been constantly updated. If the function does not return true, we need to backtrack. Replace the current location with zero and incrememnt counter
~ Back track with print
~ Backtrack function but with print statements to display it visually to the user where backtracking occurs and what values get selected
Input format:
Precoded puzzle arrays as input
Output format:
Before and after solved puzzle and number of backtracking needed
Examples:
----------------------------- PUZZLE 1---------------------------------
. . . | 9 . 2 | 6 . 4
6 . 4 | 3 . . | . 7 .
. 7 . | 1 . 4 | . . .

---

. . 3 | . 1 9 | 8 . .
1 5 . | . 4 . | . 9 7
. . 7 | 8 2 . | 3 . .

---

. . . | 2 . 6 | . 5 .
. 3 . | . . 7 | 1 . 2
9 . 2 | 5 . 1 | . . .
Amount of times there was backtracking needed: 575
------------------------Solution-----------------------------
8 1 5 | 9 7 2 | 6 3 4
6 2 4 | 3 5 8 | 9 7 1
3 7 9 | 1 6 4 | 5 2 8

---

2 6 3 | 7 1 9 | 8 4 5
1 5 8 | 6 4 3 | 2 9 7
4 9 7 | 8 2 5 | 3 1 6

---

7 8 1 | 2 3 6 | 4 5 9
5 3 6 | 4 9 7 | 1 8 2
9 4 2 | 5 8 1 | 7 6 3
----------------------------------------- PUZZLE 2 ---------------------
6 8 . | . . . | . 5 .
. . . | . . 5 | . . .
. . 3 | 8 . . | 2 6 .

---

1 . 7 | . 2 . | . . .
. . 9 | 5 . 8 | 6 . .
. . . | . 1 . | 7 . 2

---

. 2 1 | . . 9 | 4 . .
. . . | 4 . . | . . .
. 3 . | . . . | . 2 8
Amount of times there was backtracking needed: 14512
------------------------------------------Solution--------------------------------------
6 8 2 | 7 9 3 | 1 5 4
7 1 4 | 2 6 5 | 8 9 3
5 9 3 | 8 4 1 | 2 6 7

---

1 6 7 | 3 2 4 | 5 8 9
2 4 9 | 5 7 8 | 6 3 1
3 5 8 | 9 1 6 | 7 4 2

---

8 2 1 | 6 3 9 | 4 7 5
9 7 5 | 4 8 2 | 3 1 6
4 3 6 | 1 5 7 | 9 2 8

**\*\***\*\***\*\*** EASY PUZZLE TO SHOW MOVEMENTS \***\*\*\*\*\***\*\***\*\*\*\*\***
4 . 2 | 6 3 8 | 1 . .
. 8 . | 9 5 . | 3 . .
3 1 . | . 7 2 | 5 . 6

---

. 7 . | 1 2 3 | 6 5 .
8 . . | 7 . . | . . 1
. . . | . 8 . | . . .

---

. 4 3 | 8 1 . | . . 2
6 . . | . . 4 | . 1 .
1 9 . | . . 5 | . . 7

Adding number 5 at (0, 1)
4 5 2 | 6 3 8 | 1 . .
. 8 . | 9 5 . | 3 . .
3 1 . | . 7 2 | 5 . 6

---

. 7 . | 1 2 3 | 6 5 .
8 . . | 7 . . | . . 1
. . . | . 8 . | . . .

---

. 4 3 | 8 1 . | . . 2
6 . . | . . 4 | . 1 .
1 9 . | . . 5 | . . 7

.
.
.
.
.
.
Backtracking at (4, 6) - Removing 9
4 5 2 | 6 3 8 | 1 7 9
7 8 6 | 9 5 1 | 3 2 4
3 1 9 | 4 7 2 | 5 8 6

---

9 7 4 | 1 2 3 | 6 5 8
8 2 5 | 7 4 6 | . . 1
. . . | . 8 . | . . .

---

. 4 3 | 8 1 . | . . 2
6 . . | . . 4 | . 1 .
1 9 . | . . 5 | . . 7

Backtracking at (4, 5) - Removing 6
4 5 2 | 6 3 8 | 1 7 9
7 8 6 | 9 5 1 | 3 2 4
3 1 9 | 4 7 2 | 5 8 6

---

9 7 4 | 1 2 3 | 6 5 8
8 2 5 | 7 4 . | . . 1
. . . | . 8 . | . . .

---

. 4 3 | 8 1 . | . . 2
6 . . | . . 4 | . 1 .
1 9 . | . . 5 | . . 7
.
.
.
.

```UNSOLVABLE PUZZLE ~~~~~~~~~~~~~~~~~~~~~~~~
5 1 6 | 8 4 9 | 7 3 2
3 . 7 | 6 . 5 | . . .
8 . 9 | 7 . . | . 6 5
---------------------
1 3 5 | . 6 . | 9 . 7
4 7 2 | 5 9 1 | . . .
9 6 8 | 3 7 . | . 5 .
---------------------
2 5 3 | 1 8 6 | . 7 4
6 8 4 | 9 2 7 | 5 . .
7 9 1 | . 5 . | 6 8 3
No solution for this puzzle


Statistics:
Average number of backtracking steps: 1236

```
