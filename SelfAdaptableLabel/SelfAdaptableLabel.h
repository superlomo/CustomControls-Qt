#ifndef SELFADAPTABLELABEL_H
#define SELFADAPTABLELABEL_H

#include <QLabel>
#include <QPixmap>

class SelfAdaptableLabel : public QLabel
{
    Q_OBJECT
public:
    explicit SelfAdaptableLabel(QWidget *parent = nullptr);
    void setInitalPixmap(const QPixmap&);

private:
    QPixmap _pixmap;

protected:
    void resizeEvent(QResizeEvent* event);
};

#endif // SELFADAPTABLELABEL_H
