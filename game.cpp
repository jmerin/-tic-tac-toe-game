#include "board.h"
#include "Game.h"
#include <QMessageBox>
#include "ui_tictactoe.h"

bool Game::isMoveLeft(QChar board[3][3])
{
    for (int i = 0; i<3; i++)
            for (int j = 0; j<3; j++)
                if (board[i][j]=='_')
                    return true;
    return false;
}

 int Game::evaluate(QChar board[3][3])
 {
     // Checking for Rows for X or O victory.
         for (int row = 0; row<3; row++)
         {
             if (board[row][0]!='_'&& board[row][0]==board[row][1] && board[row][1]==board[row][2])
             {
                 if (board[row][0]==player)
                     return +10;
                 else if (board[row][0]==ai)
                     return -10;
             }
         }

         // Checking for Columns for X or O victory.
         for (int col = 0; col<3; col++)
         {
             if (board[0][col]!='_' && board[0][col]==board[1][col] && board[1][col]==board[2][col])
             {
                 if (board[0][col]==player)
                     return +10;

                 else if (board[0][col]==ai)
                     return -10;
             }
         }

         // Checking for Diagonals for X or O victory.
         if (board[0][0]!='_'&& board[0][0]==board[1][1] && board[1][1]==board[2][2])
         {
             if (board[0][0]==player)
                 return +10;
             else if (board[0][0]==ai)
                 return -10;
         }

         if (board[0][2]!='_' && board[0][2]==board[1][1] && board[1][1]==board[2][0])
         {
             if (board[0][2]==player)
                 return +10;
             else if (board[0][2]==ai)
                 return -10;
         }

         // Else if none of them have won then return 0
         return 0;

 }


 int Game:: minimax(QChar board[3][3],int depth,bool isMax)
 {
         int score = evaluate(board);

         // If Maximizer has won the game return his/her
         // evaluated score
         if (score == 10)
             return score;

         // If Minimizer has won the game return his/her
         // evaluated score
         if (score == -10)
             return score;

         // If there are no more moves and no winner then
         // it is a tie
         if (isMoveLeft(board)==false)
             return 0;

         // If this maximizer's move
         if (isMax)
         {
             int best = -1000;

             // Traverse all cells
             for (int i = 0; i<3; i++)
             {
                 for (int j = 0; j<3; j++)
                 {
                     // Check if cell is empty
                     if (board[i][j]=='_')
                     {
                         // Make the move
                         board[i][j] = player;

                         // Call minimax recursively and choose
                         // the maximum value
                         best = qMax( best, minimax(board, depth+1, !isMax) );

                         // Undo the move
                         board[i][j] = '_';
                     }
                 }
             }
             return best;
         }

         // If this minimizer's move
         else
         {
             int best = 1000;

             // Traverse all cells
             for (int i = 0; i<3; i++)
             {
                 for (int j = 0; j<3; j++)
                 {
                     // Check if cell is empty
                     if (board[i][j]=='_')
                     {
                         // Make the move
                         board[i][j] = ai;

                         // Call minimax recursively and choose
                         // the minimum value
                         best = qMin(best, minimax(board, depth+1, !isMax));

                         // Undo the move
                         board[i][j] = '_';
                     }
                 }
             }
             return best;
         }
}


 int* Game::bestmove_ai(QChar board[3][3])
  {
         int bestVal = 1000;
         pos[0] = -1;
         pos[1] = -1;

         // Traverse all cells, evaluate minimax function for
         // all empty cells. And return the cell with optimal
         // value.
         for (int i = 0; i<3; i++)
         {
             for (int j = 0; j<3; j++)
             {
                 // Check if cell is empty
                 if (board[i][j]=='_')
                 {
                     // Make the move
                     board[i][j] = ai;

                     // compute evaluation function for this
                     // move.
                     int moveVal = minimax(board, 0, true);

                     // Undo the move
                     board[i][j] = '_';

                     // If the value of the current move is
                     // more than the best value, then update
                     // best value
                     if (moveVal < bestVal)
                     {
                         pos[0] = i;
                         pos[1] = j;
                         bestVal = moveVal;
                     }
                 }
             }
         }


         return pos;
     }

