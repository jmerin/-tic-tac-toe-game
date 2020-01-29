#ifndef BOARD_H
#define BOARD_H
#include <QChar>

class Board
{
public:
    QChar board[3][3];
    Board()
    {
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                board[i][j]='_';
    }


};




#endif // BOARD_H
