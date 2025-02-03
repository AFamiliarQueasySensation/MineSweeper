#ifndef MAIN_WINDOW_H_
#define MAIN_WINDOW_H_

#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <ui_mainwindow.h>
#include <QSignalMapper>
#include <iostream>
#include <QMap>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QApplication>
#include <QGridLayout>
#include "pushbutton.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void randomBombMaker();
    ~MainWindow();

public slots:
    // Listener Events
    void onRightMouseClicked(int num_button);
    void onLeftMouseClicked(int num_button);
    void onRightClicked0();
    void onLeftClicked0();

private:
    Ui::MainWindow ui;
    void findOtherEmptySquares(int num_button);
    void loseMenu();
    void winMenu();
    void restartGame();
    inline void checkWin();

    int win_counter;

protected:
    QMap<int, PushButton *> push_button_map;
};

#endif // MAIN_WINDOW_H_
