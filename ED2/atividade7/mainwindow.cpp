#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpressionValidator *validatorNumeros = new QRegularExpressionValidator(this);
    validatorNumeros->setRegularExpression(QRegularExpression("^\\d+$"));
    ui->lineEditTamanho->setValidator(validatorNumeros);
    ui->textEdit->isReadOnly();
    ui->textEditOrdenadoInsertion->isReadOnly();
    ui->textEditOrdenadoSelection->isReadOnly();
    ui->lineEditTamanho->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGerar_clicked()
{
    try {

        if(ui->lineEditTamanho->text().isEmpty()) {
            ui->lineEditTamanho->setFocus();
            throw QString ("Digite um tamanho para o vetor");
        }
        vetor = new ped::VetorAleatorio (ui->lineEditTamanho->text().toInt());
        ui->textEdit->setText(vetor->getConjunto());

        clock_t tempoInicialSS = clock();
        ui->textEditOrdenadoSelection->setText(vetor->getConjuntoOrdenadoSelectionSort());
        clock_t tempoFinalSS = clock();
        double tempoDeRespostaSS = (tempoFinalSS - tempoInicialSS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoSS->setText(QString::number(tempoDeRespostaSS) + " Ms");

        clock_t tempoInicialIS = clock();
        ui->textEditOrdenadoInsertion->setText(vetor->getConjuntoOrdenadoInsertionSort());
        clock_t tempoFinalIS = clock();
        double tempoDeRespostaIS = (tempoFinalIS - tempoInicialIS) / static_cast<double>(CLOCKS_PER_SEC) * 1000;
        ui->textEditTempoIS->setText(QString::number(tempoDeRespostaIS) + " Ms");

        ui->textEditExecOrdenSelection->setText(QString::number(vetor->getNumOrdenSelectionSort()));
        ui->textEditExecOrdenInsertion->setText(QString::number(vetor->getNumOrdenInsertionSort()));


    } catch (QString &erro) {
        QMessageBox::critical(this, "ERRO", erro);
    }

}


