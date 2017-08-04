/********************************************************************************
** Form generated from reading UI file 'objectpropertiesdialog.ui'
**
** Created: Wed Mar 19 15:34:10 2014
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBJECTPROPERTIESDIALOG_H
#define UI_OBJECTPROPERTIESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ObjectPropertiesDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *positionGroupBox;
    QGridLayout *gridLayout;
    QLabel *xLabel;
    QDoubleSpinBox *x;
    QLabel *yLabel;
    QDoubleSpinBox *y;
    QGridLayout *gridLayout_3;
    QLabel *nameLabel;
    QLabel *typeLabel;
    QLineEdit *name;
    QComboBox *type;
    QLabel *image;
    QHBoxLayout *horizontalLayout;
    QLineEdit *imagePathEdit;
    QPushButton *browseButton;
    QGroupBox *sizeGroupBox;
    QGridLayout *gridLayout_2;
    QLabel *widthLabel;
    QDoubleSpinBox *width;
    QLabel *heightLabel;
    QDoubleSpinBox *height;
    QGroupBox *ImagePosition;
    QGridLayout *gridLayout_5;
    QLabel *xLabel_2;
    QSpinBox *image_x;
    QLabel *label;
    QSpinBox *image_y;

    void setupUi(QWidget *ObjectPropertiesDialog)
    {
        if (ObjectPropertiesDialog->objectName().isEmpty())
            ObjectPropertiesDialog->setObjectName(QString::fromUtf8("ObjectPropertiesDialog"));
        ObjectPropertiesDialog->resize(441, 206);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ObjectPropertiesDialog->sizePolicy().hasHeightForWidth());
        ObjectPropertiesDialog->setSizePolicy(sizePolicy);
        ObjectPropertiesDialog->setBaseSize(QSize(0, 0));
        gridLayout_4 = new QGridLayout(ObjectPropertiesDialog);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        positionGroupBox = new QGroupBox(ObjectPropertiesDialog);
        positionGroupBox->setObjectName(QString::fromUtf8("positionGroupBox"));
        positionGroupBox->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(positionGroupBox->sizePolicy().hasHeightForWidth());
        positionGroupBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(positionGroupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        xLabel = new QLabel(positionGroupBox);
        xLabel->setObjectName(QString::fromUtf8("xLabel"));

        gridLayout->addWidget(xLabel, 0, 0, 1, 1);

        x = new QDoubleSpinBox(positionGroupBox);
        x->setObjectName(QString::fromUtf8("x"));
        x->setDecimals(3);
        x->setMinimum(-999);
        x->setMaximum(9999);

        gridLayout->addWidget(x, 0, 1, 1, 1);

        yLabel = new QLabel(positionGroupBox);
        yLabel->setObjectName(QString::fromUtf8("yLabel"));

        gridLayout->addWidget(yLabel, 1, 0, 1, 1);

        y = new QDoubleSpinBox(positionGroupBox);
        y->setObjectName(QString::fromUtf8("y"));
        y->setDecimals(3);
        y->setMinimum(-999);
        y->setMaximum(9999);

        gridLayout->addWidget(y, 1, 1, 1, 1);


        gridLayout_4->addWidget(positionGroupBox, 2, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        nameLabel = new QLabel(ObjectPropertiesDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));

        gridLayout_3->addWidget(nameLabel, 0, 0, 1, 1);

        typeLabel = new QLabel(ObjectPropertiesDialog);
        typeLabel->setObjectName(QString::fromUtf8("typeLabel"));

        gridLayout_3->addWidget(typeLabel, 1, 0, 1, 1);

        name = new QLineEdit(ObjectPropertiesDialog);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout_3->addWidget(name, 0, 1, 1, 1);

        type = new QComboBox(ObjectPropertiesDialog);
        type->setObjectName(QString::fromUtf8("type"));
        type->setEditable(true);

        gridLayout_3->addWidget(type, 1, 1, 1, 1);

        image = new QLabel(ObjectPropertiesDialog);
        image->setObjectName(QString::fromUtf8("image"));

        gridLayout_3->addWidget(image, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        imagePathEdit = new QLineEdit(ObjectPropertiesDialog);
        imagePathEdit->setObjectName(QString::fromUtf8("imagePathEdit"));
        imagePathEdit->setEnabled(true);
        imagePathEdit->setReadOnly(false);

        horizontalLayout->addWidget(imagePathEdit);

        browseButton = new QPushButton(ObjectPropertiesDialog);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        horizontalLayout->addWidget(browseButton);


        gridLayout_3->addLayout(horizontalLayout, 2, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 4);

        sizeGroupBox = new QGroupBox(ObjectPropertiesDialog);
        sizeGroupBox->setObjectName(QString::fromUtf8("sizeGroupBox"));
        sizePolicy1.setHeightForWidth(sizeGroupBox->sizePolicy().hasHeightForWidth());
        sizeGroupBox->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(sizeGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        widthLabel = new QLabel(sizeGroupBox);
        widthLabel->setObjectName(QString::fromUtf8("widthLabel"));

        gridLayout_2->addWidget(widthLabel, 0, 0, 1, 1);

        width = new QDoubleSpinBox(sizeGroupBox);
        width->setObjectName(QString::fromUtf8("width"));
        width->setDecimals(3);
        width->setMaximum(9999);

        gridLayout_2->addWidget(width, 0, 1, 1, 1);

        heightLabel = new QLabel(sizeGroupBox);
        heightLabel->setObjectName(QString::fromUtf8("heightLabel"));

        gridLayout_2->addWidget(heightLabel, 1, 0, 1, 1);

        height = new QDoubleSpinBox(sizeGroupBox);
        height->setObjectName(QString::fromUtf8("height"));
        height->setDecimals(3);
        height->setMaximum(9999);

        gridLayout_2->addWidget(height, 1, 1, 1, 1);


        gridLayout_4->addWidget(sizeGroupBox, 2, 2, 1, 1);

        ImagePosition = new QGroupBox(ObjectPropertiesDialog);
        ImagePosition->setObjectName(QString::fromUtf8("ImagePosition"));
        sizePolicy1.setHeightForWidth(ImagePosition->sizePolicy().hasHeightForWidth());
        ImagePosition->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(ImagePosition);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        xLabel_2 = new QLabel(ImagePosition);
        xLabel_2->setObjectName(QString::fromUtf8("xLabel_2"));

        gridLayout_5->addWidget(xLabel_2, 0, 0, 1, 1);

        image_x = new QSpinBox(ImagePosition);
        image_x->setObjectName(QString::fromUtf8("image_x"));
        image_x->setMinimum(-9999);
        image_x->setMaximum(9999);

        gridLayout_5->addWidget(image_x, 0, 1, 1, 1);

        label = new QLabel(ImagePosition);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 1, 0, 1, 1);

        image_y = new QSpinBox(ImagePosition);
        image_y->setObjectName(QString::fromUtf8("image_y"));
        image_y->setMinimum(-9999);
        image_y->setMaximum(9999);

        gridLayout_5->addWidget(image_y, 1, 1, 1, 1);


        gridLayout_4->addWidget(ImagePosition, 2, 1, 1, 1);

#ifndef QT_NO_SHORTCUT
        nameLabel->setBuddy(name);
        typeLabel->setBuddy(type);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(name, type);
        QWidget::setTabOrder(type, imagePathEdit);
        QWidget::setTabOrder(imagePathEdit, x);
        QWidget::setTabOrder(x, y);
        QWidget::setTabOrder(y, image_x);
        QWidget::setTabOrder(image_x, image_y);
        QWidget::setTabOrder(image_y, width);
        QWidget::setTabOrder(width, height);
        QWidget::setTabOrder(height, browseButton);

        retranslateUi(ObjectPropertiesDialog);

        QMetaObject::connectSlotsByName(ObjectPropertiesDialog);
    } // setupUi

    void retranslateUi(QWidget *ObjectPropertiesDialog)
    {
        ObjectPropertiesDialog->setWindowTitle(QApplication::translate("ObjectPropertiesDialog", "Form", 0, QApplication::UnicodeUTF8));
        positionGroupBox->setTitle(QApplication::translate("ObjectPropertiesDialog", "Position", 0, QApplication::UnicodeUTF8));
        xLabel->setText(QApplication::translate("ObjectPropertiesDialog", "X:", 0, QApplication::UnicodeUTF8));
        yLabel->setText(QApplication::translate("ObjectPropertiesDialog", "Y:", 0, QApplication::UnicodeUTF8));
        nameLabel->setText(QApplication::translate("ObjectPropertiesDialog", "Name:", 0, QApplication::UnicodeUTF8));
        typeLabel->setText(QApplication::translate("ObjectPropertiesDialog", "Type:", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("ObjectPropertiesDialog", "Image:", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("ObjectPropertiesDialog", "Browser", 0, QApplication::UnicodeUTF8));
        sizeGroupBox->setTitle(QApplication::translate("ObjectPropertiesDialog", "Size", 0, QApplication::UnicodeUTF8));
        widthLabel->setText(QApplication::translate("ObjectPropertiesDialog", "Width:", 0, QApplication::UnicodeUTF8));
        heightLabel->setText(QApplication::translate("ObjectPropertiesDialog", "Height:", 0, QApplication::UnicodeUTF8));
        ImagePosition->setTitle(QApplication::translate("ObjectPropertiesDialog", "ImagePosition", 0, QApplication::UnicodeUTF8));
        xLabel_2->setText(QApplication::translate("ObjectPropertiesDialog", "X:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ObjectPropertiesDialog", "Y:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ObjectPropertiesDialog: public Ui_ObjectPropertiesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBJECTPROPERTIESDIALOG_H
