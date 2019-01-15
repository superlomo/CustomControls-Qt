#include "RoundDot.h"

#include <QPainter>
#include "qmath.h"
#include <QDebug>

RoundDot::RoundDot(QWidget *parent) : QWidget(parent)
{
    SetColor(QColor(49,190,169));
    setRatio(0.4);
}

void RoundDot::SetColor(const QColor&color)
{
    _color=color;
}

void RoundDot::setRatio(float ratio)
{
    _ratio=ratio;
}

void RoundDot::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(_color);
    painter.setBrush(_color);

    //半径
    float radii=qMin(this->geometry().width(),this->geometry().height())/2;
    //绘制圆点
    painter.drawEllipse(QPointF(this->geometry().width()/2,this->geometry().height()/2),radii*_ratio,radii*_ratio);
}
