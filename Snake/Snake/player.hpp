#pragma once
#include "application.h"

class Player : public Application {
public:
    Player(Application &application, int w, int h, int x, int y, int r, int g, int b, int a);
   
    void pollEvents(SDL_Event(&event));
    void draw() const;
    
private:
    int _w, _h;
    int _x, _y;
    int _r, _g, _b, _a;
};
