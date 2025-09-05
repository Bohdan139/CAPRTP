#ifndef RESULTFORM_H
#define RESULTFORM_H

#include <QMainWindow>
#include "collector.h"
#include "result.h"

namespace Ui {
class ResultForm;
}

class ResultForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultForm(std::shared_ptr<Result> res, QWidget *parent = nullptr);
    ~ResultForm();

public slots:
    void on_back();

private:
    QWidget* _parent;
    Ui::ResultForm *ui;
};

#endif // RESULTFORM_H
