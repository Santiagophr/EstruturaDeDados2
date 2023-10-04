#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <conjunto.h>
#include <QMainWindow>
#include <QMessageBox>

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

    void on_pushButtonSequencialAleatorio_clicked();

    void on_pushButtonSequencialOrdenado_clicked();

    void on_pushButtonBinarioOrdenado_clicked();

private:
    Ui::MainWindow *ui;
    QMessageBox msgBoxIncluir;
    ped::Conjunto *conjunto;
};
#endif // MAINWINDOW_H
