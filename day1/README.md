Here’s a detailed README for Day 1: Historian Hysteria:

Day 1: Historian Hysteria 🎄

Problem Statement

The Chief Historian is missing, and your mission is to help the Elvish Senior Historians reconcile two lists of location IDs to search for him. Each list represents historically significant locations, but discrepancies in the lists complicate their search.

The problem is divided into two parts:
1.	Calculate the total distance between the two lists.
2.	Determine the similarity score by analyzing how often numbers in the left list appear in the right list.

Part 1: Total Distance Calculation

Objective: Pair the numbers from the two lists in ascending order and calculate the sum of their absolute differences.

Example

Input Lists:
Left: 3, 4, 2, 1, 3, 3
Right: 4, 3, 5, 3, 9, 3

Steps:
1.	Sort both lists:
•	Left: 1, 2, 3, 3, 3, 4
•	Right: 3, 3, 3, 4, 5, 9
2.	Pair numbers and compute distances:
•	(1, 3) → |1 - 3| = 2
•	(2, 3) → |2 - 3| = 1
•	(3, 3) → |3 - 3| = 0
•	(3, 4) → |3 - 4| = 1
•	(3, 5) → |3 - 5| = 2
•	(4, 9) → |4 - 9| = 5
3.	Total Distance: 2 + 1 + 0 + 1 + 2 + 5 = 11

Part 2: Similarity Score Calculation

Objective: Calculate a score by summing up each number in the left list multiplied by the number of times it appears in the right list.

Example

Input Lists:
Left: 3, 4, 2, 1, 3, 3
Right: 4, 3, 5, 3, 9, 3

Steps:
1.	Count occurrences in the right list:
•	3 → 3 times
•	4 → 1 time
•	Other numbers → 0 times
2.	Compute scores for each number in the left list:
•	3 → 3 * 3 = 9
•	4 → 4 * 1 = 4
•	2 → 2 * 0 = 0
•	1 → 1 * 0 = 0
•	3 → 3 * 3 = 9
•	3 → 3 * 3 = 9
3.	Similarity Score: 9 + 4 + 0 + 0 + 9 + 9 = 31

Implementation

Solutions are implemented in C++, leveraging efficient sorting and counting algorithms.

File: day01/solution.cpp

	•	Input: Two lists of integers (provided as puzzle input).
	•	Output:
	•	Total distance between the lists (Part 1).
	•	Similarity score of the lists (Part 2).

Usage

Compile and run the solution:

g++ -std=c++17 solution.cpp -o solution && ./solution