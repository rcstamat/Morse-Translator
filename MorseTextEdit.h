#ifndef MORSETEXTEDIT_H
#define MORSETEXTEDIT_H

#include <QObject>
#include <QTextEdit>
#include <QLineEdit>
#include <QMouseEvent>

class MorseTextEdit : public QLineEdit
{
    Q_OBJECT

protected:
    void keyPressEvent (QKeyEvent *event) override;

signals:
    void sendMorse(QString text);

public slots:
    void printText(QString text);
    void clearText();
    void receiveEnglish(QString text);
};

#endif // MORSETEXTEDIT_H
