#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QTextCharFormat>
#include <QMap>
#include <QObject>
#include <QString>

class Highlighter : public QSyntaxHighlighter
{
public:
    Highlighter(QTextDocument* parent, QMap<QString, bool>* keywords);

protected:
    void highlightBlock(const QString& text) override;

private:
    struct HighlightingRule
        {
            QRegularExpression pattern;
            QTextCharFormat format;
        };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};

#endif // HIGHLIGHTER_H
