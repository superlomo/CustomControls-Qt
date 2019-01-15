#include "LineEditpart.h"
#include <QRegExpValidator>

LineEditPart::LineEditPart(QWidget *parent) : QLineEdit(parent)
{
    this->setStyleSheet("background-color:rgba(0,0,0,0);border-width:0px;color:rgb(255,255,255);");

    //设置只能输入一个字符
    QValidator* validator=new QRegExpValidator(QRegExp("^.{1}$"),this);
    this->setValidator(validator);
    this->setAlignment(Qt::AlignCenter);
}

//按键事件
void LineEditPart::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        emit leftAndRightPressed(0);
        break;
    case Qt::Key_Right:
        emit leftAndRightPressed(1);
        break;
    case Qt::Key_Up:
        emit leftAndRightPressed(0);
        break;
    case Qt::Key_Down:
        emit leftAndRightPressed(1);
        break;
    default:
        break;
    }
    QLineEdit::keyPressEvent(event);
    return;
}


