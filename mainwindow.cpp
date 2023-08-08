#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentValueEvro    = 0.0;
    currentValueRubl    = 0.0;
    currentValueDinar   = 0.0;

    // Подключение к базе данных
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db"); // Имя файла базы данных

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных!";
    }

    // Создание таблицы, если она не существует
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS my_values (id INTEGER PRIMARY KEY AUTOINCREMENT, value REAL)");

    if (!db.open()) {
        qDebug() << "Ошибка при открытии базы данных: " << db.lastError().text();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString enteredText = ui->lineEdit->text();
    double enteredNumber = enteredText.toDouble();
    currentValueEvro += enteredNumber * 1;

    QString resultText = QString::number(currentValueEvro);
    ui->label_6->setText("Евро: " + resultText);

    qDebug() << "Button 1 clicked. Current value: " << currentValueEvro;
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString enteredText = ui->lineEdit->text();
    double enteredNumber = enteredText.toDouble();
    currentValueEvro += enteredNumber * -1;

    QString resultText = QString::number(currentValueEvro);
    ui->label_6->setText("Евро: " + resultText);

    qDebug() << "Button 2 clicked. Current value: " << currentValueEvro;
    ui->lineEdit->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
    QString enteredText = ui->lineEdit_2->text();
    double enteredNumber = enteredText.toDouble();
    currentValueRubl += enteredNumber * 1;

    QString resultText = QString::number(currentValueRubl);
    ui->label_7->setText("Рубль: " + resultText);

    qDebug() << "Button 7 clicked. Current value: " << currentValueRubl;
    ui->lineEdit_2->clear();
}


void MainWindow::on_pushButton_8_clicked()
{
    QString enteredText = ui->lineEdit_2->text();
    double enteredNumber = enteredText.toDouble();
    currentValueRubl += enteredNumber * -1;

    QString resultText = QString::number(currentValueRubl);
    ui->label_7->setText("Рубль: " + resultText);

    qDebug() << "Button 8 clicked. Current value: " << currentValueRubl;
    ui->lineEdit_2->clear();
}





void MainWindow::on_pushButton_9_clicked()
{
    QString enteredText = ui->lineEdit_3->text();
    double enteredNumber = enteredText.toDouble();
    currentValueDinar += enteredNumber * 1;

    QString resultText = QString::number(currentValueDinar);
    ui->label_2->setText("Динар: " + resultText);

    qDebug() << "Button 9 clicked. Current value: " << currentValueDinar;
    ui->lineEdit_3->clear();
}


void MainWindow::on_pushButton_10_clicked()
{
    QString enteredText = ui->lineEdit_3->text();
    double enteredNumber = enteredText.toDouble();
    currentValueDinar += enteredNumber * -1;

    QString resultText = QString::number(currentValueDinar);
    ui->label_2->setText("Динар: " + resultText);

    qDebug() << "Button 9 clicked. Current value: " << currentValueDinar;
    ui->lineEdit_3->clear();
}

