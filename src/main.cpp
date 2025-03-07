#include <iostream>
#include <vector>

#include "BuiltinRenderer.hpp"
#include "DebugRenderer.hpp"
#include "SearchEngine.hpp"

#undef main

int main()
{
    Hayari::SearchEngine engine;

    std::vector<std::unique_ptr<Hayari::ARenderer>> renderers;
    auto baseRenderer = std::make_unique<Hayari::BuiltinRenderer>();

    renderers.push_back(std::make_unique<Hayari::DebugRenderer>(baseRenderer->GetWindow(), baseRenderer->GetRenderer(), engine));
    renderers.push_back(std::move(baseRenderer));

    bool isActive = true;
    while (isActive)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            for (const auto& r : renderers)
            {
                r->ProcessEvents(event);
            }
            switch (event.type)
            {
            case SDL_QUIT:
                isActive = false;
                break;

            default:
                break;
            }
        }

        for (const auto& r : renderers)
        {
            r->PrepareRender();
        }
        for (const auto& r : renderers)
        {
            r->Render();
        }

        SDL_Delay(16);
    }

    return 0;
}