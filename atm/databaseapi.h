#ifndef DATABASEAPI_H
#define DATABASEAPI_H

#include <QString>
#include <QMap>
#include <QList>
#include <account.h>
struct DBCard{
    QString* _cardNumber;
    QString* _cardCode;
    bool _isBlocked;
    long long _amount;

    DBCard(QString cardNumber, QString cardCode, bool isBlocked, long long amount);
};

class DataBaseApi
{
public:
    static DataBaseApi* getDataBaseApi(); // ready
    bool existCard(QString number); // ready
    Card* existCardGetCard(QString number); // ready

    bool enterCard(QString number, QString code); // ready
    Card* enterCardGetCard(QString number, QString code); // ready

//    Account* existCardgetAccount(QString number);
//    Account* enterCardGetAccount(QString number, QString code);

    bool withdrawCard(QString number, long long amount); // ready
    Card* withdrawCardGetCard(QString number, long long amount); // ready

    bool rechargeCard(QString number, long long amount); // ready
    Card* rechargeCardGetCard(QString number, long long amount); // ready

    bool changePinCard(QString number, QString newPin); // ready
    Card* changePinCardGetCard(QString number, QString newPin); // ready
//    Account* changePinCardGetAccount(QString number, QString newPin);

//    Account* transactionGetAccount(QString from, QString to, long long amount);
    bool transaction(QString from, QString to, long long amount); // ready
    Card* transactionGetCard(QString from, QString to, long long amount); // ready

    bool blockCard(QString number); // ready
    Card* blockCardGetCard(QString number); // ready


private:
    DataBaseApi(); // ready
    ~DataBaseApi();
    static DataBaseApi* dataBaseApi;
    QMap<size_t, QList<DBCard>> map;
};

#endif // DATABASEAPI_H
