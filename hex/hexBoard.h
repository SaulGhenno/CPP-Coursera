#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

enum class player{WHITE, BLACK};

class hexBoard
{
    public:
        hexBoard() {}
        hexBoard(int size): size(size), board(size, vector<char>(size, '~')){
            edgeLines = "\\";
            for (int i = 1; i < size; i++)
            {
                edgeLines += " / \\";
            }
        }
        void printBoard();
        bool makeAMove(int x, int y, player p); //place
        
        vector<pair<int,int>> emptySlots();
        bool badMove(int x, int y);

        bool win(int x, int y);

    private:
        //private variables
        vector<vector<char>> board;
        int size;
        const static char empty = '~';
        const static char black = 'O';
        const static char white = 'X';
        string edgeLines;
        const static int directions[6][2];
        //private functions
        void checkBorders(int x, int y, vector<bool> &flags, char turn);
        bool validMove(int x, int y);
};