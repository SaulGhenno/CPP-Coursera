#include <iostream>
#include "hexBoard.cpp"

using namespace std;

class AI // based on montecarlo simulation, more below
{
    public:
        static double bestValue(hexBoard &board, player p);
        pair<int, int> next(hexBoard &board, player p);
};

class Game
{
    public:
        Game() {}
        Game(AI &robotAI) : robotAI(robotAI) {}
        void play();
        void computerTurn();

    private:
        player computer = player::WHITE;
        player player = player::BLACK;
        AI robotAI;
        hexBoard board;    
};