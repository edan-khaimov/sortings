#include <QApplication>
#include "UI/MainWindow.h"

void applyStyleSheet(QApplication &app) {
    QString styleSheet = R"(
        QMainWindow {
            background-color: #121212;
            color: #FFFFFF;
            font-family: 'SF Pro Display';
            font-size: 14px;
        }

        QLabel {
            color: #FFFFFF;
            font-size: 16px;
        }

        QPushButton {
            background-color: #1DB954;
            color: #FFFFFF;
            border: none;
            padding: 10px;
            font-size: 14px;
            font-weight: bold;
            text-transform: uppercase;
            border-radius: 0;
        }

        QPushButton:hover {
            background-color: #1AA34A;
        }

        QPushButton:pressed {
            background-color: #198F40;
        }

        QComboBox {
            background-color: #1E1E1E;
            color: #FFFFFF;
            border: 1px solid #1DB954;
            padding: 5px;
            font-size: 14px;
        }

        QComboBox::drop-down {
            border: none;
            background-color: #1DB954;
            width: 20px;
        }

        QComboBox::down-arrow {
            image: url(:/icons/down-arrow-white.png);
        }

        QComboBox QAbstractItemView {
            background-color: #1E1E1E;
            color: #FFFFFF;
            selection-background-color: #1DB954;
            selection-color: #FFFFFF;
            border: 1px solid #1DB954;
        }

        QLineEdit {
            background-color: #1E1E1E;
            color: #FFFFFF;
            border: 1px solid #1DB954;
            padding: 5px;
            font-size: 14px;
        }

        QProgressBar {
            background-color: #1E1E1E;
            border: 1px solid #FFFFFF;
            border-radius: 0;
            text-align: center;
            color: #FFFFFF;
        }

        QProgressBar::chunk {
            background-color: #1DB954;
        }

        QFrame {
            background-color: #1E1E1E;
            border: none;
            margin: 10px 0;
        }

        QTextEdit {
            background-color: #1E1E1E;
            color: #FFFFFF;
            border: 1px solid #1DB954;
            padding: 10px;
            font-size: 14px;
        }

        QTextEdit QScrollBar:vertical {
            border: none;
            background: #121212;
            width: 10px;
        }

        QTextEdit QScrollBar::handle:vertical {
            background: #1DB954;
            border-radius: 5px;
        }

        QTextEdit QScrollBar::add-line:vertical, QTextEdit QScrollBar::sub-line:vertical {
            height: 0px;
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
