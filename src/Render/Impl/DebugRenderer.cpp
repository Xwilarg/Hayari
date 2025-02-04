#include "DebugRenderer.hpp"

#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_sdlrenderer2.h"

namespace Hayari
{
	DebugRenderer::DebugRenderer(SDL_Window* window, SDL_Renderer* renderer, SearchEngine& engine)
        : _renderer(renderer), _engine(engine)
	{
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
        ImGui_ImplSDLRenderer2_Init(renderer);

        _searchBuff = (char*)calloc(50, sizeof(char));
	}

    DebugRenderer::~DebugRenderer() noexcept
    {
        ImGui_ImplSDLRenderer2_Shutdown();
        ImGui_ImplSDL2_Shutdown();
        ImGui::DestroyContext();

        free(_searchBuff);
    }

    void DebugRenderer::PrepareRender() noexcept
    {
        ImGui_ImplSDLRenderer2_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
    }

    void DebugRenderer::Render() noexcept
    {
        ImGui::InputText("URL", _searchBuff, 50);
        if (ImGui::Button("Search"))
        {
            _engine.Search(std::string(_searchBuff));
            memset(_searchBuff, 0, 50);
        }

        ImGui::Render();
        ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData(), _renderer);
    }

    void DebugRenderer::ProcessEvents(SDL_Event& events) noexcept
    {
        ImGui_ImplSDL2_ProcessEvent(&events);
    }
}