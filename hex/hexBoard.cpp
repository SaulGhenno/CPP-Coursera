#include "hexBoard.h"

using namespace std;

void hexBoard::printBoard()
{    
    cout << board[0][0];
    for(int j=1; j<size; ++j)
        cout << " - " << board[0][j];
    cout << endl;
    string space = "";
    for (int i=1; i<size; ++i)
    {
        space += ' ';
        cout << space << edgeLines << endl;
        space += ' ';
        cout << space << board[i][0];
        for (int j = 1; j < size; j++)
            cout << " - " << board[i][j];
        cout << endl;
    }
}

bool hexBoard::validMove(int x, int y)
{
    return x >= 0 && x < size && y >= 0 && y < size;
}

bool hexBoard::makeAMove(int x, int y, player p)
{
    if (validMove(x, y) == false)
        return false;

    if (board[x][y] != empty)
        return false;

    if (p == player::BLACK)
        board[x][y] = black;
    else if (p == player::WHITE)
        board[x][y] = white;

    return true;
}

const int hexBoard::directions[6][2] = 
{
    {-1, 0}, // top left
    {-1, 1}, // top right
	{0, -1}, // left
    {0, 1},  // right
	{1, -1}, // buttom left
    {1, 0}   // buttom right
};

void hexBoard::checkBorders(int x, int y, vector<bool> &flags, char turn)
{
    if (turn == black)
    {
        if (y == 0)
            flags[0] = true;
        if (y == size - 1)
            flags[1] = true;
    }
    else if (turn == white)
    {
        if (x == 0)
            flags[0] = true;
        if (x == size - 1)
            flags[1] = true;
    }
}

vector<pair<int, int>> hexBoard::emptySlots()
{
    vector<pair<int, int>> emptyCells;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
            if(board[i][j] == empty)
                emptyCells.push_back(make_pair(i, j));
    }
    return emptyCells;
}

bool hexBoard::badMove(int x, int y)
{
    if(validMove(x,y))
    {
        board[x][y] = empty;
        return true;
    }
    return false;
}

bool hexBoard::win(int x, int y)
{
    if (validMove(x, y) == false || board[x][y] == empty)
        return false;
    
    char turn = board[x][y];
    vector<bool> flags(2, false);
    vector<vector<bool>> visited(size, vector<bool>(size));
    queue<pair<int, int>> positions;
    
    positions.push(make_pair(x, y));
    visited[x][y] = true;

    while(!positions.empty())
    {
        auto first = positions.front();
        checkBorders(first.first, first.second, flags, turn);
        positions.pop();

        for (int i = 0; i < 6; ++i)
        {
            int curX = first.first + directions[i][0];
            int curY = first.second + directions[i][1];
            if (validMove(curX, curY) && board[curX][curY] == turn && visited[curX][curY] == false)
            {
                visited[curX][curY] = true;
                positions.push(make_pair(curX, curY));
            }
        }
    }

    return flags[0] && flags[1];
}

