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
        sum += (a[i] > b[i]) ? (a[i] - b[i]) : (b[i] - a[i]);
    }

    cout << sum << endl;

    return 0;
}