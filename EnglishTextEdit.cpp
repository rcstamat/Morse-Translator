#include <EnglishTextEdit.h>
#include <MorseEncoder.h>
#include <QDebug>
#include <QKeyEvent>

void EnglishTextEdit::printText(QString text)
{
    this->setText(text);
}

void EnglishTextEdit::clearText()
{
    this->setText("");
}

void EnglishTextEdit::receiveMorse(QString text)
{
    MorseEncoder morseEncoder;
    this->setText(morseEncoder.morseToEnglish(text));
}

void EnglishTextEdit::keyPressEvent(QKeyEvent *event)
{
    QLineEdit::keyPressEvent(event);
    emit sendEnglish(this->text());
}
