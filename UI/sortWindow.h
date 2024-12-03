#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QComboBox>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QProgressBar>

class SortWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit SortWindow(QWidget* parent = nullptr);

private slots:
    void selectFile();
    void startSorting() const;

private:
    QComboBox* sortTypeComboBox;
    QComboBox* sortParameterComboBox;
    QComboBox* sortOrderComboBox;
    QLineEdit* filePathLineEdit;
    QLabel* resultLabel;
    QLabel* statusLabel;
    QProgressBar* progressBar;
};

#endif // SORTWINDOW_H
