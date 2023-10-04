#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conjunto = nullptr;

    msgBoxIncluir.setWindowTitle("ERRO");
    msgBoxIncluir.setText("Insira apenas inteiros positivos!");
    msgBoxIncluir.setIcon(QMessageBox::Warning);
    msgBoxIncluir.setStyleSheet("QMessageBox{background-color: rgb(30, 37, 40);}" "QLabel{color: white;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGerar_clicked()
{
    try
    {
        QString v = ui->lineEditTamanho->text();
        bool ok;
        int tamanho = v.toInt(&ok);
        if(ok && tamanho > 0)
        {
            conjunto = new ped::Conjunto(tamanho);
            ui->lineEditVetor->setText(conjunto->getConjunto());
            conjunto->selectionSort();
            ui->lineEditVetorOrdenado->setText(conjunto->getConjuntoOrdenado());
            ui->lineEditExecucoesOrdendado->setText(QString::number(conjunto->getExecucoesOrdencao()));
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditTamanho->clear();
        }
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this,"ERRO", erro);
    }
}

void MainWindow::on_pushButtonSequencialAleatorio_clicked()
{
    try
    {
        if(ui->lineEditValor1->text().isEmpty()) throw QString ("Informe o número a ser buscado");
        QString posicao = QString::number(conjunto->buscarNumero(ui->lineEditValor1->text().toInt()));
        if(conjunto->buscarBinario(ui->lineEditValor1->text().toInt()) == -1){
             ui->lineEditResultado1->setText("O número não existe.");
        }
        else{
             ui->lineEditResultado1->setText("O número " + ui->lineEditValor1->text() + " está na posição " + posicao);
        }
        ui->lineEditExecucoes1->setText(QString::number(conjunto->getExecucoesBuscar()));
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonSequencialOrdenado_clicked()
{
    try
    {
        if(ui->lineEditValor2->text().isEmpty()) throw QString ("Informe o número a ser buscado");
        QString posicao = QString::number(conjunto->buscarNumeroMelhorado(ui->lineEditValor2->text().toInt()));
        if(conjunto->buscarBinario(ui->lineEditValor2->text().toInt()) == -1){
             ui->lineEditResultado2->setText("O número não existe.");
        }
        else{
             ui->lineEditResultado2->setText("O número " + ui->lineEditValor2->text() + " está na posição " + posicao);
        }
        ui->lineEditExecucoes2->setText(QString::number(conjunto->getExecucoesBuscarMelhorado()));
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

void MainWindow::on_pushButtonBinarioOrdenado_clicked()
{
    try
    {
        if(ui->lineEditValor3->text().isEmpty()) throw QString ("Informe o número a ser buscado");
        QString posicao = QString::number(conjunto->buscarBinario(ui->lineEditValor3->text().toInt()));
        if(conjunto->buscarBinario(ui->lineEditValor3->text().toInt()) == -1){
             ui->lineEditResultado3->setText("O número não existe.");
        }
        else{
             ui->lineEditResultado3->setText("O número " + ui->lineEditValor3->text() + " está na posição " + posicao);
        }
        ui->lineEditExecucoes3->setText(QString::number(conjunto->getExecucoesBuscarBinario()));
    }
    catch (QString &erro)
    {
        QMessageBox::critical(this, "ERRO", erro);
    }
}

