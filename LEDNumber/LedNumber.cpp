#include "LedNumber.h"
#include <QLabel>

LEDNumber::LEDNumber(QWidget *parent) : QWidget(parent)
{
    //设置默认宽高比
    setScale((float)0.6);
    //设置默认背景色
    setBackColor(QColor(85,85,85));
    //设置默认文字颜色
    setFrontColor(QColor(255,255,255));
    //设置中间线颜色
    setLineColor(QColor(60,60,60));
    //设置默认文字
    setText("2");
    //设置默认文字大小
    setFontSize(40);
    //设置默认最小尺寸
    this->setMinimumSize(100,100);
}

//**********************************************  设置部分 ****************************************
//设置文字颜色
void LEDNumber::setFrontColor(const QColor & color)
{
    _frontColor=color;
}

//设置背景色
void LEDNumber::setBackColor(const QColor & color)
{
    _backColor=color;
}

//设置中间线颜色
void LEDNumber::setLineColor(const QColor& color)
{
    _lineColor=color;
}

//设置宽高比
void LEDNumber::setScale(float scale)
{
    _scale=scale;
}

//设置文字
void LEDNumber::setText(QString text)
{
    _text=text;
}

void LEDNumber::setFontSize(int size)
{
    _fontSize=size;
}

//**********************************************  绘制部分 ****************************************
void LEDNumber::resizeEvent(QResizeEvent *event)
{
    //计算绘制区域
    caculateArea();
}

void LEDNumber::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    //计算绘制区域
//    caculateArea();
    //绘制背景
    drawBack(painter);
    //绘制文字
    drawText(painter);
    //绘制中间线
    drawLine(painter);
}

//计算绘制区域
void LEDNumber::caculateArea()
{
    if((this->height()-2)*_scale>(this->width()-2))
    {
        _width=this->width()-2;
        _height=_width/_scale;
    }
    else
    {
        _height=this->height()-2;
        _width=_height*_scale;
    }
}

//绘制背景
void LEDNumber::drawBack(QPainter & painter)
{
    QPen pen(_backColor,1);
    painter.setPen(pen);
    QPainterPath path;
    path.addRoundedRect(1,1,_width,_height,10,10);
    painter.fillPath(path,_backColor);
    painter.drawPath(path);
}

//绘制文字
void LEDNumber::drawText(QPainter& painter)
{
    QPen pen(_frontColor);
    painter.setPen(pen);
    painter.setFont(QFont("Microsoft YaHei",_fontSize,75));
    painter.drawText(0,0,_width,_height,Qt::AlignCenter,_text);
}

//绘制中间线
void LEDNumber::drawLine(QPainter & painter)
{
    QPen pen(_lineColor,3);
    painter.setPen(pen);
    painter.drawLine(1,_height/2,_width+1,_height/2);
}
