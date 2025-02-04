#pragma once

#include "SDL2/SDL.h"
#include "ARenderer.hpp"
#include "SearchEngine.hpp"

namespace Hayari
{
	class DebugRenderer: public ARenderer
	{
	public:
		DebugRenderer(SDL_Window* window, SDL_Renderer* renderer, SearchEngine& engine);
		~DebugRenderer();
		void PrepareRender() noexcept override;
		void Render() noexcept override;
		void ProcessEvents(SDL_Event& events) noexcept override;
	private:
		SDL_Renderer* _renderer;
		SearchEngine& _engine;

		char* _searchBuff;
	};
}