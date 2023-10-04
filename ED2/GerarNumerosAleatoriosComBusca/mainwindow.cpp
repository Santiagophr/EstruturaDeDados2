#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conjunto = nullptr;
    QPixmap foto("/home/puc/Downloads/GerarNumerosAleatoriosComBusca/imgs/foto");
    ui->labelFoto->setPixmap(foto);
    QPixmap logo("/home/puc/Downloads/GerarNumerosAleatoriosComBusca/imgs/logopuc");
    ui->labelLogo->setPixmap(logo);

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
        QString teste = ui->lineEditTamanho->text();
        bool ok;
        int tamanho = teste.toInt(&ok);
        if(ok && tamanho > 0)
        {
            if(conjunto){
                delete conjunto;
            }
            conjunto = new ped::Conjunto(tamanho);
            ui->textEditSaida->setText(conjunto->obterVetor());
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditTamanho->clear();
        }
    }catch (QString &erro)
    {
        QMessageBox::information(this,"ERRO!", erro);
    }
}


void MainWindow::on_pushButtonBuscar_clicked()
{
    try {
        QString teste = ui->lineEditValor->text();
        bool ok;
        int valor = teste.toInt(&ok);
        if(ok && valor > 0)
        {
            int posicao = conjunto->buscar(valor);
            QString saida = "Número encontrado na posição " + QString::number(posicao);
            ui->lineEditResultado->setText(saida);
        }
        else
        {
            msgBoxIncluir.exec();
            ui->lineEditValor->clear();
        }
    } catch (QString &erro)
    {
        QMessageBox::information(this, "ERRO!", erro);
    }
}

