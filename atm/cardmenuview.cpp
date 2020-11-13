#include "cardmenuview.h"
#include "ui_cardmenuview.h"

CardMenuView::CardMenuView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardMenuView)
{
    ui->setupUi(this);
}

CardMenuView::~CardMenuView()
{
    delete ui;
}
