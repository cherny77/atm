#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "atm.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum LoginConditionType { INPUT_CARD_NUMBER, INPUT_PASSWORD, ENTERED };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    const QString PASSWORD_LABEL_TEXT = "Password";
    const QString LOGIN_LABEL_TEXT = "Login";
    const QString INSERT_BUTTON_TEXT = "Insert card";
    const QString ENTER_BUTTON_TEXT = "Enter";
    const int LOGIN_PAGE_NUMBER = 0;
    const int CARDS_VIEW_PAGE_NUMBER = 1;
    const int CARD_MENU_VIEW_PAGE_NUMBER = 2;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_enterBtn_clicked();
    void on_cardsPageBackBtn_clicked();

private:
    Ui::MainWindow *ui;
    ATM *_atm;
    QString *_tempNumberCard;
    LoginConditionType _loginConditionType;
    void initLoginPage();
    void initCardsPage();
    void initCardMenuPage();

};


#endif // MAINWINDOW_H
