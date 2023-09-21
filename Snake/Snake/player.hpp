#pragma once
#include "application.h"

class Player {
public:
    Player(int w, int h, int x, int y, int r, int g, int b, int a, bool isControlled);
   
    void pollEvents(SDL_Event(&event));
    void draw(SDL_Renderer *m_window_renderer) const;
    
private:
    int _w, _h;
    int _x, _y;
    int _r, _g, _b, _a;
    bool _isControlled; 
};
