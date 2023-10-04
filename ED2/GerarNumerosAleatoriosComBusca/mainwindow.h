#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <conjunto.h>
#include <QMessageBox>
#include <QPixmap>

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
    void on_pushButtonGerar_clicked();

    void on_pushButtonBuscar_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox msgBoxIncluir;
    ped::Conjunto *conjunto;
};
#endif // MAINWINDOW_H
