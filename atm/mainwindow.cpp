#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "withdrawrechargedialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), _atm(new ATM()), _loginConditionType(INPUT_CARD_NUMBER)
{
    ui->setupUi(this);
   initLoginPage();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_enterBtn_clicked()
{
    switch(_loginConditionType) {
        case INPUT_CARD_NUMBER:
            if(_atm->existCard((ui->loginInput->text()))) {
                _tempNumberCard = new QString (ui->loginInput->text());
                ui->enterBtn->setText(ENTER_BUTTON_TEXT);
                ui->loginLabel->setText(PASSWORD_LABEL_TEXT);
                _loginConditionType = INPUT_PASSWORD;
                ui->loginInput->clear();
                ui->loginInput->setEchoMode(QLineEdit::Password);
            }
            break;
        case INPUT_PASSWORD:
        if(_atm->enterCard(*_tempNumberCard, ui->loginInput->text())) {
           _loginConditionType = ENTERED;
           _atm->setCurrent(*_tempNumberCard);
           _tempNumberCard = nullptr;
           initCardsPage();
           ui->stackedWidget-> setCurrentIndex(CARDS_VIEW_PAGE_NUMBER);

        }
        break;
        case ENTERED:
        break;

    }
}

void MainWindow::initLoginPage() {
    ui->loginLabel->setText(LOGIN_LABEL_TEXT);
    ui->enterBtn->setText(INSERT_BUTTON_TEXT);
    _loginConditionType = INPUT_CARD_NUMBER;
    ui->loginInput->clear();
//    _atm->exit();
};

void MainWindow::initCardsPage() {
    if (_atm->currentAccount() == nullptr)
        return;
    ui->cardsTableTest->setRowCount(_atm->currentAccount()->getCards()->length());
    ui->cardsTableTest->setColumnCount(3);
    ui->cardsTableTest->verticalHeader()->setVisible(false);
//    ui->cardsTableTest->horizontalHeader()->setVisible(false);
    ui->cardsTableTest->setShowGrid(false);
    ui->cardsTableTest->setEditTriggers(QAbstractItemView::NoEditTriggers);

//    QTableWidgetItem* item = new QTableWidgetItem();
//    item->setData(Qt::DecorationRole, QPixmap(":/MyFiles/res/card.png"));
//    ui->cardsTableTest->setItem(0,0,item);

    QHeaderView* header = ui->cardsTableTest->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    QStringList headers = QStringList();
    headers.append("Card Number");
    headers.append("Money amount");
    headers.append("State");
    ui->cardsTableTest->setHorizontalHeaderLabels(headers);

    QIcon icon = QIcon(":/MyFiles/res/card.png");
    size_t y = 0;
    for (Card card: *_atm->currentAccount()->getCards())
    {
        QTableWidgetItem* item = new QTableWidgetItem(icon, *card.cardNumber());
        ui->cardsTableTest->setItem(y,0,item);
        QTableWidgetItem* item2 = new QTableWidgetItem(QString::number(card.amount()));
        ui->cardsTableTest->setItem(y,1,item2);
        QTableWidgetItem* item3 = new QTableWidgetItem((!card.isBlocked())? "not blocked": "blocked");
        ui->cardsTableTest->setItem(y,2,item3);
        y+=1;
    }

    ui->cardsTableTest->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

};

void MainWindow::on_cardsPageBackBtn_clicked()
{
    ui->stackedWidget-> setCurrentIndex(LOGIN_PAGE_NUMBER);
    initLoginPage();

}


void MainWindow::on_cardsTableTest_itemDoubleClicked(QTableWidgetItem *item)
{
    //TODO
    if (_atm->existCard(item->text()))
    {
    _atm->setCurrent(item->text());
    initCardMenuPage();
    ui->stackedWidget->setCurrentIndex(CARD_MENU_VIEW_PAGE_NUMBER);
    }
}

void MainWindow::initCardMenuPage() {
    if(_atm->currentCard() != nullptr) {
        _atm->setCurrent(*(_atm->currentCard()->cardNumber()));
    ui->moneyLabel->setText(QString::number(_atm->currentCard()->amount()));
    ui->cardNumberLabel->setText(*(_atm->currentCard()->cardNumber()));

    }
};

void MainWindow::on_cardMenuPageBackBtn_clicked()
{
    initCardsPage();
    ui->stackedWidget->setCurrentIndex(CARDS_VIEW_PAGE_NUMBER);

}

void MainWindow::on_rechargeBtn_clicked()
{
    WithdrawRechargeDialog withdrawRechargeDialog;
    withdrawRechargeDialog.setModal(true);
    withdrawRechargeDialog.init(RECHARGE, _atm->currentCard(), this);
    withdrawRechargeDialog.exec();

}

void MainWindow::on_withdrawBtn_clicked()
{
    WithdrawRechargeDialog withdrawRechargeDialog;
    withdrawRechargeDialog.setModal(true);
    withdrawRechargeDialog.init(WITHDRAW, _atm->currentCard(), this);
    withdrawRechargeDialog.exec();

}

void MainWindow::on_changePasswordBtn_clicked()
{

}

void MainWindow::on_transferBtn_clicked()
{

}
