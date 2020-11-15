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

Card* Account::getCurrentCard()
{
    if (_currCardIndex >= 0 && _currCardIndex < _cards->length())
    return &((*_cards)[_currCardIndex]);
    else return nullptr;
}
