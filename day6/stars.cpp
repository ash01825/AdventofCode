//
// Created by Arsh Tulshyan on 06/12/24.
//
#include <fstream>
#include <iostream>
using namespace std;
using namespace std::chrono;
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
int moveAdd(vector<vector<char>> &matrix,pair<size_t,size_t> &pos)
{
    int count = 0;
    bool right=false;
    bool down=false;
    bool up=true;
    bool left=false;
    const size_t rows = matrix.size();
    const size_t columns = matrix[0].size();
    while(isValid(pos.first,pos.second,rows,columns))
    {
        if(matrix[pos.first][pos.second]=='.' || matrix[pos.first][pos.second]=='^')
        {
            matrix[pos.first][pos.second]='X';
            count = 0;
        }
        if(matrix[pos.first][pos.second]=='X')
        {
            moveFront(pos,left,right,up,down);
            count++;
        }
        else if(matrix[pos.first][pos.second]=='#')
        {
            moveBack(pos,left,right,up,down);
            turnRight(left,right,up,down);
            count--;
        }
        if(count==131)
            return 1;
    }
    return 0;
}
vector<pair<size_t,size_t>> moveVisited(vector<vector<char>> &matrix,pair<size_t,size_t> &pos)
{
    vector<pair<size_t,size_t>> visited;
    bool right=false;
    bool down=false;
    bool up=true;
    bool left=false;
    const size_t rows = matrix.size();
    const size_t columns = matrix[0].size();
    while(isValid(pos.first,pos.second,rows,columns))
    {
        if(matrix[pos.first][pos.second]=='.' || matrix[pos.first][pos.second]=='^')
        {
            matrix[pos.first][pos.second]='X';
            visited.emplace_back(pos.first,pos.second);
        }
        if(matrix[pos.first][pos.second]=='X')
            moveFront(pos,left,right,up,down);
        else if(matrix[pos.first][pos.second]=='#')
        {
            moveBack(pos,left,right,up,down);
            turnRight(left,right,up,down);
        }
    }
    return visited;
}

int bruteforce(vector<vector<char>> &matrix,pair<size_t,size_t> &pos,vector<pair<size_t,size_t>> &visited)
{
    int count = 0;
    for(int row=1;row<visited.size();row++)
    {
        auto tempMat = matrix;
        tempMat[visited[row].first][visited[row].second]='#';
        auto tempPos = pos;
        count+=moveAdd(tempMat,tempPos);
    }
    return count;

}
int main()
{
    auto start = high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    auto tempMat = matrix;
    auto tempPos = positions;
    auto visited = moveVisited(tempMat,tempPos);
    cout<<visited.size()<<endl;
    cout<<bruteforce(matrix,positions,visited)<<endl;
    cout << "Time taken by function: "
     << duration.count() << " microseconds" << endl;




}