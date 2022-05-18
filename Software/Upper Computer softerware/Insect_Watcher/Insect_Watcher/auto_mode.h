#ifndef AUTO_MODE_H
#define AUTO_MODE_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

namespace Ui {
class auto_mode;
}

class auto_mode : public QWidget
{
    Q_OBJECT

public:
    explicit auto_mode(QWidget *parent = nullptr);
    ~auto_mode();
    auto_mode *auto_m;

private slots:
    void on_end_Button_clicked();

    void on_init_Button_clicked();

    void on_start_Button_clicked();

    void on_suspend_Button_clicked();

    void on_continue_Button_clicked();

private:
    Ui::auto_mode *ui;
    QSerialPort *serialPort;
};

#endif // AUTO_MODE_H
