#pragma once

#include <QMainWindow>

namespace Hayari
{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT

    public:
        MainWindow() noexcept;
        ~MainWindow() noexcept;
    };
}
