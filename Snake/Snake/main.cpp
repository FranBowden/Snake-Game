#include "player.hpp"

void pollEvent(Application &application, std::vector<Player> &objects);
void gridLayout(Application &app, SDL_Renderer* render);

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
    

    const int targetFrameRate = 120;  // Set your desired frame rate (e.g., 60 frames per second)
    const int frameDelay = 1000 / targetFrameRate;  // Calculate frame delay in milliseconds
    Uint32 frameStart;
    int frameTime;
    

        
    while (app.isWindowOpen()) { //Application opened
        frameStart = SDL_GetTicks();
      
        SDL_RenderClear(render); // Clear the renderer
       
       
        
        
        gridLayout(app, render);
        
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


void gridLayout(Application &app, SDL_Renderer* render) {
    const int gridSize = 50;  // Adjust the size of the grid squares as needed
    // Define two colors for the grid squares
    SDL_Color color1 = {255,196,12, 255}; // Yellow
    SDL_Color color2 = {251,153,2, 255}; // Orange
    
    bool useColor1 = true;
    //Grid Layout to alternate colours
    for (int x = 0; x < app.windowWidth; x += gridSize) {
           for (int y = 0; y < app.windowHeight; y += gridSize) {
               SDL_Color currentColor = useColor1 ? color1 : color2;
               SDL_SetRenderDrawColor(render, currentColor.r, currentColor.g, currentColor.b, currentColor.a);
               SDL_Rect squareRect = {x, y, gridSize, gridSize};
               SDL_RenderFillRect(render, &squareRect);
               useColor1 = !useColor1; // Toggle the color for the next square
           }
           // Toggle the starting color for the next row
           useColor1 = !useColor1;
       }
}
