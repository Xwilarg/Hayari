#include <iostream>

#include "SDL3/SDL.h"

int main()
{
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS))
    {
        std::cout << "SDL failed to init" << std::endl;
        return 1;
    }

    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Renderer* renderer = NULL;

    SDL_CreateWindowAndRenderer("Test window", 800, 600, 0, &window, &renderer);

    if (!window || !renderer)
    {
        std::cout << "Window/renderer failed to create" << std::endl;
        return 1;
    }

    bool isActive = true;
    while (isActive)
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_EVENT_QUIT:
                isActive = false;
                break;

            default:
                break;
            }
        }

        SDL_SetRenderDrawColor(renderer, 96, 128, 255, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    SDL_Quit();
    return 0;
}