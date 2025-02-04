#include <iostream>

#include "SDL2/SDL.h"
#undef main
#include "imgui.h"

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL failed to init: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Renderer* renderer = NULL;

    SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);

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
            case SDL_QUIT:
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