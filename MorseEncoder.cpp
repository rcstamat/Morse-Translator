#include <MorseEncoder.h>
#include <QDebug>

MorseEncoder::MorseEncoder()
{
    englishAlphabet[" "] = "/";
    englishAlphabet["A"] = ".-";
    englishAlphabet["B"] = "-...";
    englishAlphabet["C"] = "-.-.";
    englishAlphabet["D"] = "-..";
    englishAlphabet["E"] = ".";
    englishAlphabet["F"] = "..-.";
    englishAlphabet["G"] = "--.";
    englishAlphabet["H"] = "....";
    englishAlphabet["I"] = "..";
    englishAlphabet["J"] = ".---";
    englishAlphabet["K"] = "-.-";
    englishAlphabet["L"] = ".-..";
    englishAlphabet["M"] = "--";
    englishAlphabet["N"] = "-.";
    englishAlphabet["O"] = "---";
    englishAlphabet["P"] = ".--.";
    englishAlphabet["Q"] = "--.-";
    englishAlphabet["R"] = ".-.";
    englishAlphabet["S"] = "...";
    englishAlphabet["T"] = "-";
    englishAlphabet["U"] = "..-";
    englishAlphabet["V"] = "...-";
    englishAlphabet["W"] = ".--";
    englishAlphabet["X"] = "-..-";
    englishAlphabet["Y"] = "-.--";
    englishAlphabet["Z"] = "--..";

    englishAlphabet["0"] = "-----";
    englishAlphabet["1"] = ".----";
    englishAlphabet["2"] = "..---";
    englishAlphabet["3"] = "...--";
    englishAlphabet["4"] = "....-";
    englishAlphabet["5"] = ".....";
    englishAlphabet["6"] = "-....";
    englishAlphabet["7"] = "--...";
    englishAlphabet["8"] = "---..";
    englishAlphabet["9"] = "----.";

    englishAlphabet["."] = ".-.-.-";
    englishAlphabet[","] = "--..--";
    englishAlphabet["?"] = "..--..";
    englishAlphabet["'"] = ".---.";
    englishAlphabet["!"] = "-.-.--";
    englishAlphabet["/"] = "-..-.";
    englishAlphabet["("] = "-.--.";
    englishAlphabet[")"] = "-.--.-";
    englishAlphabet["&"] = ".-...";
    englishAlphabet[":"] = "---...";
    englishAlphabet[";"] = "-.-.-.";
    englishAlphabet["="] = "-...-";
    englishAlphabet["+"] = "-.-.";
    englishAlphabet["-"] = "-....-";
    englishAlphabet["_"] = "..--.-";
    englishAlphabet["\""] = ".-..-.";
    englishAlphabet["$"] = "...-..-";
    englishAlphabet["@"] = ".--.-.";
}

QString MorseEncoder::englishToMorse(QString text)
{
    QString returnText;
    text = text.toUpper();
    for(int i = 0; i < text.size(); i++)
    {
        returnText += englishAlphabet[text.at(i)];
        if (i < text.size() - 1)
            returnText = returnText + " ";
    }
    return returnText;
}

QString MorseEncoder::morseToEnglish(QString text)
{
    QString returnText = "";
    QStringList words = text.split("/");

    for (int i = 0; i < words.size(); i++)
    {
        QStringList letters = words[i].split(" ");
        for (int j = 0; j < letters.size(); j++)
        {
            returnText += englishAlphabet.key(letters.at(j));
        }
        returnText += " ";
    }
    return returnText;
}
