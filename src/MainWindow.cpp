#include <QLineEdit>
#include <QMouseEvent>
#include <QTabBar>
#include <QtWebEngine>
#include <QWebEngineView>
#include "inc/BrowseWindow.hpp"
#include "inc/MainWindow.hpp"

namespace Hayari
{
    MainWindow::MainWindow() noexcept
        : QMainWindow(nullptr), _mainWidget(new QWidget(this)), _tabs(new QTabWidget(_mainWidget)),
          _mainLayout(new QGridLayout(_mainWidget))
    {
        resize(1000, 500);
        setCentralWidget(_mainWidget);

        _mainLayout->addWidget(_tabs, 0, 0, 0, 0);

        _tabs->installEventFilter(this);
        AddTab();
        AddTab();
    }

    bool MainWindow::eventFilter(QObject* watched, QEvent* event)
    {
        if (watched == _tabs && event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::MouseButton::MidButton) // TODO: Can't close last tab if selected
            {
                RemoveTab(_tabs->tabBar()->tabAt(mouseEvent->pos()));
                return true;
            }
        }
        return QMainWindow::eventFilter(watched, event);
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
        connect(_tabs, SIGNAL(currentChanged(int)), this, SLOT(ChangeTab(int)));

        new BrowseWindow(content); // TODO: delete when not used anymore
    }

    void MainWindow::RemoveTab(int index) noexcept
    {
        if (index != _tabs->count() - 1) // We can't remove the "+" tab
        {
            _tabs->removeTab(index);
        }
    }

    /// Called when the user click on a tab
    /// If he click on the "+" tab, we create a new one
    void MainWindow::ChangeTab(int index) noexcept
    {
        if (index == _tabs->count() - 1) // Click on last tab ("+")
        {
            AddTab();
        }
    }
}
