#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool isValid(int row,int col,size_t rows,size_t columns)
{
    if(row>=0&&row<rows&&col<columns&&col>=0)
        return true;
    return false;
}

int Xmas1(const vector<vector<char> > &matrix, const int i, const int j, const size_t rows, const size_t columns)
{
    int count=0;
    vector<pair<int,int> > offsets = {{-1,-1}, {-1,0}, {-1,1},{0,-1}, {0,1},{1,-1}, {1,0}, {1,1}};
    for (const auto& [a1, b1] : offsets) {
        int my = i + a1;
        int mx = j + b1;
        if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='M'))
        {
            my = my + a1;
            mx = mx + b1;
            if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='A'))
            {
                my = my + a1;
                mx = mx + b1;
                if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='S')){

                    count++;}
            }
        }
    }
    return count;
}

int Xmas2(const vector<vector<char> > &matrix,const int i, const int j,const size_t rows,const
    size_t columns)
{
    int count=0;
    const vector<pair<int,int> > offsets = {{-1,-1}, {-1,1}, {1,1},  {1,-1}};
    for (int c = 0; c<2; c++) {
        int my = i + offsets[c].first;
        int mx = j + offsets[c].second;
        if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='M'))
        {
            my = i + offsets[c+2].first;
            mx = j + offsets[c+2].second;
            if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='S'))
                count++;
        }
        else if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='S'))
        {
            my = i + offsets[c+2].first;
            mx = j + offsets[c+2].second;
            if(isValid(my,mx,rows,columns)&&(matrix[my][mx]=='M'))
                count++;
        }
    }
    return count/2;
}


int main()
{
    ifstream f("/Users/ash/CLionProjects/AdventofCode/day4/input.txt");
    string text;
    vector<vector<char> > matrix;

    while(getline(f, text)){
        matrix.push_back(vector<char>());  // Add a new row
        for(char c : text)
            matrix.back().push_back(c);  // Push characters to the last row
    }
    int count1 = 0;
    int count2 = 0;
    size_t a = matrix.size();
    size_t b = matrix[0].size();
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
        {
            if(matrix[i][j] == 'X')
                count1+=Xmas1(matrix,i,j,a,b);
            if(matrix[i][j] == 'A')
                count2+=Xmas2(matrix,i,j,a,b);
        }


    }
    cout << count1 << endl;
    cout << count2 << endl;
    return 0;
}