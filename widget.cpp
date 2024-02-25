#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    m_list = new QListWidget;
    m_add = new QPushButton("Add");
    m_del = new QPushButton("Delete");
    m_line = new QLineEdit;
    m_label = new QLabel;
    m_layout = new QVBoxLayout(this);

    m_layout->addWidget(m_list);
    m_layout->addWidget(m_line);
    m_layout->addWidget(m_add);
    m_layout->addWidget(m_del);

    connect(m_add, SIGNAL(clicked()), this, SLOT(handleAddButton()));
    connect(m_del, SIGNAL(clicked()), this, SLOT(handleDelButton()));

    ui->setupUi(this);
}

void Widget::handleAddButton ()
{
    QString str = m_line->text();

    if(str == nullptr)
    {
        QMessageBox::critical(this, "Message", "Please enter task detail");
    }
    else
    {
        m_list->addItem(str);
    }
}

void Widget::handleDelButton ()
{
    QListWidgetItem *it = m_list->takeItem(m_list->currentRow());
    delete it;
}

Widget::~Widget()
{
    delete ui;
}

