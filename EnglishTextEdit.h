#ifndef ENGLISHTEXTEDIT_H
#define ENGLISHTEXTEDIT_H

#include <QObject>
#include <QTextEdit>
#include <QLineEdit>
#include <QMouseEvent>

class EnglishTextEdit : public QLineEdit
{
    Q_OBJECT

protected:
    void keyPressEvent (QKeyEvent *event) override;

signals:
    void sendEnglish(QString text);

public slots:
    void receiveMorse(QString text);
    void printText(QString text);
    void clearText();
};

#endif // ENGLISHTEXTEDIT_H
