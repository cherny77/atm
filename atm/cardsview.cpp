#include "cardsview.h"
#include "ui_cardsview.h"

CardsView::CardsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardsView)
{
    ui->setupUi(this);
}

CardsView::~CardsView()
{
    delete ui;
}
