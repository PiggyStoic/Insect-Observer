#include "auto_mode.h"
#include "ui_auto_mode.h"
#include "widget.h"

auto_mode::auto_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::auto_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Insect Observer 自动控制");

    QStringList serialNamePort;

    //创建一个串口对象
    serialPort = new QSerialPort(this);

    //搜索所有可用串口
    foreach(const QSerialPortInfo &inf0,QSerialPortInfo::availablePorts())
    {
        serialNamePort << inf0.portName();
    }
    ui->serialBox->addItems(serialNamePort);
}

auto_mode::~auto_mode()
{
    delete ui;
}

void auto_mode::on_init_Button_clicked()
{
    //设置串口参数
    serialPort->setPortName(ui->serialBox->currentText());
    serialPort->setBaudRate(115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setParity(QSerialPort::NoParity);
    //打开串口提示框
    if(serialPort->open(QIODevice::ReadWrite) == true)
    {
        QMessageBox::information(this,"提示","串口打开成功");
    }
    else
    {
        QMessageBox::critical(this,"提示","串口打开失败");
    }

    serialPort->write("INIT");
    qDebug("INIT");
}

void auto_mode::on_start_Button_clicked()
{
    serialPort->write("START");
    qDebug("START");
}


void auto_mode::on_end_Button_clicked()
{
    serialPort->write("EEND");
    qDebug("EEND");
    sleep(50);
    serialPort->close();
    this->close();
}

void auto_mode::on_suspend_Button_clicked()
{
    serialPort->write("SUSPEND");
    qDebug("SUSPEND");
}

void auto_mode::on_continue_Button_clicked()
{
    serialPort->write("CONTINUE");
    qDebug("CONTINUE");
}
