#include "Loading.h"

Loading::Loading(QWidget *parent) : QWidget(parent)
{
    setDotColor(QColor(100,100,100));
}

//********************************************** 设置部分 *************************************
//设置点的个数
void Loading::setDotCount(int count)
{

}

//设置点的颜色
void Loading::setDotColor(const QColor & color)
{
    _dotColor=color;
}

//********************************************** 绘制部分 *************************************
void Loading::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    paintDot(painter);
}

void Loading::paintDot(QPainter& painter)
{

}
