//
// Created by Arsh Tulshyan on 05/12/24.
//
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include <sstream>
#include <vector>
#include <ranges>
using namespace std;

int getcorrect(const vector<vector<int>> & map, vector<int> & x,const int size)
{
    ranges::sort(x, [&map](int a, int b) {
        return map[a][b] == 0;
    });
    return x[size/2];
}

int checkcorrect1(const vector<vector<int>>& map, const string& line) {
    vector<int> b;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        int k = stoi(token);
        b.push_back(k);
    }
    const int size = b.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
            if(map[b[i]][b[j]]==1)
                return 0;
    }
    const int mid = size / 2;
    return b[mid];
    }
int checkcorrect2(const vector<vector<int>>& map, const string& line) {
    vector<int> b;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        int k = stoi(token);
        b.push_back(k);
    }
    const int size = b.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
            if(map[b[i]][b[j]]==1)
                return getcorrect(map,b,size);
    }
    return 0;
}
int main()
{
    ifstream fin("/Users/ash/CLionProjects/AdventofCode/day5/input.txt");
    string line;
    vector<vector<int>> map(100, vector<int>(100, 0));
    for(int i = 0; i < 1176; i++)
    {
        getline(fin, line);
        istringstream iss(line);
        int a,b;
        char c;
        iss >> a >> c >> b;
        map[b][a] = 1;
    }

    getline(fin, line);
    int mid1,mid2;
    while(getline(fin, line))
    {
        mid1+= checkcorrect1(map, line);
        mid2+= checkcorrect2(map, line)
    }
    cout << mid1<<endl<< mid2 <<endl;

}
