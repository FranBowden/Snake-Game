#include "player.hpp"

void pollEvent(Application &application, std::vector<Player> &objects);

int main()
{
    Application app;
    
    if (!app.initialize()) {
        return 0;
    }
    
    std::vector<Player> objectsToDraw;

       
    objectsToDraw.push_back(Player(25, 25, 200, 200, 255, 0, 0, 255, false));
    objectsToDraw.push_back(Player(50, 50, 100, 100, 0, 100, 100, 255, true));
    
    
    const int targetFrameRate = 120;  // Set your desired frame rate (e.g., 60 frames per second)
    const int frameDelay = 1000 / targetFrameRate;  // Calculate frame delay in milliseconds
    Uint32 frameStart;
    int frameTime;
        
    while (app.isWindowOpen()) {
        frameStart = SDL_GetTicks();
        SDL_SetRenderDrawColor(Application::m_window_renderer, 0, 0, 0, 255); // background color
        SDL_RenderClear(Application::m_window_renderer); // Clear the renderer
       
        for (const Player& obj : objectsToDraw) {
            obj.draw(Application::m_window_renderer); //Pass the renderer obtained from Application
            
        }
        SDL_RenderPresent(Application::m_window_renderer); // Present the renderer to update the window
        
        // Calculate the time taken for this frame
            frameTime = SDL_GetTicks() - frameStart;

            // Delay to control frame rate
        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
            
        }
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
