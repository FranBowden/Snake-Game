#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

class Application {
public:
    Application();
    ~Application();

    bool initialize();
    void handleEvents(SDL_Event(&event));
    void cleanup();
    bool isWindowOpen() const;
    void render();
    int windowWidth = 500;
    int windowHeight = 500;
    
private:
    SDL_Window *m_window;;
    SDL_Event m_window_event;
    bool m_keep_window_open; // New member variable to track window state
    
public:
  static SDL_Renderer *m_window_renderer;
};
