#pragma once

# include <QLineEdit>
# include <QVBoxLayout>
# include <QWebEngineView>

namespace Hayari
{
    class BrowseWindow
    {
    public:
        BrowseWindow(QWidget* parent) noexcept;
        ~BrowseWindow() noexcept;
        void PressEnter() noexcept;

    private:
        QWidget*        _mainWidget;
        QVBoxLayout*    _layout;
        QLineEdit*      _urlInput;
        QWebEngineView* _view;
    };
}
