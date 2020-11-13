#include "mainwindow.h"
#include "ui_mainwindow.h"

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
           _tempNumberCard = nullptr;
           _loginConditionType = ENTERED;
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
//   TO DO
};

void MainWindow::initCardMenuPage() {
//    _atm->exit();
};
void MainWindow::on_cardsPageBackBtn_clicked()
{
    ui->stackedWidget-> setCurrentIndex(LOGIN_PAGE_NUMBER);
    initLoginPage();

}

