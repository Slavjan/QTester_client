#ifndef CHECK_H
#define CHECK_H

#include <QCheckBox>

typedef QMultiMap<int, int> selectedAnswersCheckMap;

namespace SelectedNums{
    namespace Check {
        const char qNum[] = "qNum";
        const char ansNum[] = "ansNum";
    }
}


class Check : public QCheckBox
{
    Q_OBJECT
public:
    Check(QString text, QWidget *parent = 0);
    Check(QString text,
          int questionId,
          int answerId,
          QWidget *parent = 0);
private slots:
    void ansSelected(bool clicked);

signals:
    void ansSelected( int qNum, int ansNum );
};

#endif // CHECK_H
