#ifndef LOADING_H
#define LOADING_H

#include <QWidget>
#include <QPainter>

class Loading : public QWidget
{
    Q_OBJECT
public:
    explicit Loading(QWidget *parent = nullptr);
    //设置圆点个数
    void setDotCount(int);
    void setDotColor(const QColor&);

private:
    //点的颜色
    QColor _dotColor;
    //点的个数
    int _count;
    //圆点最小直径
    float _minDiameter;
    //圆点最大直径
    float _maxDiameter;
    //绘制圆点
    void paintDot(QPainter &);

protected:
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // LOADING_H
