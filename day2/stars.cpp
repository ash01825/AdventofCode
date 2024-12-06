//
// Created by Arsh Tulshyan on 02/12/24.
//


#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
using namespace std::chrono;


int check_safety(vector<int> &arr, bool k)
{
    const size_t n = arr.size();
    if(arr[0] > arr[1] && arr[0] - arr[1]<4)
    {
        for(int i = 0; i < n-1; i++)
            if((arr[i] <= arr[i+1])||arr[i]-arr[i+1]>3)
            {
                if(k)
                {
                    if(i==1)
                {
                    auto  b =  arr;
                    b.erase(b.begin());
                    if(check_safety(b,false)==1)
                        return 1;
                }
                    auto  b =  arr;
                    arr.erase(arr.begin()+i);
                    if(check_safety(arr,false)==1)
                        return 1;
                    b.erase(b.begin()+i+1);
                    return check_safety(b,false);
                }
                return 0;
            }
        return 1;
    }
    if(arr[0] < arr[1] && arr[1] - arr[0]<4)
    {
        for(int i = 1; i < n-1; i++)
            if((arr[i] >= arr[i+1])||arr[i+1]-arr[i]>3)
            {
                if(k)
                {
                    if(i==1)
                    {
                        auto  b =  arr;
                        b.erase(b.begin());
                        if(check_safety(b,false)==1)
                            return 1;
                    }
                    auto  b =  arr;
                    arr.erase(arr.begin()+i);
                    if(check_safety(arr,false)==1)
                        return 1;
                    b.erase(b.begin()+i+1);
                    return check_safety(b,false);
                }
                return 0;
            }

        return 1;
    }
    if(k)
    {
        auto  i =  arr;
        arr.erase(arr.begin());
        if(check_safety(arr,false)==1)
            return 1;
        i.erase(i.begin()+1);
        return check_safety(i,false);
    }


    return 0;
}
int main() {
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream input("/Users/ash/CLionProjects/AdventofCode/day2/input.txt");
    if (!input.is_open()) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }
    vector<vector<int> > matrix(1000);
    string line;
    for (int i = 0; i < 1000; i++) {
        getline(input, line);
        istringstream iss(line);
        int x;
        while(iss>>x)
            matrix[i].push_back(x);
    }
    input.close();
    int safe = 0;
    for (auto& row : matrix)
    {
        safe+=check_safety(row,true);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << safe << "\n";
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
    return 0;
}