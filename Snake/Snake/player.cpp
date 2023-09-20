#include "player.hpp"

Player::Player(Application &application, int w, int h, int x, int y, int r, int g, int b, int a) :
    Application(application), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
}

void Player::draw() const
{
    SDL_Rect rect;
    rect.x = _x;
    rect.y = _y;
    rect.w = _w;
    rect.h = _h;
    
    SDL_SetRenderDrawColor(m_window_renderer, 200, 0, 200, 255);
    SDL_RenderFillRect(m_window_renderer, &rect);
}

void Player::pollEvents(SDL_Event(&event)) {
        if(event.type == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    _x -= 10;
                    break;
                case SDLK_RIGHT:
                    _x += 10;
                    break;
                case SDLK_UP:
                    _y -= 10;
                    break;
                case SDLK_DOWN:
                    _y += 10;
                    break;
            }
        }
}
