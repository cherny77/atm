#include "atm.h"
#include "databaseapi.h"
#include <QCryptographicHash>
#include <iostream>


ATM::ATM()
{

}


bool ATM::existCard(QString cardNumber) {
    return DataBaseApi::getDataBaseApi()->existCard(cardNumber);
};
bool ATM::enterCard(QString cardNumber, QString password)
{
    QCryptographicHash* crypt = new QCryptographicHash(QCryptographicHash::Md5);
    crypt->addData(cardNumber.toUtf8());
    crypt->addData(password.toUtf8());
    QString code = QString(crypt->result());
    delete crypt;
    return DataBaseApi::getDataBaseApi()->enterCard(cardNumber, code);
};


const Card* ATM::currentCard()
{
    return this->_currentCard;
};

const Account* ATM::currentAccount()
{
    return this->_currentAccount;
};

void ATM::setCurrent(QString cardNumber)
{
    this->_currentAccount = DataBaseApi::getDataBaseApi()->getAccoutByCardNumber(cardNumber);
    this->_currentCard = DataBaseApi::getDataBaseApi()->existCardGetCard(cardNumber);
}
