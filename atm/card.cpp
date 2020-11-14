#include "card.h"
Card::Card(QString cardNumber, bool isBlocked): _cardNumber(new QString(cardNumber)), _isBlocked(isBlocked) {}
