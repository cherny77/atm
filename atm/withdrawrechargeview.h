#ifndef WITHDRAWRECHARGEVIEW_H
#define WITHDRAWRECHARGEVIEW_H

#include <QDialog>

namespace Ui {
class WithdrawRechargeView;
}

class WithdrawRechargeView : public QDialog
{
    Q_OBJECT

public:
    explicit WithdrawRechargeView(QWidget *parent = nullptr);
    ~WithdrawRechargeView();

private:
    Ui::WithdrawRechargeView *ui;
};

#endif // WITHDRAWRECHARGEVIEW_H
