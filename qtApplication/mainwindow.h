#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QClipboard>
#include "ClipboardInterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QSharedPointer<QTimer> _timer;
    QSharedPointer<ClipboardInterface> _clipboardInterface;
    QClipboard* _clipboard;

    size_t _lastChangeCount = 0;

private slots:
    void checkClipBoardChange();
};

#endif // MAINWINDOW_H
