#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialogButtonBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void questionState();
    void onYesButtonClicked();
    void onNoButtonClicked();
    void onRestartButtonClicked();

private:
    Ui::MainWindow *ui;
    Game *game;
    void initialState();
    void finalState();
    void clearLayout();
};
#endif // MAINWINDOW_H
