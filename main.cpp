#include <QApplication>
#include "UI/MainWindow.h"

void applyStyleSheet(QApplication &app) {
    const QString styleSheet = R"(
        QMainWindow {
            background-color: #2E3440;
            color: #D8DEE9;
            font-family: SF Pro;
            font-size: 14px;
        }

        QPushButton {
            background-color: #4C566A;
            color: #ECEFF4;
            border: 1px solid #D8DEE9;
            border-radius: 5px;
            padding: 8px;
            font-size: 16px;
        }

        QPushButton:hover {
            background-color: #5E81AC;
        }

        QPushButton:pressed {
            background-color: #81A1C1;
        }

        QLabel {
            color: #ECEFF4;
            font-size: 18px;
        }

        QComboBox {
            background-color: #4C566A;
            color: #ECEFF4;
            border: 1px solid #D8DEE9;
            border-radius: 5px;
            padding: 5px;
            font-size: 16px;
        }

        QComboBox QAbstractItemView {
            background-color: #4C566A;
            color: #ECEFF4;
            border: 1px solid #D8DEE9;
            selection-background-color: #5E81AC;
            selection-color: #ECEFF4;
            font-size: 16px;
        }

        QComboBox::drop-down {
            border: 0px;
        }

        QComboBox::down-arrow {
            image: url(:/icons/down-arrow.png);
            width: 12px;
            height: 12px;
        }

        QComboBox::down-arrow:hover {
            image: url(:/icons/down-arrow-hover.png);
        }

        QLineEdit {
            background-color: #4C566A;
            color: #ECEFF4;
            border: 1px solid #D8DEE9;
            border-radius: 5px;
            padding: 5px;
            font-size: 16px;
        }

        QLineEdit:disabled {
            background-color: #3B4252;
            color: #4C566A;
        }

        QHBoxLayout {
            margin: 10px;
        }

        QLineEdit {
            width: 300px;
        }

        QPushButton {
            width: 150px;
        }

        /* Стиль для комбинированных элементов (кнопка и поле для текста) */
        QHBoxLayout > QWidget {
            margin-right: 10px;
        }

        /* Стиль для кнопки "Выбрать файл" */
        QPushButton#selectFileButton {
            background-color: #81A1C1;
            border-radius: 5px;
            padding: 8px 16px;
            font-size: 14px;
            color: #2E3440;
        }

        QPushButton#selectFileButton:hover {
            background-color: #A3B8D8;
        }

        QPushButton#selectFileButton:pressed {
            background-color: #7A90B8;
        }
    )";

    app.setStyleSheet(styleSheet);
}


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    applyStyleSheet(app);
    MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}
