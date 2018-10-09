/********************************************************************************
** Form generated from reading UI file 'newmapdialog.ui'
**
** Created: Wed Mar 19 15:34:10 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMAPDIALOG_H
#define UI_NEWMAPDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_NewMapDialog
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *mapWidth;
    QLabel *label_2;
    QSpinBox *mapHeight;
    QLabel *pixelSizeLabel;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QSpinBox *tileWidth;
    QLabel *label_4;
    QSpinBox *tileHeight;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QLabel *label_5;
    QComboBox *orientation;
    QLabel *layerFormatLabel;
    QComboBox *layerFormat;

    void setupUi(QDialog *NewMapDialog)
    {
        if (NewMapDialog->objectName().isEmpty())
            NewMapDialog->setObjectName(QString::fromUtf8("NewMapDialog"));
        NewMapDialog->resize(365, 268);
        gridLayout_3 = new QGridLayout(NewMapDialog);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_3 = new QGroupBox(NewMapDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        mapWidth = new QSpinBox(groupBox_3);
        mapWidth->setObjectName(QString::fromUtf8("mapWidth"));
        mapWidth->setMinimum(1);
        mapWidth->setMaximum(9999);
        mapWidth->setValue(100);

        gridLayout_2->addWidget(mapWidth, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        mapHeight = new QSpinBox(groupBox_3);
        mapHeight->setObjectName(QString::fromUtf8("mapHeight"));
        mapHeight->setMinimum(1);
        mapHeight->setMaximum(9999);
        mapHeight->setValue(100);

        gridLayout_2->addWidget(mapHeight, 1, 1, 1, 1);

        pixelSizeLabel = new QLabel(groupBox_3);
        pixelSizeLabel->setObjectName(QString::fromUtf8("pixelSizeLabel"));
        pixelSizeLabel->setText(QString::fromUtf8("3200 x 3200 pixels"));

        gridLayout_2->addWidget(pixelSizeLabel, 2, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(NewMapDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        tileWidth = new QSpinBox(groupBox_2);
        tileWidth->setObjectName(QString::fromUtf8("tileWidth"));
        tileWidth->setMinimum(1);
        tileWidth->setMaximum(9999);
        tileWidth->setValue(32);

        gridLayout->addWidget(tileWidth, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        tileHeight = new QSpinBox(groupBox_2);
        tileHeight->setObjectName(QString::fromUtf8("tileHeight"));
        tileHeight->setMinimum(1);
        tileHeight->setMaximum(9999);
        tileHeight->setValue(32);

        gridLayout->addWidget(tileHeight, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 2);


        gridLayout_3->addWidget(groupBox_2, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(NewMapDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_3->addWidget(buttonBox, 3, 0, 1, 2);

        groupBox = new QGroupBox(NewMapDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_4->addWidget(label_5, 0, 0, 1, 1);

        orientation = new QComboBox(groupBox);
        orientation->setObjectName(QString::fromUtf8("orientation"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(orientation->sizePolicy().hasHeightForWidth());
        orientation->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(orientation, 0, 1, 1, 1);

        layerFormatLabel = new QLabel(groupBox);
        layerFormatLabel->setObjectName(QString::fromUtf8("layerFormatLabel"));

        gridLayout_4->addWidget(layerFormatLabel, 1, 0, 1, 1);

        layerFormat = new QComboBox(groupBox);
        layerFormat->setObjectName(QString::fromUtf8("layerFormat"));

        gridLayout_4->addWidget(layerFormat, 1, 1, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 2);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(mapWidth);
        label_2->setBuddy(mapHeight);
        label_3->setBuddy(tileWidth);
        label_4->setBuddy(tileHeight);
        label_5->setBuddy(orientation);
        layerFormatLabel->setBuddy(layerFormat);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(orientation, mapWidth);
        QWidget::setTabOrder(mapWidth, mapHeight);
        QWidget::setTabOrder(mapHeight, tileWidth);
        QWidget::setTabOrder(tileWidth, tileHeight);
        QWidget::setTabOrder(tileHeight, buttonBox);

        retranslateUi(NewMapDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewMapDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewMapDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewMapDialog);
    } // setupUi

    void retranslateUi(QDialog *NewMapDialog)
    {
        NewMapDialog->setWindowTitle(QApplication::translate("NewMapDialog", "New Map", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("NewMapDialog", "Map size", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewMapDialog", "Width:", 0, QApplication::UnicodeUTF8));
        mapWidth->setSuffix(QApplication::translate("NewMapDialog", " tiles", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewMapDialog", "Height:", 0, QApplication::UnicodeUTF8));
        mapHeight->setSuffix(QApplication::translate("NewMapDialog", " tiles", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NewMapDialog", "Tile size", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewMapDialog", "Width:", 0, QApplication::UnicodeUTF8));
        tileWidth->setSuffix(QApplication::translate("NewMapDialog", " px", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewMapDialog", "Height:", 0, QApplication::UnicodeUTF8));
        tileHeight->setSuffix(QApplication::translate("NewMapDialog", " px", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NewMapDialog", "Map", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewMapDialog", "Orientation:", 0, QApplication::UnicodeUTF8));
        layerFormatLabel->setText(QApplication::translate("NewMapDialog", "Layer format:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewMapDialog: public Ui_NewMapDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMAPDIALOG_H
