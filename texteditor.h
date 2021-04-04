#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QDialog>

namespace Ui {
class TextEditor;
}

class TextEditor : public QDialog
{
    Q_OBJECT

public:
    explicit TextEditor(QWidget *parent = nullptr);
    ~TextEditor();

    void SetText(const QString& text);
    QString GetText();

private:
    Ui::TextEditor *ui;
};

#endif // TEXTEDITOR_H
