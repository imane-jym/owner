/********************************************************************************
** Form generated from reading UI file 'editterraindialog.ui'
**
** Created: Wed Mar 19 15:34:11 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITTERRAINDIALOG_H
#define UI_EDITTERRAINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <terrainview.h>
#include <tilesetview.h>

QT_BEGIN_NAMESPACE

class Ui_EditTerrainDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *undo;
    QToolButton *redo;
    QToolButton *eraseTerrain;
    QSpacerItem *horizontalSpacer_2;
    QComboBox *zoomComboBox;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    Tiled::Internal::TerrainView *terrainList;
    Tiled::Internal::TilesetView *tilesetView;
    QHBoxLayout *horizontalLayout;
    QToolButton *addTerrainTypeButton;
    QToolButton *removeTerrainTypeButton;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditTerrainDialog)
    {
        if (EditTerrainDialog->objectName().isEmpty())
            EditTerrainDialog->setObjectName(QString::fromUtf8("EditTerrainDialog"));
        EditTerrainDialog->resize(615, 372);
        verticalLayout_2 = new QVBoxLayout(EditTerrainDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        undo = new QToolButton(EditTerrainDialog);
        undo->setObjectName(QString::fromUtf8("undo"));
        undo->setEnabled(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/24x24/edit-undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undo->setIcon(icon);
        undo->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        undo->setAutoRaise(true);

        horizontalLayout_3->addWidget(undo);

        redo = new QToolButton(EditTerrainDialog);
        redo->setObjectName(QString::fromUtf8("redo"));
        redo->setEnabled(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/24x24/edit-redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redo->setIcon(icon1);
        redo->setAutoRaise(true);

        horizontalLayout_3->addWidget(redo);

        eraseTerrain = new QToolButton(EditTerrainDialog);
        eraseTerrain->setObjectName(QString::fromUtf8("eraseTerrain"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/22x22/stock-tool-eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        eraseTerrain->setIcon(icon2);
        eraseTerrain->setCheckable(true);
        eraseTerrain->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        eraseTerrain->setAutoRaise(true);

        horizontalLayout_3->addWidget(eraseTerrain);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        zoomComboBox = new QComboBox(EditTerrainDialog);
        zoomComboBox->setObjectName(QString::fromUtf8("zoomComboBox"));

        horizontalLayout_3->addWidget(zoomComboBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        terrainList = new Tiled::Internal::TerrainView(EditTerrainDialog);
        terrainList->setObjectName(QString::fromUtf8("terrainList"));
        terrainList->setMaximumSize(QSize(200, 16777215));
        terrainList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        terrainList->setIndentation(0);
        terrainList->setRootIsDecorated(false);
        terrainList->setItemsExpandable(false);
        terrainList->header()->setVisible(false);

        verticalLayout->addWidget(terrainList);


        horizontalLayout_2->addLayout(verticalLayout);

        tilesetView = new Tiled::Internal::TilesetView(EditTerrainDialog);
        tilesetView->setObjectName(QString::fromUtf8("tilesetView"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tilesetView->sizePolicy().hasHeightForWidth());
        tilesetView->setSizePolicy(sizePolicy);
        tilesetView->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(tilesetView);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        addTerrainTypeButton = new QToolButton(EditTerrainDialog);
        addTerrainTypeButton->setObjectName(QString::fromUtf8("addTerrainTypeButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/22x22/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addTerrainTypeButton->setIcon(icon3);
        addTerrainTypeButton->setAutoRaise(true);

        horizontalLayout->addWidget(addTerrainTypeButton);

        removeTerrainTypeButton = new QToolButton(EditTerrainDialog);
        removeTerrainTypeButton->setObjectName(QString::fromUtf8("removeTerrainTypeButton"));
        removeTerrainTypeButton->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/22x22/remove.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeTerrainTypeButton->setIcon(icon4);
        removeTerrainTypeButton->setAutoRaise(true);

        horizontalLayout->addWidget(removeTerrainTypeButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(EditTerrainDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        verticalLayout_2->addWidget(buttonBox);

        QWidget::setTabOrder(tilesetView, addTerrainTypeButton);
        QWidget::setTabOrder(addTerrainTypeButton, removeTerrainTypeButton);
        QWidget::setTabOrder(removeTerrainTypeButton, buttonBox);

        retranslateUi(EditTerrainDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), EditTerrainDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), EditTerrainDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(EditTerrainDialog);
    } // setupUi

    void retranslateUi(QDialog *EditTerrainDialog)
    {
        EditTerrainDialog->setWindowTitle(QApplication::translate("EditTerrainDialog", "Edit Terrain Information", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        undo->setToolTip(QApplication::translate("EditTerrainDialog", "Undo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        undo->setText(QApplication::translate("EditTerrainDialog", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        redo->setToolTip(QApplication::translate("EditTerrainDialog", "Redo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        redo->setText(QApplication::translate("EditTerrainDialog", "Redo", 0, QApplication::UnicodeUTF8));
        eraseTerrain->setText(QApplication::translate("EditTerrainDialog", "Erase", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        addTerrainTypeButton->setToolTip(QApplication::translate("EditTerrainDialog", "Add Terrain Type", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        addTerrainTypeButton->setText(QApplication::translate("EditTerrainDialog", "Add", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        removeTerrainTypeButton->setToolTip(QApplication::translate("EditTerrainDialog", "Remove Terrain Type", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        removeTerrainTypeButton->setText(QApplication::translate("EditTerrainDialog", "Remove", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditTerrainDialog: public Ui_EditTerrainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITTERRAINDIALOG_H
