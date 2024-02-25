#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QListWidget *m_list;
    QPushButton *m_add;
    QPushButton *m_del;
    QVBoxLayout *m_layout;
    QLineEdit *m_line;
    QLabel *m_label;

private slots:
    void handleAddButton();
    void handleDelButton();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
