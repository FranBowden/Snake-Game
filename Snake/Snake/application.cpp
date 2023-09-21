#include "application.h"
SDL_Renderer *Application::m_window_renderer = nullptr;
Application::Application()
    : m_window(), m_keep_window_open(true)
{
}

Application::~Application()
{
}

bool Application::initialize()
{
    // Initialize SDL and create window/renderer
    m_window = SDL_CreateWindow("Snake Game",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                windowWidth, windowHeight,
                                0);

    if (!m_window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return false;
    }

    m_window_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!m_window_renderer)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return false;
    }

    return true;
}

void Application::cleanup()
{
    // Cleanup and release resources
    SDL_DestroyRenderer(m_window_renderer);
    SDL_DestroyWindow(m_window);
}

void Application::handleEvents(SDL_Event(&event))
{
        switch (event.type)
        {
            case SDL_QUIT:
                m_keep_window_open = false;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        m_keep_window_open = false;
                        break;
                }
    }
}


bool Application::isWindowOpen() const
{
    return m_keep_window_open;
}

void Application::render() {
    SDL_RenderPresent(m_window_renderer); // You need to call this to update the window
    SDL_SetRenderDrawColor(m_window_renderer, 0, 0, 0, 255); // Use member variables
    SDL_RenderClear(m_window_renderer); // You need to call this to update the window

}
