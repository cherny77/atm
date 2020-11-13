#include "withdrawrechargeview.h"
#include "ui_withdrawrechargeview.h"

WithdrawRechargeView::WithdrawRechargeView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawRechargeView)
{
    ui->setupUi(this);
}

WithdrawRechargeView::~WithdrawRechargeView()
{
    delete ui;
}
