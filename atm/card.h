#ifndef CARD_H
#define CARD_H
#include <QString>

class Card
{
private:
    QString* _cardNumber;
    bool _isBlocked;
    long long _amount;
public:
    void withdraw(long long amount);
    void recharge(long long amount);
    void changePin(QString newPin);
    void transferTo(QString cardNumberTo, long long amount);
    void block();
    Card(QString cardNumber, bool isBlocked, long long amount);
    const QString* cardNumber() const;
    bool isBlocked() const;
    long long amount() const;
};

#endif // CARD_H
