#ifndef ROUNDDOT_H
#define ROUNDDOT_H

#include <QWidget>
#include <QPainter>

class RoundDot : public QWidget
{
    Q_OBJECT
public:
    explicit RoundDot(QWidget *parent = nullptr);
    void SetColor(const QColor &);
    void setRatio(float);

private:
    QColor _color;
    float _ratio;

protected:
    void paintEvent(QPaintEvent* event);

signals:

public slots:
};

#endif // ROUNDDOT_H
