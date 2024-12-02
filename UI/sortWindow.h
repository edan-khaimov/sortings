#ifndef SORTWINDOW_H
#define SORTWINDOW_H

#include <QComboBox>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>

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
    QLineEdit* filePathLineEdit;
    QLabel* resultLabel;
};

#endif // SORTWINDOW_H
