#ifndef CARDMENUVIEW_H
#define CARDMENUVIEW_H

#include <QWidget>

namespace Ui {
class CardMenuView;
}

class CardMenuView : public QWidget
{
    Q_OBJECT

public:
    explicit CardMenuView(QWidget *parent = nullptr);
    ~CardMenuView();

private:
    Ui::CardMenuView *ui;
};

#endif // CARDMENUVIEW_H
