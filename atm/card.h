#ifndef CARD_H
#define CARD_H
#include <QString>

class Card
{
private:
    QString* _cardNumber;

public:
    void withdraw(long long amount);
    void recharge(long long amount);
    void changePin(QString newPin);
    void transferTo(QString cardNumberTo, long long amount);

    Card();
};

#endif // CARD_H
