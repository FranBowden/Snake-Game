#include "player.hpp"

Player::Player(int w, int h, int x, int y, int r, int g, int b, int a, bool isControlled) :
     _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a), _isControlled(isControlled)
{
}

void Player::draw(SDL_Renderer* m_window_renderer) const
{
    SDL_Rect player;
    player.x = _x;
    player.y = _y;
    player.w = _w;
    player.h = _h;
    
    SDL_SetRenderDrawColor(Application::m_window_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Application::m_window_renderer, &player);
}

void Player::pollEvents(SDL_Event(&event)) {
        if(_isControlled && event.type  == SDL_KEYDOWN) {
            switch(event.key.keysym.sym) {
                case SDLK_LEFT:
                    _x -= 10 ;
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
