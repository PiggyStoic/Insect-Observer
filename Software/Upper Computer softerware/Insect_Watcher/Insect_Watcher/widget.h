#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_auto_mode_Button_clicked();

    void on_manual_mode_Button_clicked();

private:
    Ui::Widget *ui;

};
void sleep(unsigned int msec);
#endif // WIDGET_H
