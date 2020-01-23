#include "inc/BrowseWindow.hpp"

namespace Hayari
{
    BrowseWindow::BrowseWindow(QWidget* parent) noexcept
        : _mainWidget(parent), _layout(new QVBoxLayout(parent)),
          _urlInput(new QLineEdit(parent)), _view(new QWebEngineView(parent))
    {
        _layout->addWidget(_urlInput, 0);
        _layout->addWidget(_view, 1);
    }

    void BrowseWindow::PressEnter() noexcept
    {
        if (_urlInput->hasFocus() && !_urlInput->text().isEmpty()) // If we press enter while the URL bar have the focus
        {
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
}
