#include "changepindialog.h"
#include "ui_changepindialog.h"

ChangePinDialog::ChangePinDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangePinDialog)
{
    ui->setupUi(this);
}

void ChangePinDialog::init(Card* card, MainWindow* mainWindow)
{
    _currCard = card;
    _mainWindow = mainWindow;
    _changePinType = INPUT_OLD_PASSWORD;
    ui->errorLabel->setVisible(false);
    ui->errorLabel->setStyleSheet("QLabel { color : red; }");
    ui->lineEdit->setEchoMode(QLineEdit::Password);
}

ChangePinDialog::~ChangePinDialog()
{
    delete ui;
}

void ChangePinDialog::on_OkBtn_clicked()
{
    switch(_changePinType){
    case INPUT_OLD_PASSWORD:
       if (_mainWindow->atm()->enterCard(*_currCard->cardNumber(), ui->lineEdit->text()))
       {
           ui->label->setText(PASSWORD_LABEL_NAME);
           ui->lineEdit->clear();
           _changePinType = INPUT_NEW_PASSWORD;
       }
       else {
           showError(OLD_PASSWORD_ERROR_LABEL);
       }
       break;

    case INPUT_NEW_PASSWORD:
        if (_mainWindow->atm()->enterCard(*_currCard->cardNumber(), ui->lineEdit->text()))
             showError(NEW_PASSWORD_ERROR_LABEL);
        else {
            _currCard->changePin(ui->lineEdit->text());
            this->close();
        }

        break;

    }
}

void ChangePinDialog::showError(QString errorMsg) {
    ui->errorLabel->setVisible(true);
    ui->errorLabel->setText(errorMsg);
};

void ChangePinDialog::on_cancelBtn_clicked()
{
    close();
}
