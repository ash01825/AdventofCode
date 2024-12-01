//
// Created by Arsh Tulshyan on 02/12/24.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    vector<int> a, b;
    a.reserve(1000);
    b.reserve(1000);

    int x, y;
    while (input >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }

    input.close();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int sum = 0;
    for (int i = 0; i < 1000; ++i) {
        sum += abs(a[i] - b[i]);
    }

    int score = 0, j = 0, prev_score = 0;
    for (int i = 0; i < 1000; ++i) {
        if (i > 0 && a[i] == a[i - 1]) {
            score += prev_score;
            continue;
        }

        int count = 0;
        while (j < 1000 && b[j] <= a[i]) {
            if (b[j] == a[i]) count++;
            j++;
        }
        prev_score = a[i] * count;
        score += prev_score;
    }

    cout << sum << endl;
    cout << score << endl;

    return 0;
}