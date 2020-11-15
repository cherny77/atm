#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QList>
#include "card.h"
class Account
{
private:
    size_t _id;
    QList<Card>* _cards;
    int _currCardIndex;
public:
    Account(size_t id);
    ~Account();
    void addCard(Card card);
    const QList<Card>* getCards() const;
    Card* getCurrentCard();
};

#endif // ACCOUNT_H
