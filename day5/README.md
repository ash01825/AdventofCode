# Advent of Code 2024 - Day 5: Print Queue

## Problem Description

The North Pole printing department is under pressure as the engineers update the sleigh launch safety manuals. However, the page ordering isn't working as expected, and it's your job to help organize the page order correctly based on the specified rules.

### Part One: Check Correct Order of Updates
The first part of the task is to check which updates are already printed in the correct order. You are provided with two sections:
1. **Page Ordering Rules:** A list of dependencies in the format `X|Y`, meaning page `X` must appear before page `Y` if both pages are present.
2. **Page Updates:** A series of page numbers to be printed in order.

You need to determine which updates are printed in the correct order by checking whether the page numbers follow the rules in the provided order.

#### Example Input:

47|53

97|13

97|61

97|47

75|29

61|13

75|53

29|13

97|29

53|29

61|53

97|53

61|29

47|13

75|47

97|75

47|61

75|61

47|29

75|13

53|13

75,47,61,53,29
97,61,53,29,13
75,29,13
75,97,47,61,53
61,13,29
97,13,75,29,47

#### Explanation:
The first section specifies the rules, such as "47|53", meaning page 47 must be printed before page 53. The second section specifies the pages to be printed in each update.

For example, the first update `75,47,61,53,29` is already in the correct order because it follows the rules. For this update:
- Page 75 is before 47, 61, 53, and 29.
- Page 47 is before 61, 53, and 29.
- Page 61 is before 53 and 29.
- Page 53 is before 29.

For Part One, find all updates that follow the rules, and calculate the middle page number from those updates.

### Part Two: Correct the Order of Updates
In Part Two, you need to correct the order of the incorrectly ordered updates using the page ordering rules. After correcting the order of the pages in each update, calculate the middle page number from each updated list.

#### Example of Correction:
1. `75,97,47,61,53` becomes `97,75,47,61,53`.
2. `61,13,29` becomes `61,29,13`.
3. `97,13,75,29,47` becomes `97,75,47,29,13`.

Then, calculate the middle page numbers from the corrected lists.

---

## Solution

### Approach:
1. **Part One:**
    - Parse the input to extract page ordering rules and updates.
    - Check each update for correctness by comparing the page numbers against the given rules.
    - Calculate the middle page number for correctly ordered updates.

2. **Part Two:**
    - For incorrectly ordered updates, use a sorting algorithm based on the page ordering rules to correct the order.
    - Calculate the middle page number for each corrected update.

---

## Implementation

### Files:
- **`main.cpp`**: Contains the solution logic for parsing, checking, and sorting.
- **`input.txt`**: The puzzle input data.

### Compilation:
To compile the program:

```bash
g++ -std=c++20 -o day5_solution main.cpp