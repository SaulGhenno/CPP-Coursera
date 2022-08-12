#include "AI.h"

using namespace std;

void Game::computerTurn()
{
    cout << "Player WHITE turn ";
    auto move = robotAI.next(board, computer);
    board.makeAMove(move.first, move.second, computer);
    cout << move.first << " " << move.second << endl;
    board.printBoard();
}

double AI::bestValue(hexBoard& board, player p)
{
    auto empty = board.emptySlots();
    int winCount = 0;
    vector<int> perm(empty.size());
    for (int i = 0; i < perm.size(); i++)
        perm[i] = i;
    for(int n = 0; n < 1000; n++)
    {
        for(int i = perm.size(); i > 1; --i)
        {
            int swap = rand() % i;
            int temp = perm[i-1];
            perm[i-1] = perm[swap];
            perm[swap] = temp;
        }
        for(int i = 0; i < perm.size(); ++i)
        {
            int x = empty[perm[i]].first;
            int y = empty[perm[i]].second;
            board.makeAMove(x,y,p);
        }
        if(p == player::WHITE)
            winCount++;
        for(auto itr = empty.begin(); itr != empty.end(); ++itr)
            board.badMove(itr->first, itr->second);
    }
    return static_cast<double>(winCount)/1000;
}

pair<int, int> AI::next(hexBoard& board, player p)
{
    auto empty = board.emptySlots();
    double bestMove = 0;
    pair<int, int> move = empty[0];

    for(int i = 0; i < empty.size(); ++i)
    {
        int x = empty[i].first;
        int y = empty[i].second;
        board.makeAMove(x, y, p);
        double moveValue = bestValue(board, p);

        if (moveValue > bestMove)
        {
            move = empty[i];
            bestMove = moveValue;
        }
        board.badMove(x, y);
    }
    return move;
}