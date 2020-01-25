#include "inc/BrowseWindow.hpp"

namespace Hayari
{
    BrowseWindow::BrowseWindow(QWidget* parent, std::function<void(int, const QString&)> setTabName, int index) noexcept
        : QWidget(parent), _mainWidget(parent), _layout(new QVBoxLayout(parent)),
          _urlInput(new QLineEdit(parent)), _view(new QWebEngineView(parent)),
          _setTabNameCallback(std::move(setTabName)), _index(index)
    {
        _layout->addWidget(_urlInput, 0);
        _layout->addWidget(_view, 1);
        connect(_view, SIGNAL(titleChanged(const QString&)), this, SLOT(ChangeNameEvent(const QString&)));
    }

    BrowseWindow::~BrowseWindow() noexcept
    {
        delete _view; // Force the view to be destroyed so the page don't continue to play
    }

    void BrowseWindow::DecreaseIndex() noexcept
    {
        _index--;
    }

    void BrowseWindow::PressEnter() noexcept
    {
        if (_urlInput->hasFocus() && !_urlInput->text().isEmpty()) // If we press enter while the URL bar have the focus
        {
            _urlInput->clearFocus();
            if (_urlInput->text().startsWith("https://") || _urlInput->text().startsWith("http://"))
            {
                _view->load(QUrl(_urlInput->text()));
            }
            else
            {
                _view->load(QUrl("https://www.google.com/search?q=" + QUrl::toPercentEncoding(_urlInput->text())));
            }
            _view->show();
        }
    }

    void BrowseWindow::ChangeNameEvent(const QString& newName)
    {
        _setTabNameCallback(_index, newName);
    }
}
