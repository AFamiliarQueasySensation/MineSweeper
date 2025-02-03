#include <iostream>
#include <QApplication>
#include <QMessageBox>
#include <QMainWindow>
#include <fmt/format.h>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   MainWindow window;
   window.show();

   return a.exec();
}