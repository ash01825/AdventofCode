//
// Created by Arsh Tulshyan on 06/12/24.
//
//
// Created by Arsh Tulshyan on 06/12/24.
//
#include <fstream>
#include <iostream>
using namespace std;
bool isValid(int row,int col,size_t rows,size_t columns)
{
    if(row>=0&&row<rows&&col<columns&&col>=0)
        return true;
    return false;
}
void turnRight(bool &left,bool &right,bool &up,bool &down)
{
    if(left)
    {
        left=false;
        up = true;
    }
    else if(right)
    {
        right=false;
        down=true;
    }
    else if(up)
    {
        up=false;
        right=true;
    }
    else if(down)
    {
        down=false;
        left=true;
    }
}
void moveBack(pair<size_t,size_t> &pos, const bool &left, const bool &right, const bool &up, const bool &down)
{
    if(left)
        pos.second++;
    else if(right)
        pos.second--;
    else if(up)
        pos.first++;
    else if(down)
        pos.first--;
}
void moveFront(pair<size_t,size_t> &pos, const bool &left, const bool &right, const bool &up, const bool &down)
{
    if(left)
        pos.second--;
    else if(right)
        pos.second++;
    else if(up)
        pos.first--;
    else if(down)
        pos.first++;
}

int move(vector<vector<char>> &matrix,pair<size_t,size_t> &pos,bool &left,bool &right,bool &up,bool &down)
{
    int count = 0;
    const size_t rows = matrix.size();
    const size_t columns = matrix[0].size();
    while(isValid(pos.first,pos.second,rows,columns))
    {
        if(matrix[pos.first][pos.second]=='.' || matrix[pos.first][pos.second]=='^')
        {
            matrix[pos.first][pos.second]='X';
            count+=1;
        }
        if(matrix[pos.first][pos.second]=='X')
            moveFront(pos,left,right,up,down);
        else if(matrix[pos.first][pos.second]=='#')
        {
            moveBack(pos,left,right,up,down);
            turnRight(left,right,up,down);
        }
    }
    return count;
}

int numOfPositions(vector<vector<char>> &matrix,pair<size_t,size_t> &pos)
{
    int sum=0;
    bool right=false;
    bool down=false;
    bool up=true;
    bool left=false;
    size_t rows = matrix.size();
    size_t columns = matrix[0].size();
    return move(matrix,pos,left,right,up,down);


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream f("/Users/ash/CLionProjects/AdventofCode/day6/input.txt");
    string text;
    vector<vector<char> > matrix;
    pair<size_t,size_t> positions;
    while(getline(f, text)){
        matrix.emplace_back();  // Add a new row
        for(char c : text)
        {
            matrix.back().push_back(c);
            if(c=='^')
            {
                positions.first= matrix.size()-1;
                 positions.second= matrix[positions.first].size()-1;
            }
        }
        // Push characters to the last row
    }
    cout<<numOfPositions(matrix,positions)<<endl;




}