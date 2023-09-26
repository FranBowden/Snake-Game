#pragma once
#include "application.h"

class Player {
public:
    Player(int w, int h, int x, int y, int r, int g, int b, int a, bool isControlled);
    void draw(SDL_Renderer *m_window_renderer);
    void autoMoveX(float playerMovement);
    void autoMoveY(float playerMovement);
    void vertical();
    void horizontal();
    void update(float playerMovement);
    void direction(SDL_Event(&event));
private:
    int _w, _h;
    int _x, _y;
    int _r, _g, _b, _a;
    bool _isControlled;
    bool _isHorizontal = true; // Variable to track the orientation
};
