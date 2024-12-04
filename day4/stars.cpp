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

int Xmas(const vector<vector<char> > &matrix,int i,int j,size_t rows,size_t columns)
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
    int count = 0;
    size_t a = matrix.size();
    size_t b = matrix[0].size();
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < b; j++)
            if(matrix[i][j] == 'X')
                count+=Xmas(matrix,i,j,a,b);

    }
    cout << count << endl;
    return 0;
}