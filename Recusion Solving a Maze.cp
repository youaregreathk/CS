#include <iostream>
using namespace std;
bool pathExists(char maze[][10], int sr, int sc, int er, int ec);
int main()
{
    char maze[10][10] = {
        { 'X','X','X','X','X','X','X','X','X','X'},
        { 'X','.','.','.','.','.','.','.','.','X'},
        { 'X','X','.','X','.','X','X','X','X','X'},
        { 'X','.','.','X','.','X','.','.','.','X'},
        { 'X','.','.','X','.','.','.','X','.','X'},
        { 'X','X','X','X','.','X','X','X','.','X'},
        { 'X','.','X','.','.','.','.','X','X','X'},
        { 'X','.','.','X','X','.','X','X','.','X'},
        { 'X','.','.','.','X','.','.','.','.','X'},
        { 'X','X','X','X','X','X','X','X','X','X'}
    };
    
   // if (pathExists(maze, 6,4, 1,1));
    //if (pathExists(maze, 6,4, 1,1))
    if (pathExists(maze, 1,1, 4,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
    
}

bool pathExists(char maze[][10], int be_x, int be_y, int end_x, int end_y)
{
    if(be_x==end_x&&be_y==end_y)
        return true;
    maze[be_x][be_y]='#';
    
    if(maze[be_x-1][be_y]=='.'&& pathExists(maze,be_x-1,be_y,end_x,end_y))
        return true;
    
    if(maze[be_x+1][be_y]=='.'&&pathExists(maze,be_x+1,be_y,end_x,end_y))
       return true;
    
    if(maze[be_x][be_y-1]=='.'&&pathExists(maze,be_x,be_y-1,end_x,end_y))
       return true;
    
    if(maze[be_x][be_y+1]=='.'&&pathExists(maze,be_x,be_y+1,end_x,end_y))
        return true;
    
     return false;
}