#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QLabel>

class TestWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit TestWindow(QWidget *parent = nullptr);
};

#endif //TESTWINDOW_H
