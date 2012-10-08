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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    isEjected = false;

    eject_close = new  QAction(tr("&Eject"),this);
    quit = new QAction(tr("&Quit"),this);
    trayIconMenu = new QMenu(this);
    trayIconMain = QIcon(QPixmap(":/icon"));
    ejectIcon = QIcon(QPixmap(":/eject"));
    quitIcon = QIcon(QPixmap(":/quit"));
    closeIcon = QIcon(QPixmap(":/close"));

    connect(ui->bClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->bEject, SIGNAL(clicked()), this, SLOT(manageEject()));
    connect(ui->bInsert, SIGNAL(clicked()), this, SLOT(manageInsert()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::manageEject()
{
    if(ui->buttonGroup->checkedButton()->text()=="DVD")
        QProcess::startDetached(QString("eject /dev/sr"+QString::number(ui->comboDVD->currentIndex())).toAscii());
    else
        QProcess::startDetached(QString("eject /dev/cdrom"+QString::number(ui->comboDVD->currentIndex())).toAscii());
}

void MainWindow::manageInsert()
{
    if(ui->buttonGroup->checkedButton()->text()=="DVD")
        QProcess::startDetached(QString("eject -t /dev/sr"+QString::number(ui->comboCD->currentIndex())).toAscii());
    else
        QProcess::startDetached(QString("eject -t /dev/cdrom"+QString::number(ui->comboCD->currentIndex())).toAscii());
}
