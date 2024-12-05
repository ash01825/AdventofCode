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

void merge(const vector<vector<int>> & map, vector<int> & x, int start,int mid,int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    vector<int> y(n1),z(n2);
    for(int i=0;i<n1;i++)
        y[i]=x[start+i];
    for(int i=0;i<n2;i++)
        z[i]=x[mid+i+1];
    int i = 0, j = 0;
    int k = start;
    while(i<n1 && j<n2)
    {
        if(map[y[i]][z[j]]==0)
            x[k++]=y[i++];
        else
            x[k++]=z[j++];
    }
    while(i<n1)
        x[k++]=y[i++];
    while(j<n2)
        x[k++]=z[j++];
}

void merge_sort(const vector<vector<int>> & map, vector<int> & x, int start,int end)
{
    if(start>=end)
        return;
    const int mid = start + (end-start)/2;
    merge_sort(map, x, start, mid);
    merge_sort(map, x, mid+1, end);
    merge(map, x, start, mid, end);
}

int getcorrect(const vector<vector<int>> & map, vector<int> & x,const int size)
{
    merge_sort(map,x,0,size-1);
    return x[size/2];
}

int checkcorrect(const vector<vector<int>>& map, const string& line) {
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
    const int mid = size / 2;
    return b[mid];

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
    int mid;
    while(getline(fin, line))
    {
        mid+= checkcorrect(map, line);
    }
    cout << mid - 4957<< endl;

}