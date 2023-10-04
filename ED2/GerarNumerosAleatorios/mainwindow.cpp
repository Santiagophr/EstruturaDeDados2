#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap foto("/home/puc/Downloads/GerarNumerosAleatorios/imgs/foto");
    ui->labelFoto->setPixmap(foto);

    msgBoxIncluir.setWindowTitle("ERRO");
    msgBoxIncluir.setText("Insira apenas inteiros positivos!");
    msgBoxIncluir.setIcon(QMessageBox::Warning);
    msgBoxIncluir.setStyleSheet("QMessageBox{background-color: rgb(30, 37, 40);}" "QLabel{color: white;}");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    try
    {
        QString teste = ui->lineEditTamanho->text();
        bool v;
        int tamanho = teste.toInt(&v);
        if(v && tamanho > 0)
        {
            ped::Conjunto x(tamanho);
            ui->textEditSaida->setText(x.obterVetor());
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

