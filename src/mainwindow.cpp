#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Collector& coll = Collector::getCollector();


    QIntValidator* validD = new QIntValidator(1,30, ui->diamentLine);
    QIntValidator* validL = new QIntValidator(1, 100, ui->longLine);

    ui->diamentLine->setValidator(validD);
    ui->longLine->setValidator(validL);




    initialComboBox(ui->materialBox, TableDB::convertToBase(coll.getMaterialsTabel()));
    initialComboBox(ui->instrumentBox, TableDB::convertToBase(coll.getInstrumentsTable()));
    initialComboBox(ui->drillingBox, TableDB::convertToBase(coll.getDrillingMachinesTable()));


    connect(ui->pushButton, &QPushButton::released, this, &MainWindow::on_pressed);
    connect(ui->diamentLine, &QLineEdit::textChanged, this, &MainWindow::change_diametr);
    connect(ui->longLine, &QLineEdit::textChanged, this, &MainWindow::change_long);

}

void MainWindow::initialComboBox(QComboBox* comboBox, QVector<const TableDB*> table)
{
    for(const auto& elem : table)
    {

        comboBox->addItem(elem->getName(), elem->getId());
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pressed()
{
    qDebug() << "Material id = " << ui->materialBox->currentData().toInt();

    {

        Collector& coll = Collector::getCollector();

        DataBase data;

        auto feed = data.getFeedValue(ui->materialBox->currentData().toInt(), ui->diamentLine->text().toInt());
        auto kmv = data.getKmvValue(ui->materialBox->currentData().toInt());
        auto kmp = data.getKmpValue(ui->materialBox->currentData().toInt());
        auto table_value = data.getTableValue(ui->materialBox->currentData().toInt(), ui->instrumentBox->currentData().toInt());
        auto t_value = data.getTValue(ui->materialBox->currentData().toInt(),
                                      ui->instrumentBox->currentData().toInt(),
                                      ui->diamentLine->text().toInt());
        auto prm = data.getPRMValue(ui->drillingBox->currentData().toInt());


        if(!feed || !kmv || !table_value || !t_value || !prm)
        {
            QMessageBox::warning(this,"Error","Змініть параметри");
            return;
        }


        coll.setFeed(feed);
        coll.setKmv(kmv);
        coll.setKmp(kmp);
        coll.setTableValue(table_value);
        coll.setTValue(t_value);
        coll.setPRM(prm);
        coll.setRest(std::make_shared<RestData>(ui->diamentLine->text().toInt(), ui->longLine->text().toInt()));


    }


    MainAlgorithm algo;

    algo.calculate(algo.getDrillingMath());

    auto res = algo.getResult();


    qDebug() << res->getT() << " " << res->getS() << " " << res->getNb() << " "
             << res->getVd() << " " << res->getM() << res->getPo() << " " << res->getTo();

    qDebug() << "данні знайденно";



    resForm = std::make_unique<ResultForm>(res, this);

    this->hide();




    resForm->show();
    resForm->activateWindow();

}

void MainWindow::change_diametr()
{
    bool ok;
    int val = ui->diamentLine->text().toInt(&ok);

    if(ok && val > 30)
    {
        ui->diamentLine->setText("30");
    }
    else if(ok && val < 1)
    {
        ui->diamentLine->setText("1");
    }
}

void MainWindow::change_long()
{
    bool ok;
    int val = ui->longLine->text().toInt(&ok);

    if(ok && val > 100)
    {
        ui->longLine->setText("100");
    }
    else if(ok && val < 1)
    {
        ui->longLine->setText("1");
    }
}
