#include "databaseapi.h"
#include <QCryptographicHash>
#include <iostream>

DataBaseApi* DataBaseApi::dataBaseApi = nullptr;

DBCard::DBCard(QString cardNumber, QString cardCode, bool isBlocked, long long amount): _cardNumber(new QString(cardNumber)), _cardCode(new QString(cardCode)), _isBlocked(isBlocked), _amount(amount){};

bool operator==(const DBCard &a, const DBCard &b)
{
    return a._cardNumber == b._cardNumber;
}

DataBaseApi::DataBaseApi()
{

    this->map = QMap<size_t, QList<DBCard*>>();
    this->addCard(1, "1", "1", true, 100);
    this->addCard(1, "11", "11", false, 1000);
    this->addCard(2, "22", "22", false, 100);
    this->addCard(2, "2", "2", false, 1000);

    this->rechargeCard("2", 80);
}

void DataBaseApi::addCard(size_t acc, QString number, QString pin, bool isBlocked, long long amount)
{
    QCryptographicHash* crypt = new QCryptographicHash(QCryptographicHash::Md5);
    crypt->addData(number.toUtf8());
    crypt->addData(pin.toUtf8());

    DBCard* dbcard = new DBCard(number, QString(crypt->result()), isBlocked, amount);
    if (this->map.contains(acc))
    {
        if (!this->map[acc].contains(dbcard))
        {
            this->map[acc].append(dbcard);
        }
        delete crypt;
        return;
    }
    QList<DBCard*> list = QList<DBCard*>();
    list.append(dbcard);
    this->map.insert(acc, list);
    delete crypt;
}

DataBaseApi* DataBaseApi::getDataBaseApi() {
    if (dataBaseApi == nullptr)
    {
        dataBaseApi = new DataBaseApi();
    }
    return dataBaseApi;
}


bool DataBaseApi::existCard(QString number)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if (dbcard->_cardNumber == number && !dbcard->_isBlocked) {
                return true;
            };
        }
    }
    return false;
}


Card* DataBaseApi::existCardGetCard(QString number)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if (dbcard->_cardNumber == number) {
                return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            };
        }
    }
    return nullptr;
}


bool DataBaseApi::enterCard(QString number, QString code)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && !dbcard->_isBlocked)
            {
                return dbcard->_cardCode == code;
            }
        }
    }
    return false;
}



Card* DataBaseApi::enterCardGetCard(QString number, QString code)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && (dbcard->_cardCode == code))
            {
                return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            }
        }
    }
    return nullptr;
}

bool DataBaseApi::withdrawCard(QString number, long long amount)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && (dbcard->_amount >= amount) && !dbcard->_isBlocked)
            {
                    dbcard->_amount -= amount;
                    return true;
            }
        }
    }
    return false;
}

Card* DataBaseApi::withdrawCardGetCard(QString number, long long amount)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && (dbcard->_amount >= amount) && !dbcard->_isBlocked)
            {
                    dbcard->_amount -= amount;
                    return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            }
        }
    }
    return nullptr;
}


bool DataBaseApi::rechargeCard(QString number, long long amount)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : (this->map.find(accId).value()))
        {
            if ((dbcard->_cardNumber == number) && !dbcard->_isBlocked)
            {
                dbcard->_amount = dbcard->_amount + amount;

std::cout << "lol" << std::endl;
                    return true;
            }
        }
    }
    return false;
}

Card* DataBaseApi::rechargeCardGetCard(QString number, long long amount)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && !dbcard->_isBlocked)
            {
                    dbcard->_amount += amount;
                    return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            }
        }
    }
    return nullptr;
}



bool DataBaseApi::changePinCard(QString number, QString newPin)
{
    QCryptographicHash* crypt = new QCryptographicHash(QCryptographicHash::Md5);
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && !dbcard->_isBlocked)
            {

                crypt->addData(dbcard->_cardNumber->toUtf8());
                crypt->addData(newPin.toUtf8());
                delete dbcard->_cardCode;
                dbcard->_cardCode = new QString(crypt->result());
                delete crypt;
                return true;
            }
        }
    }
    return false;
}
Card* DataBaseApi::changePinCardGetCard(QString number, QString newPin)
{
    QCryptographicHash* crypt = new QCryptographicHash(QCryptographicHash::Md5);
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == number) && !dbcard->_isBlocked)
            {

                crypt->addData(dbcard->_cardNumber->toUtf8());
                crypt->addData(newPin.toUtf8());
                delete dbcard->_cardCode;
                dbcard->_cardCode = new QString(crypt->result());
                delete crypt;
                return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            }
        }
    }
    return nullptr;
}



bool DataBaseApi::transaction(QString from, QString to, long long amount)
{
    DBCard* fromC;
    DBCard* toC;
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == from))
            {
                if (dbcard->_isBlocked || dbcard->_amount < amount)
                    return false;
                else
                    fromC = dbcard;
            }
            if ((dbcard->_cardNumber == to))
            {
                if (dbcard->_isBlocked)
                    return false;
                else
                    toC = dbcard;
            }
        }
    }
    fromC->_amount -= amount;
    toC->_amount += amount;
    return true;
}

Card* DataBaseApi::transactionGetCard(QString from, QString to, long long amount)
{
    DBCard* fromC;
    DBCard* toC;
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if ((dbcard->_cardNumber == from))
            {
                if (dbcard->_isBlocked || dbcard->_amount < amount)
                    return nullptr;
                else
                    fromC = dbcard;
            }
            if ((dbcard->_cardNumber == to))
            {
                if (dbcard->_isBlocked)
                    return nullptr;
                else
                    toC = dbcard;
            }
        }
    }
    fromC->_amount -= amount;
    toC->_amount += amount;
    return new Card(*fromC->_cardNumber, fromC->_isBlocked, fromC->_amount);
}


bool DataBaseApi::blockCard(QString number)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if (dbcard->_cardNumber == number) {
                dbcard->_isBlocked = true;
                return true;
            };
        }
    }
    return false;
}


Card* DataBaseApi::blockCardGetCard(QString number)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if (dbcard->_cardNumber == number) {
                dbcard->_isBlocked = true;
                return new Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount);
            };
        }
    }
    return nullptr;
}


Account* DataBaseApi::getAccoutByCardNumber(QString number)
{
    for(size_t accId : this->map.keys())
    {
        for(DBCard* dbcard : this->map.find(accId).value())
        {
            if (dbcard->_cardNumber == number) {
                Account* account = new Account(accId);
                for(DBCard* dbcard: this->map[accId])
                {
                    account->addCard(Card(*dbcard->_cardNumber, dbcard->_isBlocked, dbcard->_amount));
                }
                return account;
            };
        }
    }
    return nullptr;
}

