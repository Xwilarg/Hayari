#include <QLineEdit>
#include <QMouseEvent>
#include <QShortcut>
#include <QTabBar>
#include <QtWebEngine>
#include <QWebEngineView>
#include "inc/MainWindow.hpp"

namespace Hayari
{
    MainWindow::MainWindow() noexcept
        : QMainWindow(nullptr), _mainWidget(new QWidget(this)), _tabs(new QTabWidget(_mainWidget)),
          _mainLayout(new QGridLayout(_mainWidget)), _tabsContent()
    {
        resize(1000, 500);
        setCentralWidget(_mainWidget);

        _mainLayout->addWidget(_tabs, 0, 0, 0, 0);

        _tabs->installEventFilter(this);
        AddTab();
        AddTab();

        QShortcut* scNewTab = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_T), this);
        QShortcut* scCloseTab = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_W), this);
        connect(scNewTab, SIGNAL(activated()), this, SLOT(AddTab()));
        connect(scCloseTab, SIGNAL(activated()), this, SLOT(RemoveCurrentTab()));
    }

    bool MainWindow::eventFilter(QObject* watched, QEvent* event)
    {
        if (watched == _tabs && event->type() == QEvent::MouseButtonPress)
        {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::MouseButton::MidButton) // TODO: Can't close last tab if selected
            {
                RemoveTab(_tabs->tabBar()->tabAt(mouseEvent->pos()));
                return true;
            }
        }
        else if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
            {
                _tabsContent[_tabs->currentIndex()]->PressEnter();
            }
        }
        return QMainWindow::eventFilter(watched, event);
    }

    void MainWindow::RemoveTab(int index) noexcept
    {
        if (index != _tabs->count() - 1) // We can't remove the "+" tab
        {
            _tabsContent.erase(_tabsContent.begin() + index);
            _tabs->removeTab(index);
        }
    }

    /// Add a new tab to the browser
    void MainWindow::AddTab() noexcept
    {
        QWidget* content = new QWidget(_tabs);
        int tabCount = _tabs->count();
        if (tabCount > 0)
        {
            _tabs->setTabText(tabCount - 1, tr("New Tab")); // Rename last tab ("+" tab)
        }
        _tabs->addTab(content, "+"); // Add new "+" tab
        connect(_tabs, SIGNAL(currentChanged(int)), this, SLOT(ChangeTabEvent(int)));

        _tabsContent.push_back(std::make_unique<BrowseWindow>(content));
        _tabs->setCurrentIndex(tabCount - 1);
    }

    void MainWindow::RemoveCurrentTab() noexcept
    {
        RemoveTab(_tabs->currentIndex());
    }

    /// Called when the user click on a tab
    /// If he click on the "+" tab, we create a new one
    void MainWindow::ChangeTabEvent(int index) noexcept
    {
        if (index == _tabs->count() - 1) // Click on last tab ("+")
        {
            AddTab();
        }
    }
}
