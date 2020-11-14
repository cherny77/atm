#include "atm.h"
#include "databaseapi.h"
#include <QCryptographicHash>
#include <iostream>


ATM::ATM()
{

}


bool ATM::existCard(QString cardNumber) {
    std::cout<< cardNumber.toStdString() << std::endl;
    return DataBaseApi::getDataBaseApi()->existCard(cardNumber);
//    return true;
};
bool ATM::enterCard(QString cardNumber, QString password)
{
    QCryptographicHash* crypt = new QCryptographicHash(QCryptographicHash::Md5);
    crypt->addData(cardNumber.toUtf8());
    crypt->addData(password.toUtf8());
    QString code = QString(crypt->result());
    delete crypt;
    return DataBaseApi::getDataBaseApi()->enterCard(cardNumber, code);
//    return true;
};
