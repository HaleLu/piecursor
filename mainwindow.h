#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "bigwheel.h"
#include "piecursor.h"
#include "toolbar.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    virtual void mouseMoveEvent(QMouseEvent*);
    virtual void paintEvent(QPaintEvent*);
    virtual void mousePressEvent(QMouseEvent*);
    virtual void mouseReleaseEvent(QMouseEvent*);
    virtual void keyPressEvent(QKeyEvent*);
    virtual void keyReleaseEvent(QKeyEvent*);
    virtual int randomNumber();

private:
    Ui::MainWindow* ui;

    Cursor* cursor = nullptr; //鼠标选择
    int iconNumber; //哪一块
    int targetSize;

    QTimer* timer; //计时
    QTime* TimeRecord;

    QPoint currentMousePosPoint;
    QPoint lastMousePosPoint;

    QPoint Rect1PosPoint;
    QPoint Rect2PosPoint;
    QPoint Rect3PosPoint;

    bool needRestart = false;

    bool IsUse[12];  //判断是否用过
    int count=0;     //统计随机生成次数

    void paintRects(QPainter& painter);
private slots:
    void updateTime(); //功能选择
    void on_Toolbar_4_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::ArrowCursor);
        cursor = new ToolBar(Cursor::Four);
        update();
        needRestart = true;
    }
    void on_Toolbar_8_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::ArrowCursor);
        cursor = new ToolBar(Cursor::Eight);
        update();
        needRestart = true;
    }
    void on_PieCursor_4_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::BlankCursor);
        cursor = new PieCursor(Cursor::Four);
        update();
        needRestart = true;
    }
    void on_PieCursor_8_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::BlankCursor);
        cursor = new PieCursor(Cursor::Eight);
        update();
        needRestart = true;
    }
    void on_BigWheel_4_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::ArrowCursor);
        cursor = new BigWheel(Cursor::Four);
        update();
        needRestart = true;
    }
    void on_BigWheel_8_clicked()
    {
        if (cursor != nullptr)
            delete cursor;
        setCursor(Qt::ArrowCursor);
        cursor = new BigWheel(Cursor::Eight);
        update();
        needRestart = true;
    }
};

#endif // MAINWINDOW_H
