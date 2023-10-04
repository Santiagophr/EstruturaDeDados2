#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "conjunto.h"
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
    void on_pushButtonCriar_clicked();

    void on_pushButtonBuscar_clicked();

    void on_pushButtonBuscarBB_clicked();

    void on_pushButtonBuscarBBRec_clicked();

    void on_lineEditValorBBRec_returnPressed();

    void on_lineEditValorBB_returnPressed();

    void on_lineEditValor_returnPressed();

    void on_lineEditTam_returnPressed();

private:
    Ui::MainWindow *ui;
    Conjunto *BB;
};
#endif // MAINWINDOW_H
