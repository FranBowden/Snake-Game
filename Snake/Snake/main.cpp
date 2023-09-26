#include "player.hpp"

void gridLayout(Application &app, SDL_Renderer* render);
void Apple(SDL_Renderer* render, int centerX, int centerY, int radius, SDL_Color color);


int main()
{
    
    Application app;
    if (!app.initialize()) {
        return 0;
    }
 
    SDL_Renderer* render = Application::m_window_renderer;
    Player player(150, 50, 0, 0, 0, 0, 255, 255, true);

    const int TARGET_FPS = 60; // Target frame rate
    const Uint32 FRAME_DELAY = TARGET_FPS; // Delay per frame in milliseconds

    Uint32 previousTime = SDL_GetTicks();
    Uint32 elapsedTime = 0;

    while (app.isWindowOpen()) {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 deltaTime = currentTime - previousTime;

        // Check if enough time has passed to meet the frame delay
        if (deltaTime >= FRAME_DELAY) {
            previousTime = currentTime;

            // Your game logic and rendering code here

            // Calculate playerMovement based on deltaTime
            float desiredSpeed = 100.0f; // Desired speed in units per second
            float playerMovement = desiredSpeed * (deltaTime / 1000.0f); // Convert deltaTime to seconds

            // Handle events and update player position
            SDL_Event event;
            
            while (SDL_PollEvent(&event)) {
                player.direction(event);
                app.handleEvents(event);
            }

            // Render the player
            SDL_RenderClear(render);
            player.update(playerMovement);
            gridLayout(app, render);
            player.draw(render);
            SDL_RenderPresent(render);
        }
    }



    app.cleanup();
    return 0;
}


void gridLayout(Application &app, SDL_Renderer* render) {
    const int gridSize = 50;
    
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


void Apple(SDL_Renderer* render, int centerX, int centerY, int radius, SDL_Color color) {
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);

    for (int x = centerX - radius; x <= centerX + radius; x++) {
        for (int y = centerY - radius; y <= centerY + radius; y++) {
            int dx = x - centerX;
            int dy = y - centerY;
            if (dx * dx + dy * dy <= radius * radius) {
                SDL_RenderDrawPoint(render, x, y);
            }
        }
    }
}



