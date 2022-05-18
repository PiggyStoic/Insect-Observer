#include "widget.h"
#include "ui_widget.h"
#include "auto_mode.h"
#include "manual_mode.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("Insect Observer 控制程序");
}

Widget::~Widget()
{
    delete ui;
}

void sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Widget::on_auto_mode_Button_clicked()
{
    auto_mode *au = new auto_mode;
    au->show();
}

void Widget::on_manual_mode_Button_clicked()
{
    manual_mode *ma = new manual_mode;
    ma->show();
}
