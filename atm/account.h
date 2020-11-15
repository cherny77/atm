#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QList>
#include "card.h"
class Account
{
private:
    size_t _id;
    QList<Card>* _cards;
public:
    Account(size_t id);
    ~Account();
    void addCard(Card card);
    const QList<Card>* getCards() const;
};

#endif // ACCOUNT_H
