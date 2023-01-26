#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_men_clicked();
    void on_women_clicked();
    void inp();
    void on_weight_cursorPositionChanged(int arg1, int arg2);
    void get_result();
    void on_high_cursorPositionChanged(int arg1, int arg2);
    void on_age_cursorPositionChanged(int arg1, int arg2);



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
