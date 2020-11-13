#ifndef CARDSVIEW_H
#define CARDSVIEW_H

#include <QWidget>

namespace Ui {
class CardsView;
}

class CardsView : public QWidget
{
    Q_OBJECT

public:
    explicit CardsView(QWidget *parent = nullptr);
    ~CardsView();

private:
    Ui::CardsView *ui;
};

#endif // CARDSVIEW_H
