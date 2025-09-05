#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include "database.h"
#include "collector.h"
#include "dbheaders.h"
#include "mainalgorithm.h"
#include "resultform.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);


    void initialComboBox(QComboBox* comboBox, QVector<const TableDB*> table);

    ~MainWindow();

public slots:

    void on_pressed();

    void change_diametr();

    void change_long();




private:
    std::unique_ptr<ResultForm> resForm = nullptr;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
