/********************************************************************************
** Form generated from reading UI file 'industrial_robot_builder.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDUSTRIAL_ROBOT_BUILDER_H
#define UI_INDUSTRIAL_ROBOT_BUILDER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_URDFEditor
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_22;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTreeWidget *robotTreeWidget;
    QWidget *propertyBrowserContainer;
    QTabWidget *mainTabWidget;
    QWidget *visualizer_tab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *URDFEditor)
    {
        if (URDFEditor->objectName().isEmpty())
            URDFEditor->setObjectName(QString::fromUtf8("URDFEditor"));
        URDFEditor->resize(1039, 877);
        centralWidget = new QWidget(URDFEditor);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_22 = new QVBoxLayout(centralWidget);
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setContentsMargins(11, 11, 11, 11);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        robotTreeWidget = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        robotTreeWidget->setHeaderItem(__qtreewidgetitem);
        robotTreeWidget->setObjectName(QString::fromUtf8("robotTreeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(robotTreeWidget->sizePolicy().hasHeightForWidth());
        robotTreeWidget->setSizePolicy(sizePolicy);
        robotTreeWidget->setMinimumSize(QSize(0, 0));
        robotTreeWidget->setBaseSize(QSize(0, 0));
        robotTreeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        robotTreeWidget->setIndentation(20);
        robotTreeWidget->setRootIsDecorated(false);
        robotTreeWidget->setHeaderHidden(true);
        robotTreeWidget->setColumnCount(1);
        splitter->addWidget(robotTreeWidget);
        robotTreeWidget->header()->setVisible(false);
        robotTreeWidget->header()->setProperty("showSortIndicator", QVariant(true));
        propertyBrowserContainer = new QWidget(splitter);
        propertyBrowserContainer->setObjectName(QString::fromUtf8("propertyBrowserContainer"));
        sizePolicy.setHeightForWidth(propertyBrowserContainer->sizePolicy().hasHeightForWidth());
        propertyBrowserContainer->setSizePolicy(sizePolicy);
        splitter->addWidget(propertyBrowserContainer);
        splitter_2->addWidget(splitter);
        mainTabWidget = new QTabWidget(splitter_2);
        mainTabWidget->setObjectName(QString::fromUtf8("mainTabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainTabWidget->sizePolicy().hasHeightForWidth());
        mainTabWidget->setSizePolicy(sizePolicy1);
        visualizer_tab = new QWidget();
        visualizer_tab->setObjectName(QString::fromUtf8("visualizer_tab"));
        mainTabWidget->addTab(visualizer_tab, QString());
        splitter_2->addWidget(mainTabWidget);

        verticalLayout_22->addWidget(splitter_2);

        URDFEditor->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(URDFEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1039, 22));
        URDFEditor->setMenuBar(menuBar);
        mainToolBar = new QToolBar(URDFEditor);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        URDFEditor->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(URDFEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        URDFEditor->setStatusBar(statusBar);

        retranslateUi(URDFEditor);

        mainTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(URDFEditor);
    } // setupUi

    void retranslateUi(QMainWindow *URDFEditor)
    {
        URDFEditor->setWindowTitle(QApplication::translate("URDFEditor", "URDF Editor", 0, QApplication::UnicodeUTF8));
        mainTabWidget->setTabText(mainTabWidget->indexOf(visualizer_tab), QApplication::translate("URDFEditor", "Visualizer", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class URDFEditor: public Ui_URDFEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDUSTRIAL_ROBOT_BUILDER_H
