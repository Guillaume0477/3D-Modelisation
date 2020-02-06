/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QCheckBox *wireframe;
    QPushButton *draw;
    QPushButton *quit;
    QWidget *tab_4;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QCheckBox *grid;
    QCheckBox *color_patch;
    QCheckBox *grid_position;
    QCheckBox *surface;
    QWidget *tab;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QPushButton *u_back;
    QPushButton *v_back;
    QPushButton *u_front;
    QPushButton *v_front;
    QPushButton *u_back_negative;
    QPushButton *v_back_negative;
    QPushButton *u_front_negative;
    QPushButton *v_front_negative;
    QPushButton *duplicate_boundaries;
    QPushButton *save_grid;
    QPushButton *load_grid;
    QVBoxLayout *layout_scene;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(902, 509);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(300, 400));
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayoutWidget = new QWidget(tab_3);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 281, 351));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        wireframe = new QCheckBox(gridLayoutWidget);
        wireframe->setObjectName(QString::fromUtf8("wireframe"));
        sizePolicy1.setHeightForWidth(wireframe->sizePolicy().hasHeightForWidth());
        wireframe->setSizePolicy(sizePolicy1);
        wireframe->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(wireframe, 0, 0, 1, 1);

        draw = new QPushButton(gridLayoutWidget);
        draw->setObjectName(QString::fromUtf8("draw"));
        sizePolicy1.setHeightForWidth(draw->sizePolicy().hasHeightForWidth());
        draw->setSizePolicy(sizePolicy1);
        draw->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(draw, 1, 0, 1, 1);

        quit = new QPushButton(gridLayoutWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        sizePolicy1.setHeightForWidth(quit->sizePolicy().hasHeightForWidth());
        quit->setSizePolicy(sizePolicy1);
        quit->setMinimumSize(QSize(150, 0));

        gridLayout_3->addWidget(quit, 2, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayoutWidget_2 = new QWidget(tab_4);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 271, 341));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        grid = new QCheckBox(gridLayoutWidget_2);
        grid->setObjectName(QString::fromUtf8("grid"));
        grid->setChecked(true);

        gridLayout->addWidget(grid, 0, 0, 1, 1);

        color_patch = new QCheckBox(gridLayoutWidget_2);
        color_patch->setObjectName(QString::fromUtf8("color_patch"));

        gridLayout->addWidget(color_patch, 0, 1, 1, 1);

        grid_position = new QCheckBox(gridLayoutWidget_2);
        grid_position->setObjectName(QString::fromUtf8("grid_position"));
        grid_position->setChecked(true);

        gridLayout->addWidget(grid_position, 1, 0, 1, 1);

        surface = new QCheckBox(gridLayoutWidget_2);
        surface->setObjectName(QString::fromUtf8("surface"));
        surface->setChecked(true);

        gridLayout->addWidget(surface, 1, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayoutWidget_3 = new QWidget(tab);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 271, 331));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        u_back = new QPushButton(gridLayoutWidget_3);
        u_back->setObjectName(QString::fromUtf8("u_back"));

        gridLayout_2->addWidget(u_back, 0, 0, 1, 1);

        v_back = new QPushButton(gridLayoutWidget_3);
        v_back->setObjectName(QString::fromUtf8("v_back"));

        gridLayout_2->addWidget(v_back, 0, 1, 1, 1);

        u_front = new QPushButton(gridLayoutWidget_3);
        u_front->setObjectName(QString::fromUtf8("u_front"));

        gridLayout_2->addWidget(u_front, 1, 0, 1, 1);

        v_front = new QPushButton(gridLayoutWidget_3);
        v_front->setObjectName(QString::fromUtf8("v_front"));

        gridLayout_2->addWidget(v_front, 1, 1, 1, 1);

        u_back_negative = new QPushButton(gridLayoutWidget_3);
        u_back_negative->setObjectName(QString::fromUtf8("u_back_negative"));

        gridLayout_2->addWidget(u_back_negative, 2, 0, 1, 1);

        v_back_negative = new QPushButton(gridLayoutWidget_3);
        v_back_negative->setObjectName(QString::fromUtf8("v_back_negative"));

        gridLayout_2->addWidget(v_back_negative, 2, 1, 1, 1);

        u_front_negative = new QPushButton(gridLayoutWidget_3);
        u_front_negative->setObjectName(QString::fromUtf8("u_front_negative"));

        gridLayout_2->addWidget(u_front_negative, 3, 0, 1, 1);

        v_front_negative = new QPushButton(gridLayoutWidget_3);
        v_front_negative->setObjectName(QString::fromUtf8("v_front_negative"));

        gridLayout_2->addWidget(v_front_negative, 3, 1, 1, 1);

        duplicate_boundaries = new QPushButton(gridLayoutWidget_3);
        duplicate_boundaries->setObjectName(QString::fromUtf8("duplicate_boundaries"));

        gridLayout_2->addWidget(duplicate_boundaries, 4, 0, 1, 2);

        save_grid = new QPushButton(gridLayoutWidget_3);
        save_grid->setObjectName(QString::fromUtf8("save_grid"));

        gridLayout_2->addWidget(save_grid, 5, 0, 1, 1);

        load_grid = new QPushButton(gridLayoutWidget_3);
        load_grid->setObjectName(QString::fromUtf8("load_grid"));

        gridLayout_2->addWidget(load_grid, 5, 1, 1, 1);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        layout_scene = new QVBoxLayout();
        layout_scene->setObjectName(QString::fromUtf8("layout_scene"));
        layout_scene->setSizeConstraint(QLayout::SetDefaultConstraint);

        horizontalLayout->addLayout(layout_scene);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 902, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        wireframe->setText(QApplication::translate("MainWindow", "Wireframe", 0, QApplication::UnicodeUTF8));
        draw->setText(QApplication::translate("MainWindow", "Draw", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Viewer", 0, QApplication::UnicodeUTF8));
        grid->setText(QApplication::translate("MainWindow", "Grid", 0, QApplication::UnicodeUTF8));
        color_patch->setText(QApplication::translate("MainWindow", "Color patch", 0, QApplication::UnicodeUTF8));
        grid_position->setText(QApplication::translate("MainWindow", "Grid position", 0, QApplication::UnicodeUTF8));
        surface->setText(QApplication::translate("MainWindow", "Surface", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Spline", 0, QApplication::UnicodeUTF8));
        u_back->setText(QApplication::translate("MainWindow", "+u back", 0, QApplication::UnicodeUTF8));
        v_back->setText(QApplication::translate("MainWindow", "+v back", 0, QApplication::UnicodeUTF8));
        u_front->setText(QApplication::translate("MainWindow", "+u front", 0, QApplication::UnicodeUTF8));
        v_front->setText(QApplication::translate("MainWindow", "+v front", 0, QApplication::UnicodeUTF8));
        u_back_negative->setText(QApplication::translate("MainWindow", "-u back", 0, QApplication::UnicodeUTF8));
        v_back_negative->setText(QApplication::translate("MainWindow", "-v back", 0, QApplication::UnicodeUTF8));
        u_front_negative->setText(QApplication::translate("MainWindow", "-u front", 0, QApplication::UnicodeUTF8));
        v_front_negative->setText(QApplication::translate("MainWindow", "-v front", 0, QApplication::UnicodeUTF8));
        duplicate_boundaries->setText(QApplication::translate("MainWindow", "Duplicate boundaries", 0, QApplication::UnicodeUTF8));
        save_grid->setText(QApplication::translate("MainWindow", "Save Grid", 0, QApplication::UnicodeUTF8));
        load_grid->setText(QApplication::translate("MainWindow", "Load Grid", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Control Polygon", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
