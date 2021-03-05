#include <MainWindow.h>
#include <EnglishTextEdit.h>
#include <MorseTextEdit.h>
#include <MorseEncoder.h>
#include <QRegExpValidator>
#include <QLabel>
#include <QLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout *boxLayout = new QVBoxLayout;
    QHBoxLayout *row1 = new QHBoxLayout;
    QHBoxLayout *row2 = new QHBoxLayout;

    QLabel *morseLabel = new QLabel("Morse");
    QLabel *englishLabel = new QLabel("English");
    EnglishTextEdit *englishTextEdit = new EnglishTextEdit();
    MorseTextEdit *morseTextEdit = new MorseTextEdit();
    QPushButton *clearAllButton = new QPushButton("Clear All Text");

    clearAllButton->setFixedSize(180, 50);
    englishTextEdit->setFixedSize(650, 50);
    morseTextEdit->setFixedSize(650, 50);

    QFont defaultFont = englishLabel->font();
    defaultFont.setPointSize(18);
    englishLabel->setFont(defaultFont);
    morseLabel->setFont(defaultFont);
    clearAllButton->setFont(defaultFont);
    defaultFont.setPointSize(15);
    englishTextEdit->setFont(defaultFont);
    morseTextEdit->setFont(defaultFont);
    englishTextEdit->setTextMargins(5, 5, 2, 2);
    morseTextEdit->setTextMargins(5, 5, 2, 2);

    QRegExp englishRegex("[a-zA-Z0-9.,?\'/!()&:;=+-_\"$@ ]*");
    QRegExp morseRegex("[-./ ]*");
    englishTextEdit->setValidator(new QRegExpValidator(englishRegex,this));
    englishTextEdit->setToolTip("English alphabet, digits and some punction marks");
    morseTextEdit->setValidator(new QRegExpValidator(morseRegex,morseTextEdit));
    morseTextEdit->setToolTip("Morse code: - . /");
    englishTextEdit->setMaxLength(1000);
    morseTextEdit->setMaxLength(1000);

    boxLayout->setSpacing(10);
    row1->addWidget(englishLabel, 0, Qt::AlignCenter);
    row1->addWidget(englishTextEdit, 0, Qt::AlignCenter);
    row2->addWidget(morseLabel, 0, Qt::AlignCenter);
    row2->addWidget(morseTextEdit, 0, Qt::AlignCenter);
    boxLayout->addLayout(row1);
    boxLayout->addLayout(row2);
    boxLayout->addWidget(clearAllButton, 0, Qt::AlignCenter);

    connect(clearAllButton, SIGNAL(clicked()), englishTextEdit, SLOT(clearText()));
    connect(clearAllButton, SIGNAL(clicked()), morseTextEdit, SLOT(clearText()));
    connect(englishTextEdit, SIGNAL(sendEnglish(QString)), morseTextEdit, SLOT(receiveEnglish(QString)));
    connect(morseTextEdit, SIGNAL(sendMorse(QString)), englishTextEdit, SLOT(receiveMorse(QString)));

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(englishTextEdit);
    layout->addWidget(morseTextEdit);
    layout->addWidget(clearAllButton);

    QWidget *window = new QWidget();
    window->setLayout(boxLayout);
    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
}
