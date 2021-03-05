#ifndef MORSEENCODER_H
#define MORSEENCODER_H
#include <QString>
#include <QHash>

class MorseEncoder
{
public:
    MorseEncoder();
    QHash<QString, QString> englishAlphabet;
    QString englishToMorse(QString);
    QString morseToEnglish(QString);
};

#endif // MORSEENCODER_H
