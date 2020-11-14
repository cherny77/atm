#include "card.h"
#include "databaseapi.h"

Card::Card(QString cardNumber, bool isBlocked): _cardNumber(new QString(cardNumber)), _isBlocked(isBlocked) {}

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
