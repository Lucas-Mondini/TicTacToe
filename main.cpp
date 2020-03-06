#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;
bool winner;
char gameArea[3][3];

int init();
bool check (int X, int Y);
void printInvalidMove();
void show(int round);
bool askContinue();
void checkWinner();
void printWinner(char player);

int main()
{

    int posiX, posiY, round;
    bool game = true;

    while (game){
        round=init();
        while (round <= 9 && !winner){
            posiX = posiY = 0;

            do{
                show(round);
                if (round%2 != 0)
                    cout <<endl << "Player : X" <<endl;

                else
                    cout <<endl << "Player : O" <<endl;

                cout <<"[row]: " ;
                cin  >>posiX;
                cout <<"[column]: " ;
                cin  >>posiY;

            }   while (!check(posiX, posiY));
            if (round%2 != 0)
                gameArea[posiX][posiY] = 'X';
            else
                gameArea[posiX][posiY] = 'O';
            round++;
            if (round > 3)
                    checkWinner();
            if (round == 10 || winner)
                game = askContinue();

        }

    }


    return 0;
}
void show(int round){
        system("cls");
        cout <<"round : " << round <<endl;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                cout <<gameArea[i][j] << " | ";
            }
            cout <<endl;
        }
}

int init(){
        winner = false;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                gameArea[i][j] = ' ';
            }
        }
        return 1;
}
bool check (int X, int Y){
    if ((X < 0 || X > 2) || (Y < 0 || Y > 2) || gameArea[X][Y]!= ' ')
    {
        printInvalidMove();
        return false;
    }
    return true;
}

void printInvalidMove(){
    cout <<"Not a valid movement\n";
    system("pause");

}

bool askContinue(){
    int choice = 0;

    do{
    system("cls");
    cout <<"continue?\n1- Yes\t2- No\n";
    cin  >>choice;

    } while (choice != 1 && choice != 2);

    if (choice == 1 )
        return true;
    return false;
}

void checkWinner(){
    int Xtries = 0, Otries = 0;

    for(int i = 0 ; (i < 3 && !winner); i++){
        for(int j = 0 ; (j < 3 && !winner); j++){

            if (gameArea[i][j] == 'X')
                Xtries ++;

            else if (gameArea[i][j] == 'O')
                Otries++;

            if (Xtries == 3)
                printWinner('X');


            else if (Otries == 3)
                printWinner('O');

        }
        Xtries = Otries = 0;
    }

    for(int i = 0 ; (i < 3 && !winner); i++){
        for(int j = 0 ; (j < 3 && !winner); j++){

            if (gameArea[j][i] == 'X')
                Xtries ++;

            else if (gameArea[j][i] == 'O')
                Otries++;

            if (Xtries == 3){
                printWinner('X');
            }

            else if (Otries == 3){
                printWinner('O');
            }
        }
        Xtries = Otries = 0;
    }

    if (gameArea[1][1] == 'X' && (gameArea[0][0] == 'X' && gameArea[2][2]== 'X') || (gameArea[0][2] == 'X' && gameArea[2][0]== 'X'))
        {
        printWinner('X');
        }
    else if (gameArea[1][1] == 'O' && (gameArea[0][0] == 'O' && gameArea[2][2]== 'O') || (gameArea[0][2] == 'O' && gameArea[2][0]== 'O'))
        {
        printWinner('O');
        }
}

void printWinner(char player){
    system("cls");
    cout << "\nThe Winner is : Player " << player << endl;
    Sleep(2000);
    winner = true;
}

