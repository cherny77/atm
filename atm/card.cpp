#include "card.h"
#include "databaseapi.h"

Card::Card(QString cardNumber, bool isBlocked, long long amount): _cardNumber(new QString(cardNumber)), _isBlocked(isBlocked), _amount(amount) {}

void Card::withdraw(long long amount)
{
    if (!DataBaseApi::getDataBaseApi()->withdrawCard(*this->_cardNumber, amount))
    {
        throw "operation failed";
    }
}

void Card::recharge(long long amount)
{
    if (!DataBaseApi::getDataBaseApi()->rechargeCard(*this->_cardNumber, amount))
    {
        throw "operation failed";
    }

}

void Card::changePin(QString newPin)
{
    if (!DataBaseApi::getDataBaseApi()->changePinCard(*this->_cardNumber, newPin))
    {
        throw "operation failed";
    }
}

void Card::transferTo(QString cardNumberTo, long long amount)
{
    if (!DataBaseApi::getDataBaseApi()->transaction(*this->_cardNumber, cardNumberTo, amount))
    {
        throw "operation failed";
    }
}

void Card::block()
{
    if (!DataBaseApi::getDataBaseApi()->blockCard(*this->_cardNumber))
    {
        throw "operation failed";
    }
}


const QString* Card::cardNumber() const
{
    return this->_cardNumber;
}
bool Card::isBlocked() const
{
    return this->_isBlocked;
}
long long Card::amount() const
{
    return this->_amount;
}

Card& Card::operator=(const Card& right) {
        if (this == &right) {
            return *this;
        }
       _amount = right.amount();
       _cardNumber = right._cardNumber;
       _isBlocked = isBlocked();
        return *this;
    }
