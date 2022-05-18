#ifndef MANUAL_MODE_H
#define MANUAL_MODE_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

namespace Ui {
class manual_mode;
}

class manual_mode : public QWidget
{
    Q_OBJECT

public:
    explicit manual_mode(QWidget *parent = nullptr);
    ~manual_mode();
    manual_mode *manual_m;

private slots:
    void on_end_Button_clicked();

    void on_p1_Button_clicked();

    void on_p2_Button_clicked();

    void on_p3_Button_clicked();

    void on_p4_Button_clicked();

    void on_p5_Button_clicked();

    void on_p6_Button_clicked();

    void on_p7_Button_clicked();

    void on_p8_Button_clicked();

    void on_p9_Button_clicked();

    void on_init_Button_clicked();

private:
    Ui::manual_mode *ui;
    QSerialPort *serialPort;
};

#endif // MANUAL_MODE_H
