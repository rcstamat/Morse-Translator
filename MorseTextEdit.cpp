#include <MorseTextEdit.h>
#include <MorseEncoder.h>
#include <QDebug>
#include <QEvent>
#include <QKeyEvent>

void MorseTextEdit::printText(QString s){
        this->setText(s);
}

void MorseTextEdit::clearText(){
    this->setText("");
}

void MorseTextEdit::receiveEnglish(QString s)
{
    MorseEncoder morseEncoder;
    this->setText(morseEncoder.englishToMorse(s));
}

void MorseTextEdit::keyPressEvent(QKeyEvent *event)
{
    QLineEdit::keyPressEvent(event);
    emit sendMorse(this->text());
}
