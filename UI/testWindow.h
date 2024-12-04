#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QTextEdit>
#include <QLabel>
#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>

class TestWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit TestWindow(QWidget* parent = nullptr);

private slots:
    void runTests();

private:
    QPushButton* runTestsButton;
    QLabel* testStatusLabel;
    QLabel* resultLabel;
    QTextEdit* testLog;
    QProgressBar* progressBar;
};

#endif // TESTWINDOW_H
