#ifndef LINEEDITPART_H
#define LINEEDITPART_H

#include <QKeyEvent>
#include <QLineEdit>

class LineEditPart : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEditPart(QWidget *parent = nullptr);

signals:
    //0 for left 1 for right
    void leftAndRightPressed(int);
public slots:
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // LINEEDITPART_H
