/*****************************************************************************
ejector-gui, A simple GUI to eject and insert multiple CD/DVD tray
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QAction>
#include <QMenu>
#include <QIcon>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void manageEject();
    void manageInsert();

private:
    Ui::MainWindow *ui;
    QMenu *trayIconMenu;
    QAction *eject_close;
    QAction *quit;
    QIcon trayIconMain;
    QIcon ejectIcon;
    QIcon quitIcon;
    QIcon closeIcon;
    bool isEjected;
};

#endif // MAINWINDOW_H
