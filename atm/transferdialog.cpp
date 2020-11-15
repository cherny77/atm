#include "transferdialog.h"
#include "ui_transferdialog.h"

TransferDialog::TransferDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransferDialog)
{
    ui->setupUi(this);
}

TransferDialog::~TransferDialog()
{
    delete ui;
}

void TransferDialog::init(Card* card, MainWindow* mainWindow){
    _currCard = card;
    _mainWindow = mainWindow;
    ui->moneyAmountErrorLabel->setVisible(false);
    ui->moneyAmountErrorLabel->setStyleSheet("QLabel { color : red; }");

    ui->receiverErrorLabel->setVisible(false);
    ui->receiverErrorLabel->setStyleSheet("QLabel { color : red; }");
}

void TransferDialog::on_OkBtn_clicked()
{
   ui->receiverErrorLabel->setVisible(false);
   ui->moneyAmountErrorLabel->setVisible(false);
   bool isOkey = true;
   QRegExp re("\\d*");
   if(!re.exactMatch(ui->amountEdit->text())) {
       isOkey = false;
       showAmountError(INVALID_INPUT_ERROR);
   }
   else if(_currCard->amount() < (ui->amountEdit->text()).toLongLong()) {
       showAmountError(TOO_FEW_MONEY_ERROR);
       isOkey = false;
   }
   if(!_mainWindow->atm()->existCard(ui->receiverEdit->text()))
       {
          isOkey = false;
          showCardError(NO_RECEIVER_ERROR);
       }
    if(isOkey) {
        _currCard->transferTo(ui->receiverEdit->text(), ui->amountEdit->text().toLongLong());
        _mainWindow->initCardMenuPage();
        close();
    }


}

void TransferDialog::showAmountError(QString msg) {
    ui->moneyAmountErrorLabel->setVisible(true);
    ui->moneyAmountErrorLabel->setText(msg);

};
void TransferDialog::showCardError(QString msg) {
    ui->receiverErrorLabel->setVisible(true);
    ui->receiverErrorLabel->setText(msg);

};



void TransferDialog::on_CancelBtn_clicked()
{
    close();
}
