//
// Created by Arsh Tulshyan on 02/12/24.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int check_safety(const vector<int>& arr, int k) {
    size_t n = arr.size();

    bool increasing = arr[0] < arr[1];
    bool decreasing = arr[0] > arr[1];
    if (!increasing && !decreasing) return 0;

    for (size_t i = 1; i < n - 1; ++i) {
        int diff = arr[i + 1] - arr[i];
        if (increasing && (diff <= 0 || diff >= 4))
            return 0;
        if (decreasing && (diff <= 0 || diff >= 4))
            return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream input("/Users/ash/CLionProjects/AdventofCode/day2/input.txt");
    if (!input.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<vector<int>> matrix;
    matrix.reserve(1000);

    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        vector<int> row;
        int x;
        while (iss >> x) {
            row.push_back(x);
        }
        matrix.push_back(std::move(row));
    }

    input.close();

    int safe = 0;
    for (const auto& row : matrix) {
            safe += check_safety(row,0);

    }

    cout << safe << "\n";
    return 0;
}