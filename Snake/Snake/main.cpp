#include "player.hpp"

void pollEvent(Application &application, std::vector<Player> &objects);


int main()
{
    Application app;
    
    if (!app.initialize()) {
        return 0;
    }
    
    
    SDL_Renderer* render = Application::m_window_renderer;

    std::vector<Player> objectsToDraw;

       
    objectsToDraw.push_back(Player(25, 25, 200, 200, 255, 0, 0, 255, false));
    objectsToDraw.push_back(Player(50, 50, 100, 100, 0, 100, 100, 255, true));
    
    const int gridSize = 50;  // Adjust the size of the grid squares as needed
    const int targetFrameRate = 120;  // Set your desired frame rate (e.g., 60 frames per second)
    const int frameDelay = 1000 / targetFrameRate;  // Calculate frame delay in milliseconds
    Uint32 frameStart;
    int frameTime;
        
    while (app.isWindowOpen()) {
        frameStart = SDL_GetTicks();
        SDL_SetRenderDrawColor(render, 0, 0, 0, 255); // background color
        SDL_RenderClear(render); // Clear the renderer
       
        // Draw grid lines
         SDL_SetRenderDrawColor(render, 50, 50, 50, 255); // Grid color (gray in this example)
         for (int x = 0; x < app.windowWidth; x += gridSize) {
             SDL_RenderDrawLine(render, x, 0, x, app.windowHeight);
         }
         for (int y = 0; y < app.windowHeight; y += gridSize) {
             SDL_RenderDrawLine(render, 0, y, app.windowWidth, y);
         }
        
        for (const Player& obj : objectsToDraw) {
            obj.draw(render); //Pass the renderer obtained from Application
            
        }
        
        // Calculate the time taken for this frame
        frameTime = SDL_GetTicks() - frameStart;
        // Delay to control frame rate
        if (frameTime < frameDelay) {
            SDL_Delay(frameDelay - frameTime);
        }
        
        SDL_RenderPresent(render); // Present the renderer to update the window
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
