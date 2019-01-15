#ifndef LEDNUMBER_H
#define LEDNUMBER_H

#include <QWidget>
#include <QPainter>

class LEDNumber : public QWidget
{
    Q_OBJECT
public:
    explicit LEDNumber(QWidget *parent = nullptr);

    //设置文字色
    void setFrontColor(const QColor&);
    //设置背景色
    void setBackColor(const QColor&);
    //设置中间线颜色
    void setLineColor(const QColor&);
    //设置宽高比例
    void setScale(float);
    //设置文字
    void setText(QString);
    //设置文字大小
    void setFontSize(int);

private:
    //文字色
    QColor _frontColor;
    //背景色
    QColor _backColor;
    //中间线颜色
    QColor _lineColor;
    //文字
    QString _text;
    //绘制矩形宽度
    float _width;
    float _height;
    //长宽比
    float _scale;
    //文字大小
    int _fontSize;

    //计算绘制区域
    void caculateArea();
    //绘制背景色
    void drawBack(QPainter &);
    //绘制文字
    void drawText(QPainter &);
    //绘制中间线
    void drawLine(QPainter &);

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

signals:

public slots:
};

#endif // LEDNUMBER_H
