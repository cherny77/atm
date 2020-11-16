#ifndef CHANGEPINDIALOG_H
#define CHANGEPINDIALOG_H

#include <QDialog>
#include "card.h"
#include "mainwindow.h"

namespace Ui {
class ChangePinDialog;
}
enum ChangePinType { INPUT_OLD_PASSWORD, INPUT_NEW_PASSWORD};

class ChangePinDialog : public QDialog
{
    Q_OBJECT

public:
    const QString PASSWORD_LABEL_NAME = "New Password";
    const QString OLD_PASSWORD_LABEL_NAME = "Old password";
    const QString OLD_PASSWORD_ERROR_LABEL = "PASSWORD IS WRONG";
    const QString NEW_PASSWORD_ERROR_LABEL = "NEW PASSWORD CAN'T BE THE SAME AS OLD";
    explicit ChangePinDialog(QWidget *parent = nullptr);
    void init(Card* card, MainWindow* mainWindow);
    ~ChangePinDialog();

private slots:
    void on_OkBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::ChangePinDialog *ui;
    ChangePinType _changePinType;
    Card* _currCard;
    MainWindow* _mainWindow;
    void showError(QString errorMsg);
};

#endif // CHANGEPINDIALOG_H
