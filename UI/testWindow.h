#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>

class TestWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);

    private slots:
        void runTests();
    void selectFile();
    void checkIfFileIsSorted();

private:
    QPushButton *runTestsButton;
    QLabel *testStatusLabel;

    QComboBox *sortParameterComboBox;
    QComboBox *sortOrderComboBox;
    QLineEdit *filePathLineEdit;

    QLabel *resultLabel;

    QPushButton *checkSortingButton;

    QProgressBar* progressBar;
};

#endif // TESTWINDOW_H
