#include "texteditor.h"
#include "ui_texteditor.h"

TextEditor::TextEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEditor)
{
    ui->setupUi(this);
}

TextEditor::~TextEditor()
{
    delete ui;
}

void TextEditor::SetText(const QString& text)
{
    ui->textEdit->setText(text);
}

QString TextEditor::GetText()
{
    return ui->textEdit->toPlainText();
}