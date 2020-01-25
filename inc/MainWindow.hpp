#pragma once

# include <QMainWindow>
# include <QGridLayout>
# include <QTabWidget>
# include "inc/BrowseWindow.hpp"

namespace Hayari
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow() noexcept;

    private:
        bool eventFilter(QObject *watched, QEvent *event) override;
        void RemoveTab(int index) noexcept;
        QWidget*    _mainWidget;
        QTabWidget* _tabs;
        QGridLayout* _mainLayout;
        std::vector<std::unique_ptr<BrowseWindow>> _tabsContent;

    private slots:
        void AddTab() noexcept;
        void RemoveCurrentTab() noexcept;
        void ChangeTabEvent(int index) noexcept;
    };
}
