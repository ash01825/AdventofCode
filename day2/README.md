# Advent of Code 2024 - Day 2: Red-Nosed Reports

## Problem Description

The engineers at the Red-Nosed Reindeer nuclear fusion/fission plant need your help analyzing unusual reactor data. Each line of the data, called a **report**, contains a list of numbers referred to as **levels**. The goal is to determine which reports are **safe** based on specific safety rules.

### Part One: Initial Safety Rules
A report is **safe** if:
1. The levels are either:
    - Strictly increasing, or
    - Strictly decreasing.
2. The difference between any two adjacent levels is at least 1 and at most 3.

#### Example Reports and Analysis:
| Report         | Status  | Explanation                                                      |
|----------------|---------|------------------------------------------------------------------|
| `7 6 4 2 1`   | **Safe**  | All levels are decreasing, with differences of 1 or 2.          |
| `1 2 7 8 9`   | Unsafe  | Difference between `2` and `7` is 5 (greater than 3).            |
| `9 7 6 2 1`   | Unsafe  | Difference between `6` and `2` is 4 (greater than 3).            |
| `1 3 2 4 5`   | Unsafe  | The sequence is neither strictly increasing nor decreasing.      |
| `8 6 4 4 1`   | Unsafe  | The pair `4` and `4` is not a valid increase or decrease.        |
| `1 3 6 7 9`   | **Safe**  | All levels are increasing, with differences of 1, 2, or 3.      |

In the above example, only 2 reports are safe.

### Part Two: Problem Dampener
The engineers introduce the **Problem Dampener**, a feature that can ignore a single problematic level to make an otherwise unsafe report **safe**.

#### Updated Example Reports and Analysis:
| Report         | Status  | Explanation                                                     |
|----------------|---------|-----------------------------------------------------------------|
| `7 6 4 2 1`   | **Safe**  | No changes needed.                                             |
| `1 2 7 8 9`   | Unsafe  | Removing any single level still does not make it safe.          |
| `9 7 6 2 1`   | Unsafe  | Removing any single level still does not make it safe.          |
| `1 3 2 4 5`   | **Safe**  | Removing the second level (`3`) results in a safe report.      |
| `8 6 4 4 1`   | **Safe**  | Removing the third level (`4`) results in a safe report.       |
| `1 3 6 7 9`   | **Safe**  | No changes needed.                                             |

With the Problem Dampener, 4 reports are now safe in this example.

---

## Solution

### Approach:
1. Parse each report from the input file.
2. **Part One**:
    - Check if the report is sorted (in ascending or descending order).
    - Ensure all adjacent differences fall within the range `[1, 3]`.
3. **Part Two**:
    - If a report is not safe:
        - Attempt to remove each level (one at a time).
        - Recheck safety for the modified report.
        - If any modification results in a safe report, count it as safe.

---

## Implementation

### Files:
- **`main.cpp`**: Contains the solution logic.
- **`input.txt`**: The puzzle input data.

### Compilation:
To compile the program:
```bash
g++ -std=c++20 -o day2_solution main.cpp