#include "player.hpp"

void pollEvent(Application &application, std::vector<Player> &objects);

int main()
{
    Application app;
    
    if (!app.initialize()) {
        return 0;
    }
    
    std::vector<Player> objectsToDraw;

       objectsToDraw.push_back(Player(50, 50, 100, 100, 100, 0, 100, 255));
      
        
    while (app.isWindowOpen()) {
        SDL_SetRenderDrawColor(Application::m_window_renderer, 0, 0, 0, 255); // background color
        SDL_RenderClear(Application::m_window_renderer); // Clear the renderer
       
        for (const Player& obj : objectsToDraw) {
            obj.draw(Application::m_window_renderer); //Pass the renderer obtained from Application
            
        }
        SDL_RenderPresent(Application::m_window_renderer); // Present the renderer to update the window
        pollEvent(app, objectsToDraw);
    }
    
    app.cleanup();
    return 0;
}


void pollEvent(Application &application, std::vector<Player> &objects) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        for (Player& obj : objects) {
            obj.pollEvents(event);
        }

        application.handleEvents(event);
    }
}
