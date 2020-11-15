#include "account.h"

Account::Account(size_t id): _id(id), _cards(new QList<Card>)
{

}

void Account::addCard(Card card)
{
    this->_cards->append(card);
}

const QList<Card>* Account::getCards() const
{
    return this->_cards;
}
