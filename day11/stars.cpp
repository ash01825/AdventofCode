//
// Created by Arsh Tulshyan on 11/12/24.
//
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;

void part2Quick(unordered_map<string,long>& numbers1,unordered_map<string, vector<string>>& numbers2)
{
    auto newNumbers = numbers1;
    for(const auto & [fst, snd]:numbers1)
    {
        if(snd == 0)
            continue;
        if(!numbers2[fst].empty())
        {
            for(const auto& p : numbers2[fst])
                newNumbers[p]+=snd;
        }
        else if(fst =="0")
        {
            newNumbers["1"]+=snd;
        }
        else if(fst.size()%2==0)
        {
            string t = fst.substr(fst.size()/2);
            const long z = stoi(t);
            newNumbers[to_string(z)]+=snd;
            numbers2[fst].push_back(to_string(z));
            string s =fst.substr(0,fst.size()/2);
            newNumbers[s]+=snd;
            numbers2[fst].push_back(s);
        }
        else
        {
            long k = stoi(fst);
            k = k*2024;
            newNumbers[to_string(k)]+=snd;
            numbers2[fst].push_back(to_string(k));
        }
        newNumbers[fst]-=snd;
    }
    numbers1 = newNumbers;

}

int main()
{
    auto start = high_resolution_clock::now();
    ifstream fil("/Users/ash/CLionProjects/AdventofCode/day11/input.txt");
    string s;
    getline(fil, s);
    unordered_map<string,long> numbers;
    string temp;
    for (const char ch : s) {
        if (isdigit(ch)) {
            temp += ch; // Build the number string
        } else {
            if (!temp.empty()) {
                numbers[temp]++; // Add completed number to vector
                temp.clear(); // Reset for the next number
            }
        }
    }

    // Add the last number if the string ended with a digit
    if (!temp.empty()) {
        numbers[temp]++;
    }
    unordered_map<string,vector<string>> numbers2;
    for(int i = 0; i < 75; i++)
    {
        part2Quick(numbers,numbers2);
    }
    long ans = 0;
    for(const auto & [fst, snd]:numbers)
        ans+=snd;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<ans<<endl;
    cout << "Time taken by function: "
 << duration.count() << " microseconds" << endl;


}