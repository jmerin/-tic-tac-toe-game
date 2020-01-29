#ifndef GAME_H
#define GAME_H
#include <QChar>
#include<QList>

class Game
{
public:
    QChar player,ai;
    int pos[2];

    Game()
    {
        player='X';
        ai='O';
    }
    bool isMoveLeft(QChar board[3][3]);
    int evaluate(QChar board[3][3]);
    int minimax(QChar board[3][3],int depth,bool isMax);
    int * bestmove_ai(QChar board[3][3]);
    void game(QChar board[3][3]);

};

#endif // GAME_H
