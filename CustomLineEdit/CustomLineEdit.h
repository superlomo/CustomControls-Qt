#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H

#include "LineEditpart.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QPainter>
#include <QStyleOption>
#include <QFrame>
#include <QKeyEvent>

class CustomLineEdit : public QWidget
{
    Q_OBJECT
public:
    explicit CustomLineEdit(QWidget *parent = nullptr);
    //设置几个输入
    void setInputCount(int);
    //设置是否需要密码样式
    void setPassWordMode(bool);
    //获取内容
    QString text();
    //显示装饰线
    void showVerticalLine(bool);
private:
    int _inputCount;
    bool _passwordMode;
    bool _verticalLine;
    QVector<LineEditPart*> partList;
    QList<QString> textList;

signals:
    void returnPressed();
    void textChanged();

public slots:

protected:
    void paintEvent(QPaintEvent *event);
};

#endif // CUSTOMLINEEDIT_H
