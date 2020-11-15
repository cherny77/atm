#include "withdrawrechargedialog.h"
#include "ui_withdrawrechargedialog.h"

WithdrawRechargeDialog::WithdrawRechargeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WithdrawRechargeDialog)
{
    ui->setupUi(this);
    setFixedSize(size());
}

WithdrawRechargeDialog::~WithdrawRechargeDialog()
{
    delete ui;
}

void WithdrawRechargeDialog::init(TransactionType transactionType, Card* card, MainWindow* mainWindow)
{
    _transactionType = transactionType;
    _currCard = card;
    _mainWindow = mainWindow;
    switch (_transactionType)
    {
        case RECHARGE:
            this->setWindowTitle(RECHARGE_NAME_WINDOW);
            break;
        case WITHDRAW:
            this->setWindowTitle(WITHDRAW_NAME_WINDOW);
            break;
    }
    ui->errorLabel->setVisible(false);
    ui->errorLabel->setStyleSheet("QLabel { color : red; }");
}


void WithdrawRechargeDialog :: showError(QString errorMsg){
    ui->errorLabel->setText(errorMsg);
    ui->errorLabel->setVisible(true);
}

void WithdrawRechargeDialog::on_pushButton_clicked()
{
    QRegExp re("\\d*");
    switch(_transactionType)
    {
        case RECHARGE:
            if (!re.exactMatch(ui->lineEdit->text()))
                showError(INVALID_INPUT_ERROR);
            else {
                _currCard->recharge((ui->lineEdit->text()).toLongLong());
                _mainWindow->initCardMenuPage();
                this->close();
            }
            break;
        case WITHDRAW:
            if (!re.exactMatch(ui->lineEdit->text()))
                showError(INVALID_INPUT_ERROR);
            else if(_currCard->amount() < (ui->lineEdit->text()).toLongLong()) {
                showError(TOO_FEW_MONEY_ERROR);
            }
            else {
                _currCard->withdraw((ui->lineEdit->text()).toLongLong());
                _mainWindow->initCardMenuPage();
                this->close();
                   }
            break;

    }
}

void WithdrawRechargeDialog::on_pushButton_2_clicked()
{
    this->close();
}
