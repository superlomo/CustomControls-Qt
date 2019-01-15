#include "CustomLineEdit.h"
#include <QDebug>

CustomLineEdit::CustomLineEdit(QWidget *parent) : QWidget(parent)
{
    //默认输入为6个
    setInputCount(6);
    //默认开启密码样式
    setPassWordMode(true);
    //默认显示装饰线
    showVerticalLine(true);

    QHBoxLayout *layout=new QHBoxLayout(this);
    layout->setMargin(14);
    layout->setSpacing(2);
    this->setLayout(layout);
    for(int i=0;i<_inputCount;i++)
    {
        LineEditPart* part=new LineEditPart(this);
        //当文字内容变化时，获取内容信息，并改变聚焦
        connect(part,&LineEditPart::textChanged,[=]{
            textList[i]=part->text().simplified();
            if(textList[i].isEmpty())
            {
                if(i!=0)
                    partList.at(i-1)->setFocus();
            }
            else if(i<_inputCount-1)
                partList.at(i+1)->setFocus();
            emit textChanged();
        });
        connect(part,&LineEditPart::leftAndRightPressed,[=](int a){
             if(a)
             {
                qDebug()<<"right";
                LineEditPart* part=(LineEditPart*)(this->focusWidget());
                int index=partList.indexOf(part);
                if(index<partList.length()-1)
                 partList.at(index+1)->setFocus();
             }
             else
             {
                qDebug()<<"left";
                LineEditPart* part=(LineEditPart*)(this->focusWidget());
                int index=partList.indexOf(part);
                if(index)
                  partList.at(index-1)->setFocus();
             }
        });
        part->setEchoMode(QLineEdit::Password);
        layout->addWidget(part);
        partList.append(part);
        textList.append(QString(""));

        //最后一个回车时发送回车信号
        if(i==_inputCount-1)
            connect(part,&LineEditPart::returnPressed,[=]{
                emit returnPressed();
            });
        //加入装饰线
        else if(_verticalLine)
        {
            QFrame* line = new QFrame(this);
            line->setObjectName(QStringLiteral("line"));
            line->setStyleSheet(QStringLiteral("background-color: rgba(220,220,220,200);border-width:0px;"));
            line->setMinimumWidth(1);
            //line->setFrameShape(QFrame::VLine);
            //line->setFrameShadow(QFrame::Sunken);
            layout->addWidget(line);
        }
    }
}

void CustomLineEdit::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}

void CustomLineEdit::setInputCount(int count)
{
    _inputCount=count;
}

void CustomLineEdit::setPassWordMode(bool flag)
{
    _passwordMode=flag;
}

void CustomLineEdit::showVerticalLine(bool flag)
{
    _verticalLine=flag;
}

QString CustomLineEdit::text()
{
    QString str("");
    for(QString i:textList)
        str+=i;
    return str;
}






