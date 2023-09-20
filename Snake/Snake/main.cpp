#include "player.hpp"

void pollEvent(Application &application, Player &player) {
    SDL_Event event;
    
    if(SDL_PollEvent(&event)) {
        player.pollEvents(event);
        application.handleEvents(event);
    }
        
}

int main()
{
    Application app;
    
    if (!app.initialize()) {
        return 0;
    }
    
    Player player(app,120,120,100,100,100,0,100,255);
    
    
  
        
    while (app.isWindowOpen()) {
        player.draw();
        pollEvent(app, player);
        app.render();
    }
    
    // Cleanup and shutdown
    app.cleanup();
    return 0;
}


