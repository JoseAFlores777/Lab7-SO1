#include "cframe.h"
#include "ui_cframe.h"

CFrame::CFrame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CFrame)
{
    ui->setupUi(this);
}

CFrame::~CFrame()
{
    delete ui;
}

