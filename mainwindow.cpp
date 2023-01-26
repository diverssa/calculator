#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QValidator>

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

double weight;
double high;
double age;
double result;
void MainWindow::on_weight_cursorPositionChanged(int arg1, int arg2)
{
    QRegularExpression rx ("[1-9][0-9][0-9]");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->weight->setValidator(validator);
}


void MainWindow::on_high_cursorPositionChanged(int arg1, int arg2)
{
    QRegularExpression rx ("[1-9][0-9][0-9]");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->high->setValidator(validator);
}


void MainWindow::on_age_cursorPositionChanged(int arg1, int arg2)
{
    QRegularExpression rx ("[1-9][0-9][0-9]");
    QValidator *validator = new QRegularExpressionValidator(rx, this);
    ui->age->setValidator(validator);
}

void MainWindow::inp()
{
    QString el = ui->weight->text();
    weight = el.toInt();
    QString el2 = ui->high->text();
    high = el2.toInt();
    QString el3 = ui->age->text();
    age = el3.toInt();
}
void MainWindow::get_result()
{
    inp();

    if (ui->men->isChecked()) {
        result = 66 + (13.7 * weight) + (5 * high) - (6.8 * age);
    }
    else if (ui->women->isChecked()) {

        result = 665 + (9.6 * weight) + (1.8 * high) - (4.7 * age);
    }
}



void MainWindow::on_pushButton_clicked()
{
    get_result();

    if (ui->comboBox->currentIndex() == 0) {
        result *= 1.20;
    }
    else if (ui->comboBox->currentIndex() == 1) {
        result *= 1.38;
    }
    else if (ui->comboBox->currentIndex() == 2) {
        result *= 1.55;
    }
    else if (ui->comboBox->currentIndex() == 3) {
        result *= 1.73;
    }

    ui->result->setText(QString::number(result));
}







