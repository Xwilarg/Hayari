#pragma once

# include <QLineEdit>
# include <QVBoxLayout>
# include <QWebEngineView>

namespace Hayari
{
    class BrowseWindow : public QWidget
    {
        Q_OBJECT

    public:
        BrowseWindow(QWidget* parent, std::function<void(int, const QString&)> setTabName, int index) noexcept;
        ~BrowseWindow() noexcept;
        void PressEnter() noexcept;
        void DecreaseIndex() noexcept; // Reduce index by one, happens when a tab is deleted

    private:
        QWidget*        _mainWidget;
        QVBoxLayout*    _layout;
        QLineEdit*      _urlInput;
        QWebEngineView* _view;
        std::function<void(int, const QString&)> _setTabNameCallback;
        int             _index; // My index in the tab list

    private slots:
        void ChangeNameEvent(const QString& newName);
    };
}
