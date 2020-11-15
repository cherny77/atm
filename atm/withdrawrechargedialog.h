#ifndef WITHDRAWRECHARGEDIALOG_H
#define WITHDRAWRECHARGEDIALOG_H

#include <QDialog>
#include "card.h"
#include "mainwindow.h"

namespace Ui {
class WithdrawRechargeDialog;
}
enum TransactionType { RECHARGE, WITHDRAW};
class WithdrawRechargeDialog : public QDialog
{
    Q_OBJECT

public:
    const QString INVALID_INPUT_ERROR = "INVALID INPUT";
    const QString TOO_FEW_MONEY_ERROR = "TOO FEW MONEY";
    const QString RECHARGE_NAME_WINDOW = "RECHARGE";
    const QString WITHDRAW_NAME_WINDOW = "WITHDRAW";
    void init(TransactionType, Card* card, MainWindow* mainWindow);
    explicit WithdrawRechargeDialog(QWidget *parent = nullptr);
    ~WithdrawRechargeDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::WithdrawRechargeDialog *ui;
    TransactionType _transactionType;
    Card* _currCard;
    MainWindow* _mainWindow;

    void showError(QString errorMsg);

};

#endif // WITHDRAWRECHARGEDIALOG_H
