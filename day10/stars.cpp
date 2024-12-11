//
// Created by Arsh Tulshyan on 11/12/24.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ (hash2 << 1); // Combine the hashes
    }
};
bool isValid(int row,int col,size_t rows,size_t columns)
{
    if(row>=0&&row<rows&&col<columns&&col>=0)
        return true;
    return false;
}



void calcValues(const pair<int, int>& end,unordered_map<pair<int, int>, bool,pair_hash>& countTrail, const vector<vector<int>> &matrix,int& ans1,int& ans2)
{
    if(matrix[end.first][end.second]==0)
    {
        ans2++;
        if(!countTrail[end])
        {
            countTrail[end]=true;
            ans1++;
        }
        else
            return;
    }
    const vector<pair<int,int> > offsets = {{-1,0},{0,-1},{0,1},{1,0}};
    for(const auto & [fst, snd] : offsets){
        pair<int,int> next = {end.first+fst,end.second+snd};
        if(isValid(next.first,next.second,matrix.size(),matrix[0].size()))
        {
            if(matrix[next.first][next.second]==matrix[end.first][end.second]-1)
                calcValues(next,countTrail,matrix,ans1,ans2);
        }
    }
}
int main()
{
    ifstream fil("/Users/ash/CLionProjects/AdventofCode/day10/input.txt");
    vector<vector<int>> matrix;
    vector<unordered_map<pair<int, int>, bool,pair_hash>> countTrail;
    vector<pair<int, int>> end;
    string line;
    while (getline(fil, line))
    {
        istringstream iss(line);
        vector<int> row;
        char i;
        while(iss>>i)
        {
            row.push_back(i-'0');
            if(i-'0'==9)
            {
                countTrail.emplace_back();
                end.emplace_back(matrix.size(),row.size()-1);

            }
        }
        matrix.emplace_back(row);
    }
    fil.close();
    int ans1= 0,ans2=0;
    for(int i = 0; i<end.size(); i++)
    {
        calcValues(end[i],countTrail[i],matrix,ans1,ans2);
    }
    cout<<ans1<<endl;
    cout<<ans2<<endl;

}