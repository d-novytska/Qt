#ifndef HELPFIELD_H
#define HELPFIELD_H

#include <QWidget>
#include <QPainter>

class HelpField : public QWidget
{
public:
    HelpField(QWidget *parent = nullptr);
    virtual ~HelpField();
protected:
    void paintEvent(QPaintEvent *e) override;
private:
    QString m_text;
public slots:
    void ChangeTextSlot(QString text);
};

#endif // HELPFIELD_H
