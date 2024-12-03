//
// Created by Arsh Tulshyan on 04/12/24.
//
#include <fstream>
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream input("/Users/ash/CLionProjects/AdventofCode/day3/input.txt");
    if (!input.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    string word;
    unsigned int ans = 0;

    while (input >> word) {
        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == 'm')
            {
                if(word[i + 1] == 'u')
                {
                    if(word[i + 2] == 'l')
                    {
                        if(word[i + 3] == '('){
                            string numChar1, numChar2;

                            size_t j = i + 4;
                            while (j < word.length() && word[j] != ',' && word[j] != ')') {
                                if (!isdigit(word[j]))
                                {
                                    i=j-1;
                                    continue;
                                }
                                numChar1 += word[j];
                                j++;
                            }

                            j++;

                            while (j < word.length() && word[j] != ')') {
                                if (!isdigit(word[j]))
                                {
                                    i=j-1;
                                    continue;
                                }
                                numChar2 += word[j];
                                j++;
                            }
                            int num1 = stoi(numChar1);
                            int num2 = stoi(numChar2);
                            ans += num1 * num2;

                            i = j;
                        }
                        else
                            i+=2;
                    }
                    else
                        i++;

                }
            }
        }
    }
    cout << "The result is: " << ans << endl;

    return 0;
}