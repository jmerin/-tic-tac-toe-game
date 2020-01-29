#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class TicTacToe; }
QT_END_NAMESPACE

class TicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr);
    ~TicTacToe();

private slots:
    void on_pushButton_20_clicked();

    void on_pushButton_00_clicked();

    void on_pushButton_01_clicked();

    void on_pushButton_02_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();
    void on_pushButton_2_clicked();

public:
    void aimove(QChar board[3][3]);
    int result(QChar board[3][3]);
    void Reset(void);
    void Disable(void);

private:

    Ui::TicTacToe *ui;
};
#endif // TICTACTOE_H
