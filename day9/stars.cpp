//
// Created by Arsh Tulshyan on 09/12/24.
//
#include <fstream>
#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
using namespace std::chrono;
void insertIntoSortedDeque(deque<int> &dq, int value) {
    // Find the correct position
    auto it = dq.begin();
    while (it != dq.end() && *it < value) {
        ++it;
    }

    // Insert the value at the correct position
    dq.insert(it, value);
}
long sum(int i,int j)
{
    long c = 0;
    for(int k=0;k<j;k++)
    {
        c+=i;
        i++;
    }
    return c;
}
long ans2(vector<int> & f,vector<deque<int> > & s_size,vector<vector<int>> &space_values)
{
    int file = f.size();
    vector<bool> shifted(file,false);
    for(int i = file-1; i > 0; i--)
    {
        int j = f[i];
        int k = INT_MAX;
        int l=0;
        for(int m = 9; m >= j; m--)
        {
            if(!s_size[m].empty())
            {
                int z = s_size[m].front();
                if(z<k)
                {
                    k = z;
                    l = m;
                }
            }
        }
        if(k<i)
        {
            s_size[l].pop_front();
            if(l>j)
                insertIntoSortedDeque(s_size[l-j],k);
            int w = 0;
            while(j>0)
            {
                if(space_values[k][w]==0)
                {
                    space_values[k][w] = i;
                    j--;
                }
                w++;
            }
            shifted[i]=true;
        }
    }
    long ans = 0;
    long curr = 0;
    for(int i = 0;i<file;i++)
    {
        if(shifted[i])
            curr+=f[i];
        else
        {
            const long count = sum(curr,f[i]);
            curr+=f[i];
            ans+=count*i;
        }
        for(const int j : space_values[i])
        {
            ans+=j*curr;
            curr++;
        }

    }
    return ans;
}
long ans1(const vector<int> & f,const vector<int> & s)
{
    auto file = f;
    auto space = s;
    int i = 0;
    int j = file.size()-1;
    long ans = 0;
    long curr = 0;
    while(i<=j)
    {
        const long count = sum(curr,file[i]);
        curr+=file[i];
        ans+=count*i;
        if(i==j)
            break;
        while(space[i]--)
        {
            while(file[j]==0)
                j--;
            if(i==j)
                break;
            ans+=curr*j;
            file[j]--;
            curr++;
        }
        i++;
    }
    return ans;
}
int main()
{
    auto start = high_resolution_clock::now();
    ifstream f("/Users/ash/CLionProjects/AdventofCode/day9/input.txt");
    string s;
    vector<int> file,space;
    vector<deque<int>> space_size(10);
    vector<vector<int>> space_values;
    getline(f,s);
    istringstream iss(s);
    char a;
    while(iss>>a)
    {
        file.push_back(a-'0');
        if(iss>>a)
        {
            space.push_back(a-'0');
            space_size[a-'0'].push_back(space.size()-1);
            for(int i = 0;i<a-'0';i++)
            {
                space_values.emplace_back();
                space_values[space.size()-1].push_back(0);
            }

        }

    }
    f.close();
    s.clear();
    iss.clear();
    long ans11=ans1(file,space);
    long ans21=ans2(file,space_size,space_values);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<ans11<<endl;
    cout<<ans21<<endl;
    cout << "Time taken by function: "
 << duration.count() << " microseconds" << endl;
    return 0;
}