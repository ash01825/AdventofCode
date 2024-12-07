//
// Created by Arsh Tulshyan on 07/12/24.
//
#include <fstream>
#include<vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

bool opTrue1(const long a, const vector<int> &array,size_t u)
{
    if(u==0)
    {
        if(a==0)
            return true;
        return false;
    }
    if(u==1)
        return opTrue1(a - array[u-1],array,u-1);
    const float remain = a%array[u-1];
    if(remain==0)
    {
        if(opTrue1(a/array[u-1],array,u-1))
            return true;
    }
    return opTrue1(a - array[u-1],array,u-1);
}
int countDigits(const int number) {
    return to_string(abs(number)).length();
}
bool opTrue2(const long a, const vector<int> &array,size_t u)
{
    if(u==0)
    {
        if(a==0)
            return true;
        return false;
    }
    if(u==1)
        return opTrue2(a - array[u-1],array,u-1);
    const float remain = a%array[u-1];
    if(remain==0)
    {
        if(opTrue2(a/array[u-1],array,u-1))
            return true;
    }
    if(opTrue2(a - array[u-1],array,u-1))
            return true;
    int divide = pow(10,countDigits(array[u-1]));
    if(a%divide==array[u-1])
        return opTrue2(a/divide,array,u-1);
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream f("/Users/ash/CLionProjects/AdventofCode/day7/input.txt");
    int n;
    string text;
    vector<long> nums(850);
    vector<vector<int>> array(850);
    int i = 0;
    while(getline(f,text))
    {
        istringstream iss(text);
        long a;
        int b;
        char c;
        iss>>a>>c;
        nums[i]=a;
        while(iss>>b)
        {
            array[i].push_back(b);
        }
        i++;
    }
    long sum1 = 0,sum2 = 0;
    for(i=0;i<850;i++)
    {
        if(opTrue1(nums[i],array[i],array[i].size()))
            sum1+=nums[i];
        if(opTrue2(nums[i],array[i],array[i].size()))
            sum2+=nums[i];
    }
    cout<<sum1<<endl;
    cout<<sum2<<endl;

}