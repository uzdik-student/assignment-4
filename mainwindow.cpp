#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create the Game object and pass the layout to it
    game = new Game();

    initialState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearLayout()
{
    QVBoxLayout *layout = ui->verticalLayout;
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        if (item->widget()) {
            // If the item is a widget, delete it
            delete item->widget();
        }
        // Delete the layout item, but don't delete its layout (this allows nested layouts to be preserved)
        delete item;
    }
}

void MainWindow::initialState()
{
    game->ResetBit();

    setWindowTitle("Initial state");

    QLabel *newLabel = new QLabel("Think of a number between 0 and 63, but don't tell me 🤫", nullptr);
    newLabel->setAlignment(Qt::AlignCenter);
    ui->verticalLayout->addWidget(newLabel);

    QLabel *newLabel2 = new QLabel("I’ll try to guess it 👀", nullptr);
    newLabel2->setAlignment(Qt::AlignCenter);
    ui->verticalLayout->addWidget(newLabel2);

    QPushButton *newButton = new QPushButton("Start game", nullptr);
    connect(newButton, &QPushButton::clicked, this, &MainWindow::questionState);
    ui->verticalLayout->addWidget(newButton);
}

void MainWindow::questionState()
{
    clearLayout();
    QVBoxLayout *layout = ui->verticalLayout;

    setWindowTitle("Question " + QString::number(game->CurrentBit()+1));

    QLabel *newLabel = new QLabel("Do you see your number in this list? 👀", nullptr);
    newLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(newLabel);

    QList<int> numbers;
    for (int i=0; i<64; i++) {
        if (i & (1 << game->CurrentBit())) {
            numbers.append(i);
        }
    }


    QString text;
    for (int i = 0; i < numbers.size(); ++i) {
        text += QString::number(numbers[i]).rightJustified(2, '0');
        if ((i+1) % 8 == 0) {
            text += QChar::LineFeed;
        } else if (i < numbers.size() - 1) {
            text += ", ";
        }
    }

    QLabel *newLabel2 = new QLabel(text, nullptr);
    newLabel2->setAlignment(Qt::AlignCenter);
    QFont monospaceFont("Courier");
    newLabel2->setFont(monospaceFont);
    layout->addWidget(newLabel2);

    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Yes | QDialogButtonBox::No, Qt::Horizontal);
    buttonBox->setCenterButtons(true);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &MainWindow::onYesButtonClicked);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &MainWindow::onNoButtonClicked);
    layout->addWidget(buttonBox);
}

void MainWindow::onYesButtonClicked()
{
    game->SetLeastSignificantBit(game->CurrentBit());

    clearLayout();

    if (game->FinalBit()) {
        // game->ChangeState(FinalState::Instance());
        finalState();
    } else {
        // game->ChangeState(ShowFirstBit::Instance());
        game->ShiftBit();
        questionState();
    }
}

void MainWindow::onNoButtonClicked()
{
    game->UnsetLeastSignificantBit(game->CurrentBit());

    clearLayout();

    if (game->FinalBit()) {
        // game->ChangeState(FinalState::Instance());
        finalState();
    } else {
        // game->ChangeState(ShowFirstBit::Instance());
        game->ShiftBit();
        questionState();
    }
}

void MainWindow::finalState()
{
    clearLayout();

    setWindowTitle("Final state");
    QVBoxLayout *layout = ui->verticalLayout;

    QLabel *newLabel = new QLabel("The number you have guessed is " + QString::number(game->Answer()), nullptr);
    newLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(newLabel);

    QPushButton *newButton = new QPushButton("Restart", nullptr);
    connect(newButton, &QPushButton::clicked, this, &MainWindow::onRestartButtonClicked);
    layout->addWidget(newButton);
}

void MainWindow::onRestartButtonClicked()
{
    clearLayout();
    initialState();
}
