//
// Created by Arsh Tulshyan on 08/12/24.
//
#include <fstream>
#include<vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool isValid(int row,int col,size_t rows,size_t columns)
{
    if(row>=0&&row<rows&&col<columns&&col>=0)
        return true;
    return false;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b,a % b);
}
int countAntenna2(vector<pair<int,int>>& v,vector<vector<char>> &hashVect)
{
    const int size=v.size();
    if(size==1)
        return 0;
    int count=0;
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
        {
            int x = v[j].first - v[i].first;
            int y = v[j].second - v[i].second;
            const int div = gcd(x,y);
            x=x/div;
            y=y/div;
            auto hash1 = v[i];
            auto hash2 = v[j];
            while(isValid(hash1.first,hash1.second,50,50))
            {

                if(hashVect[hash1.first][hash1.second]!='#')
            {
                count++;
                hashVect[hash1.first][hash1.second]='#';
            }
                hash1.first = hash1.first-x;
                hash1.second = hash1.second-y;
            }
            while(isValid(hash2.first,hash2.second,50,50))
            {

                if(hashVect[hash2.first][hash2.second]!='#')
                {
                    count++;
                    hashVect[hash2.first][hash2.second]='#';
                }
                hash2.first = hash2.first+x;
                hash2.second = hash2.second+y;
            }
        }
    return count;
}
int countAntenna(vector<pair<int,int>>& v,vector<vector<char>> &hashVect)
{
    const int size=v.size();
    if(size==1)
        return 0;
    ranges::sort(v, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    int count=0;
    for(int i=0;i<size-1;i++)
        for(int j=i+1;j<size;j++)
        {
            int x = v[j].first - v[i].first;
            int y = v[j].second - v[i].second;
            const pair<int,int> hash1 = {v[i].first-x,v[i].second-y};
            const pair<int,int> hash2 = {v[j].first+x,v[j].second+y};
            if(isValid(hash1.first,hash1.second,50,50))

            {if(hashVect[hash1.first][hash1.second]!='#')
            {
                count++;
                hashVect[hash1.first][hash1.second]='#';
            }
            }
            if(isValid(hash2.first,hash2.second,50,50))
            {if(hashVect[hash2.first][hash2.second]!='#')
            {
                count++;
                hashVect[hash2.first][hash2.second]='#';
            }
            }
        }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream input("/Users/ash/CLionProjects/AdventofCode/day8/input.txt");
    unordered_map<char,vector<pair<int,int>>> map;
    string s;
    vector<vector<char>> v;
    while(getline(input,s))
    {
        stringstream ss(s);
        char token;
        v.emplace_back();
        while(ss>>token)
        {
            v.back().push_back(token);
            if(token!='.')
            {
                map[token].emplace_back(v.size() - 1, v.back().size() - 1);
            }
        }
    }
    // auto hashVect = v;
    int ans = 0,ans2=0;
    for(auto& row:map)
    {
        ans+=countAntenna(row.second,v);
    }
    for(auto& row:map)
    {
        ans2+=countAntenna2(row.second,v);
    }
    cout<<ans<<endl;
    cout<<ans2+ans<<endl;

}