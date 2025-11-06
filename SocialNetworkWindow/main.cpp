#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(
        // 🌙 Base background + text
        "QWidget {"
        " background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, "
        " stop:0 #1a2a3a, stop:1 #0f2027);"
        " color: white;"
        " font-family: 'Segoe UI';"
        " font-size: 10pt;"
        "}"

        // 🪟 Frame & table “card” look
        "QFrame, QTableWidget {"
        " background-color: rgba(255,255,255,0.06);"
        " border-radius: 10px;"
        " padding: 8px;"
        "}"

        // ✏️ Text fields
        "QLineEdit {"
        " background-color: rgba(255,255,255,0.1);"
        " color: white;"
        " border: 1px solid rgba(255,255,255,0.2);"
        " border-radius: 6px;"
        " padding: 4px;"
        "}"
        "QLineEdit:focus {"
        " border: 1px solid rgba(255,255,255,0.4);"
        " background-color: rgba(255,255,255,0.15);"
        "}"

        // 🔘 Buttons
        "QPushButton {"
        " background-color: rgba(255,255,255,0.1);"
        " color: white;"
        " border: 1px solid rgba(255,255,255,0.2);"
        " border-radius: 6px;"
        " padding: 6px 12px;"
        "}"
        "QPushButton:hover {"
        " background-color: rgba(255,255,255,0.25);"
        "}"
        "QPushButton:pressed {"
        " background-color: rgba(255,255,255,0.35);"
        "}"

        // 🧭 Table header styling
        "QHeaderView::section {"
        " background-color: rgba(255,255,255,0.1);"
        " color: white;"
        " border: none;"
        " padding: 4px;"
        "}"

        // 📜 Scrollbars (optional clean look)
        "QScrollBar:vertical {"
        " background: transparent;"
        " width: 10px;"
        "}"
        "QScrollBar::handle:vertical {"
        " background: rgba(255,255,255,0.2);"
        " border-radius: 5px;"
        "}"
        "QScrollBar::handle:vertical:hover {"
        " background: rgba(255,255,255,0.4);"
        "}"
        );

    SocialNetworkWindow w("users.txt", "posts.txt");
    w.show();

    return a.exec();
}
