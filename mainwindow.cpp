#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString text = ui->INPUT_text->toPlainText();

    PermutationCipher sh;

    switch (ui->comboBox->currentIndex())
    {
    case 0:
        text = sh.coding(text);
        break;
    case 1:
        text = sh.decoding(text);
        break;
    default:
        text = " ";
        break;
    }

    ui->OUTPUT_text->setPlainText(text);
}
