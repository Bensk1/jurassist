#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _clipboard = QApplication::clipboard();
    _clipboardInterface = QSharedPointer<ClipboardInterface>::create();

    _timer = QSharedPointer<QTimer>::create(this);
    QObject::connect(&(*_timer), &QTimer::timeout, this, &MainWindow::checkClipBoardChange);
    _timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::checkClipBoardChange() {
    if (_lastChangeCount != _clipboardInterface->getLastChangeCount()) {
        QString newData = _clipboard->text();
//        std::cout << newData.toStdString() << std::endl;

        QString title, content, subtitle;
        bool found = false;
        if (newData == "§ 426") {
            found = true;
            subtitle = "Ausgleichungspflicht...";
            title = newData;
            content = "(1) Die Gesamtschuldner sind im Verhältnis zueinander zu gleichen Anteilen verpflichtet, soweit nicht ein anderes bestimmt ist. Kann von einem Gesamtschuldner der auf ihn entfallende Beitrag nicht erlangt werden, so ist der Ausfall von den übrigen zur Ausgleichung verpflichteten Schuldnern zu tragen.";
        } else if (newData == "§ 427") {
            found = true;
            subtitle = "Gemeinschaftliche ver...";
            title = newData;
            content = "Verpflichten sich mehrere durch Vertrag gemeinschaftlich zu einer teilbaren Leistung, so haften sie im Zweifel als Gesamtschuldner.";
        } else if (newData == "§ 428") {
            found = true;
            subtitle = "Gesamtgläubiger";
            title = newData;
            content = "Sind mehrere eine Leistung in der Weise zu fordern berechtigt, dass jeder die ganze Leistung fordern kann, der Schuldner aber die Leistung nur einmal zu bewirken verpflichtet ist (Gesamtgläubiger), so kann der Schuldner nach seinem Belieben an jeden der Gläubiger leisten. Dies gilt auch dann, wenn einer der Gläubiger bereits Klage auf die Leistung erhoben hat.";
        }

        if (_lastChangeCount != 0 && found == true) {
            ui->label->setText(subtitle);
            ui->textBrowser->setText(content);
            MainWindow::show();
            MainWindow::move(QCursor::pos());
            MainWindow::setWindowTitle(title);
            MainWindow::raise();
            MainWindow::activateWindow();
        }

        _lastChangeCount = _clipboardInterface->getLastChangeCount();
    }
}
