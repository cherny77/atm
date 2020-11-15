#ifndef TRANSFERDIALOG_H
#define TRANSFERDIALOG_H

#include <QDialog>
#include "card.h"
#include "mainwindow.h"

namespace Ui {
class TransferDialog;
}

class TransferDialog : public QDialog
{
    Q_OBJECT

public:
    const QString INVALID_INPUT_ERROR = "INVALID INPUT";
    const QString NO_RECEIVER_ERROR = "THERE IS NO SUCH RECEIVER";
    const QString TOO_FEW_MONEY_ERROR = "TOO FEW MONEY";
    explicit TransferDialog(QWidget *parent = nullptr);
    void init(Card* card, MainWindow* mainWindow);
    ~TransferDialog();

private slots:
    void on_OkBtn_clicked();
    void on_CancelBtn_clicked();

private:
    Ui::TransferDialog *ui;
    Card* _currCard;
    MainWindow* _mainWindow;
    void showAmountError(QString msg);
    void showCardError(QString msg);
};

#endif // TRANSFERDIALOG_H
