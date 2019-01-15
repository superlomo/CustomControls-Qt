#include "SelfAdaptableLabel.h"

SelfAdaptableLabel::SelfAdaptableLabel(QWidget *parent) : QLabel(parent)
{

}

//void SelfAdaptableLabel::setInitalPixamp(const QPixmap& pixmap)
//{
//    _pixmap=pixmap;
//}

void SelfAdaptableLabel::resizeEvent(QResizeEvent *event)
{
    QPixmap tmp=_pixmap.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio,Qt::FastTransformation);
    this->setPixmap(tmp);
}
