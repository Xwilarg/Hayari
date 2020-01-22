#include <QDebug>
#include "inc/BrowseWindow.hpp"

namespace Hayari
{
    BrowseWindow::BrowseWindow(QWidget* parent) noexcept
        : _mainWidget(parent), _layout(new QVBoxLayout(parent)),
          _urlInput(new QLineEdit(parent)), _view(new QWebEngineView(parent))
    {
        _view->load(QUrl("https://github.com/Xwilarg/Hayari"));
        _view->show();

        _layout->addWidget(_urlInput, 0);
        _layout->addWidget(_view, 1);

        qDebug() << parent->size();
    }
}
