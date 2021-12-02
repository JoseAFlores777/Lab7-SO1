#ifndef CFRAME_H
#define CFRAME_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CFrame; }
QT_END_NAMESPACE

class CFrame : public QMainWindow
{
    Q_OBJECT

public:
    CFrame(QWidget *parent = nullptr);
    ~CFrame();

private:
    Ui::CFrame *ui;
};
#endif // CFRAME_H
