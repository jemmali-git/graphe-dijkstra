#include "openingpage.h"
openingPage::openingPage(QWidget *parent) :
    QWidget(parent)
{
    QPalette* palette = new QPalette();
    setFixedSize(700,600);
    setStyleSheet("background:rgb(190,150,60)");
    setPalette(*palette);
    start=new QPushButton(this);
    start->setGeometry(250,120,200,80);
    start->setStyleSheet("background:rgb(150,150,150);color: red; font-size: 50px;");
    start->setText("START");
    connect(start,SIGNAL(clicked()),this,SLOT(open_main_window()));
}

openingPage::~openingPage()
{

}

void openingPage::open_main_window()
{
        m=new MainWindow;
        m->show();
       // this->hide();
}
