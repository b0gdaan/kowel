#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>  // Добавьте это включение для доступа к qDebug()

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentValue = 0.0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString enteredText = ui->lineEdit->text();
    double enteredNumber = enteredText.toDouble();
    currentValue += enteredNumber * 1;

    QString resultText = QString::number(currentValue);
    ui->label_6->setText("Евро: " + resultText);

    qDebug() << "Button 1 clicked. Current value: " << currentValue;
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString enteredText = ui->lineEdit->text();
    double enteredNumber = enteredText.toDouble();
    currentValue += enteredNumber * -1;

    QString resultText = QString::number(currentValue);
    ui->label_6->setText("Евро: " + resultText);

    qDebug() << "Button 2 clicked. Current value: " << currentValue;
    ui->lineEdit->clear();
}
