#include "resultform.h"
#include "ui_resultform.h"

ResultForm::ResultForm(std::shared_ptr<Result> res, QWidget *parent)
    : QMainWindow(nullptr)
    , ui(new Ui::ResultForm), _parent(parent)
{
    ui->setupUi(this);


    Collector& coll = Collector::getCollector();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(QString::number(coll.getRestData()->getDDrilling())));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString::number(res->getT())));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString::number(res->getS())));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString::number(res->getNb())));
    ui->tableWidget->setItem(0, 4, new QTableWidgetItem(QString::number(res->getVd())));
    ui->tableWidget->setItem(0, 5, new QTableWidgetItem(QString::number(res->getM())));
    ui->tableWidget->setItem(0, 6, new QTableWidgetItem(QString::number(res->getPo())));
    ui->tableWidget->setItem(0, 7, new QTableWidgetItem(QString::number(res->getTo())));


    connect(ui->pushButton, &QPushButton::pressed, this, &ResultForm::on_back);
}

ResultForm::~ResultForm()
{

    delete ui;
}

void ResultForm::on_back()
{
    _parent->show();
    this->close();
}
