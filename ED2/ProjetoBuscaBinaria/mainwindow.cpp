#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditTam->setValidator(new QIntValidator(0,999999999));
    ui->lineEditValor->setValidator(new QIntValidator(0,999999999));
    ui->lineEditValorBB->setValidator(new QIntValidator(0,999999999));
    ui->lineEditValorBBRec->setValidator(new QIntValidator(0,999999999));
    ui->lineEditTam->setFocus();
    ui->lineEditValor->setEnabled(false);
    ui->lineEditValorBB->setEnabled(false);
    ui->lineEditValorBBRec->setEnabled(false);
    ui->pushButtonBuscar->setEnabled(false);
    ui->pushButtonBuscarBB->setEnabled(false);
    ui->pushButtonBuscarBBRec->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonCriar_clicked()
{
    try {
        int tamanho = ui->lineEditTam->text().toInt();
        BB = new Conjunto(tamanho);
        ui->textEditSaida->setText(BB->getConjunto());
        BB->SelectionSort();
        ui->lineEditSaidaOrdenada->setText(BB->getConjuntoSort());
        ui->lineEditTam->clear();
        ui->lineEditValor->setEnabled(true);
        ui->lineEditValorBB->setEnabled(true);
        ui->lineEditValorBBRec->setEnabled(true);
        ui->pushButtonBuscar->setEnabled(true);
        ui->pushButtonBuscarBB->setEnabled(true);
        ui->pushButtonBuscarBBRec->setEnabled(true);

    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        int valor = ui->lineEditValor->text().toInt();
        QString saida = "Valor está na posição " + QString::number(BB->buscar(valor));
        ui->lineEditResul->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}


void MainWindow::on_pushButtonBuscarBB_clicked()
{
    try {
        int valorBB = ui->lineEditValorBB->text().toInt();
        QString saida = "Valor está na posição " + QString::number(BB->buscaBinaria(valorBB));
        ui->lineEditResulBB->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}


void MainWindow::on_pushButtonBuscarBBRec_clicked()
{
    try {
        int valorBBRec = ui->lineEditValorBBRec->text().toInt();
        QString saida = "Valor está na posição " + QString::number(BB->buscaBinariaRec(valorBBRec, 0, BB->getTamanho()));
        ui->lineEditResulBBRec->setText(saida);
    } catch (QString &erro) {
        QMessageBox::information(this, "ERRO", erro);
    }
}


void MainWindow::on_lineEditValorBBRec_returnPressed()
{
    ui->pushButtonBuscarBBRec->click();
}


void MainWindow::on_lineEditValorBB_returnPressed()
{
    ui->pushButtonBuscarBB->click();
}


void MainWindow::on_lineEditValor_returnPressed()
{
    ui->pushButtonBuscar->click();
}


void MainWindow::on_lineEditTam_returnPressed()
{
    ui->pushButtonCriar->click();
}

