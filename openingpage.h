#ifndef OPENINGPAGE_H
#define OPENINGPAGE_H

#include <QWidget>
#include <mainwindow.h>
#include <QPushButton>

class openingPage : public QWidget
{
    Q_OBJECT

public:
    openingPage(QWidget *parent = 0);
    ~openingPage();
signals:

public slots:
    void open_main_window();

public:
    MainWindow * m;
    QPushButton*start;
};

#endif // OPENINGPAGE_H
