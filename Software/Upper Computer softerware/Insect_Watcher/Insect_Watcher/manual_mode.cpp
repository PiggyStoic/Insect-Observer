#include "manual_mode.h"
#include "ui_manual_mode.h"
#include "widget.h"

manual_mode::manual_mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manual_mode)
{
    ui->setupUi(this);
    this->setWindowTitle("Insect Observer 手动控制");

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

manual_mode::~manual_mode()
{
    delete ui;
}

void manual_mode::on_init_Button_clicked()
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
        QMessageBox::information(this,"提示","初始化成功！");
    }
    else
    {
        QMessageBox::critical(this,"提示","初始化失败！");
    }
    serialPort->write("INIT");
    qDebug("INIT");
}

void manual_mode::on_end_Button_clicked()
{
    serialPort->write("EEND");
    qDebug("EEND");
    sleep(50);
    serialPort->close();
    this->close();
}

void manual_mode::on_p1_Button_clicked()
{
    serialPort->write("POS1");
    qDebug("POS1");
}


void manual_mode::on_p2_Button_clicked()
{
    serialPort->write("POS2");
    qDebug("POS2");
}


void manual_mode::on_p3_Button_clicked()
{
    serialPort->write("POS3");
    qDebug("POS3");
}

void manual_mode::on_p4_Button_clicked()
{
    serialPort->write("POS4");
    qDebug("POS4");
}

void manual_mode::on_p5_Button_clicked()
{
    serialPort->write("POS5");
    qDebug("POS5");
}

void manual_mode::on_p6_Button_clicked()
{
    serialPort->write("POS6");
    qDebug("POS6");
}

void manual_mode::on_p7_Button_clicked()
{
    serialPort->write("POS7");
    qDebug("POS7");
}

void manual_mode::on_p8_Button_clicked()
{
    serialPort->write("POS8");
    qDebug("POS8");
}

void manual_mode::on_p9_Button_clicked()
{
    serialPort->write("POS9");
    qDebug("POS9");
}
