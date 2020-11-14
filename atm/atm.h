#ifndef ATM_H
#define ATM_H
#include "card.h"

class ATM
{
private:
  Card* _currentCard;
public:
  bool existCard(QString cardNumber);


  bool enterCard(QString cardNumber, QString password);
    ATM();
  const Card* currentCard();
  void exit();
};

#endif // ATM_H
