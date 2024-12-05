# Advent of Code 2024 - Day 4: Ceres Search

## Problem Description

The engineers at the Ceres monitoring station need your help with a word search. They’ve given you a list of strings, each containing a collection of characters. Your task is to find how many times the word **XMAS** appears in various orientations within the grid.

### Part One: Find XMAS in All Orientations
You need to find all instances of the word **XMAS** in the word search grid. The word can appear:
- Horizontally (left to right or right to left)
- Vertically (top to bottom or bottom to top)
- Diagonally (in all four diagonal directions)

#### Example Word Search and Explanation:
| Report         | Status  | Explanation                                                      |
|----------------|---------|------------------------------------------------------------------|
| `MMMSXXMASM`   | Found   | The word **XMAS** is found horizontally.                        |
| `MSAMXMSMSA`   | Found   | The word **XMAS** appears multiple times in different positions. |
| `AMXSXMAAMM`   | Found   | The word **XMAS** is found diagonally in one direction.         |
| `MSAMASMSMX`   | Found   | The word **XMAS** appears multiple times diagonally.            |
| `XMASAMXAMM`   | Found   | The word **XMAS** is found both horizontally and vertically.    |

In this example, **XMAS** appears 18 times in total in various orientations.

### Part Two: X-MAS Puzzle
In this part, you need to find two instances of **MAS** in the shape of an **X**. The word **MAS** can appear forwards or backwards, and the goal is to form the letter X shape.

#### Example Word Search and Explanation:
| Report         | Status  | Explanation                                                     |
|----------------|---------|-----------------------------------------------------------------|
| `.M.S......`   | Found   | The letters **MAS** form an **X** pattern.                      |
| `..A..MSMS.`   | Found   | The **MAS** pattern appears diagonally.                         |
| `.M.S.MAA..`   | Found   | The word **MAS** is found in the shape of an **X**.             |
| `..A.ASMSM.`   | Found   | The word **MAS** forms an **X** shape.                          |
| `.M.S.M....`   | Found   | Another instance of **MAS** in the **X** shape.                |

In this example, the word **MAS** in the shape of an **X** appears 9 times.

---

## Solution

### Approach:
1. Parse the word search grid from the input file.
2. **Part One**:
    - Check for the word **XMAS** in all possible orientations (horizontal, vertical, and diagonal).
    - Count how many times **XMAS** appears in the grid.
3. **Part Two**:
    - Check for the word **MAS** in the shape of an **X** in all possible orientations.
    - Count how many times the **X** pattern of **MAS** appears in the grid.

---

## Implementation

### Files:
- **`main.cpp`**: Contains the solution logic.
- **`input.txt`**: The puzzle input data.

### Compilation:
To compile the program:

```bash
g++ -std=c++20 -o day4_solution main.cpp