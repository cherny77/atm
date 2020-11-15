#ifndef ATM_H
#define ATM_H
#include "account.h"

class ATM
{
private:
  Card* _currentCard;
  Account* _currentAccount;

public:
  bool existCard(QString cardNumber);
  bool enterCard(QString cardNumber, QString password);
  ATM();

  Card* currentCard();
  const Account* currentAccount();
  void setCurrent(QString cardNumber);
  void exit();
};

#endif // ATM_H
