#pragma once

# include <QMainWindow>
# include <QGridLayout>
# include <QTabWidget>

namespace Hayari
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow() noexcept;

    private:
        bool eventFilter(QObject *watched, QEvent *event) override;
        void AddTab() noexcept;
        void RemoveTab(int index) noexcept;
        QWidget*    _mainWidget;
        QTabWidget* _tabs;
        QGridLayout* _mainLayout;

    private slots:
        void ChangeTab(int index) noexcept;
    };
}
