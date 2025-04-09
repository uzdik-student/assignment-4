#include "question.h"
#include "ui_question.h"
#include <QFontDatabase>


Question::Question(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Question)
{
    ui->setupUi(this);
    setWindowTitle("Question 1");

    QList<int> numbers;
    for (int i=0; i<64; i++) {
        if (i & (1 << 0)) {
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

    ui->numbers->setText(text);
}

Question::~Question()
{
    delete ui;
}

void Question::on_buttonBox_accepted()
{

}


void Question::on_buttonBox_rejected()
{

}

