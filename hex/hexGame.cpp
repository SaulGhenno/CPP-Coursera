
#include "hexBoard.cpp"

using namespace std;

void play(int SIZE, int turn, int x, int y, hexBoard board)
{
    while (true)
    {
        turn = !turn;
        if (turn == 1)
        {
            do
            {
                x = rand() % SIZE;
                y = rand() % SIZE;
            } while (!board.makeAMove(x, y, player::WHITE));
            cout << "Player White move: (" << x + 1 << ", " << y + 1 << ")" << endl;
        }
        else
        {
            do
            {
                cout << "Where you want to play your move? y: ";
                cin >> x;
                cout << " x: ";
                cin >> y;
            } while (!board.makeAMove(x, y, player::BLACK));
            cout << "Player Black move: (" << x << ", " << y << ")" << endl;
            board.printBoard();
        }

        if (board.win(x, y))
        {
            cout << (turn ? "White" : "Black") << " WIN!!!" << endl;
            board.printBoard();
            break;
        }
    }
}

int main()
{
    int SIZE;
    int turn = 0;
    int x, y;
    srand(time(0));

    cout << "<<<<<<<<<<<<<<<<<<<<<<<< HEX Game >>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "Size of the board: ";
    cin >> SIZE;

    hexBoard board(SIZE);
    board.printBoard();

    //start game
    play(SIZE, turn, x, y, board);

    return 0;
}