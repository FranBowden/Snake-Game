#include "player.hpp"

void pollEvent(Application &application, Player &player);

int main()
{
    Application app;
    
    if (!app.initialize()) {
        return 0;
    }
    
    Player player(50,50,100,100,100,0,100,255);
        
    while (app.isWindowOpen()) {
        player.draw();
    
        pollEvent(app, player);
        app.render();
    }
    
    app.cleanup();
    return 0;
}


void pollEvent(Application &application, Player &player) {
    SDL_Event event;
    
    if(SDL_PollEvent(&event)) {
        player.pollEvents(event);
        application.handleEvents(event);
    }
}
