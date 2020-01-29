#include "tictactoe.h"
#include "ui_tictactoe.h"
#include "board.h"
#include "Game.h"
#include<QMessageBox>
#include<QLabel>

TicTacToe::TicTacToe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TicTacToe)
{
    ui->setupUi(this);
}

TicTacToe::~TicTacToe()
{
    delete ui;
}




Board b;
Game g;

void TicTacToe:: Reset(void)
{

   ui->pushButton_00->setText("");ui->pushButton_00->setEnabled(1);
   ui->pushButton_01->setText("");ui->pushButton_01->setEnabled(1);
   ui->pushButton_02->setText("");ui->pushButton_02->setEnabled(1);
   ui->pushButton_10->setText("");ui->pushButton_10->setEnabled(1);
   ui->pushButton_11->setText("");ui->pushButton_11->setEnabled(1);
   ui->pushButton_12->setText("");ui->pushButton_12->setEnabled(1);
   ui->pushButton_20->setText("");ui->pushButton_20->setEnabled(1);
   ui->pushButton_21->setText("");ui->pushButton_21->setEnabled(1);
   ui->pushButton_22->setText("");ui->pushButton_22->setEnabled(1);
   ui->label_2->setText("Game in progress");

   for(int i=0;i<3;i++)
       for(int j=0;j<3;j++)
          b. board[i][j]='_';
}

void TicTacToe:: Disable(void)
{
 ui->pushButton_00->setEnabled(0);
 ui->pushButton_01->setEnabled(0);
   ui->pushButton_02->setEnabled(0);
   ui->pushButton_10->setEnabled(0);
   ui->pushButton_11->setEnabled(0);
   ui->pushButton_12->setEnabled(0);
   ui->pushButton_20->setEnabled(0);
   ui->pushButton_21->setEnabled(0);
   ui->pushButton_22->setEnabled(0);
}

void TicTacToe::on_pushButton_00_clicked()
{

    ui->pushButton_00->setText("X");
    ui->pushButton_00->setDisabled(1);
    b.board[0][0]='X';

    aimove(b.board);

}

void TicTacToe::on_pushButton_01_clicked()
{
    ui->pushButton_01->setText("X");
    ui->pushButton_01->setDisabled(1);
    b.board[0][1]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_02_clicked()
{
    ui->pushButton_02->setText("X");
    ui->pushButton_02->setDisabled(1);
    b.board[0][2]='X';
    aimove(b.board);

}

//
void TicTacToe::on_pushButton_10_clicked()
{
    ui->pushButton_10->setText("X");
    ui->pushButton_10->setDisabled(1);
    b.board[1][0]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_11_clicked()
{
    ui->pushButton_11->setText("X");
    ui->pushButton_11->setEnabled(0);
    b.board[1][1]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_12_clicked()
{
    ui->pushButton_12->setText("X");
    ui->pushButton_12->setDisabled(1);
    b.board[1][2]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_20_clicked()
{
    ui->pushButton_20->setText("X");
    ui->pushButton_20->setDisabled(1);
    b.board[2][0]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_21_clicked()
{
    ui->pushButton_21->setText("X");
    ui->pushButton_21->setDisabled(1);
    b.board[2][1]='X';
    aimove(b.board);

}

void TicTacToe::on_pushButton_22_clicked()
{
    ui->pushButton_22->setText("X");
    ui->pushButton_22->setDisabled(1);
    b.board[2][2]='X';
    aimove(b.board);

}

int TicTacToe::result(QChar board[3][3])

{

    int result= g.evaluate(board);
    if (result==10)
       {

            ui->label_2->setText("Game Over -You Win");          
            Disable();

        }
    else if(result==-10)
     {

            ui->label_2->setText("Game Over -You Lose");
            Disable();

      }

    else if(result==0 && g.isMoveLeft(board)==false )
    {

            ui->label_2->setText("Game Over -Tie");

    }
return result;
}



void TicTacToe::aimove(QChar board[3][3])
{
   int r= result(b.board);
   if( r==0 && g.isMoveLeft(board)==true)
    {
    //ai move
      int* pos =g.bestmove_ai(board);
      int i=pos[0],j=pos[1];
      board[i][j]='O';


      if(i==0&&j==0)
        {ui->pushButton_00->setText("O");ui->pushButton_00->setDisabled(1);}
      if(i==0&&j==1)
        {ui->pushButton_01->setText("O");ui->pushButton_01->setDisabled(1);}
      if(i==0&&j==2)
        {ui->pushButton_02->setText("O");ui->pushButton_02->setDisabled(1);}
      if(i==1&&j==0)
        {ui->pushButton_10->setText("O");ui->pushButton_10->setDisabled(1);}
      if(i==1&&j==1)
        {ui->pushButton_11->setText("O");ui->pushButton_11->setDisabled(1);}
      if(i==1&&j==2)
        {ui->pushButton_12->setText("O");ui->pushButton_12->setDisabled(1);}
      if(i==2&&j==0)
        {ui->pushButton_20->setText("O");ui->pushButton_20->setDisabled(1);}
      if(i==2&&j==1)
        {ui->pushButton_21->setText("O");ui->pushButton_21->setDisabled(1);}
      if(i==2&&j==2)
        {ui->pushButton_22->setText("O");ui->pushButton_22->setDisabled(1);}
      result(b.board);

}

}

void TicTacToe::on_pushButton_2_clicked()
{
    Reset();
}
