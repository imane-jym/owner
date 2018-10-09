/********************************************************************************
** Form generated from reading UI file 'commanddialog.ui'
**
** Created: Wed Mar 19 15:34:10 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDDIALOG_H
#define UI_COMMANDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>
#include "commanddialog.h"

QT_BEGIN_NAMESPACE

class Ui_CommandDialog
{
public:
    QVBoxLayout *verticalLayout;
    Tiled::Internal::CommandTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QCheckBox *saveBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CommandDialog)
    {
        if (CommandDialog->objectName().isEmpty())
            CommandDialog->setObjectName(QString::fromUtf8("CommandDialog"));
        CommandDialog->resize(479, 258);
        verticalLayout = new QVBoxLayout(CommandDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        treeView = new Tiled::Internal::CommandTreeView(CommandDialog);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setDragDropMode(QAbstractItemView::DragDrop);
        treeView->setAlternatingRowColors(true);
        treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        saveBox = new QCheckBox(CommandDialog);
        saveBox->setObjectName(QString::fromUtf8("saveBox"));

        horizontalLayout->addWidget(saveBox);

        buttonBox = new QDialogButtonBox(CommandDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CommandDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CommandDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CommandDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CommandDialog);
    } // setupUi

    void retranslateUi(QDialog *CommandDialog)
    {
        CommandDialog->setWindowTitle(QApplication::translate("CommandDialog", "Properties", 0, QApplication::UnicodeUTF8));
        saveBox->setText(QApplication::translate("CommandDialog", "&Save map before executing", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CommandDialog: public Ui_CommandDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDDIALOG_H
