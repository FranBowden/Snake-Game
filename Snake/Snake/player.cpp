#include "player.hpp"


//THE SNAKE information:
Player::Player(int w, int h, int x, int y, int r, int g, int b, int a, bool isControlled) :
     _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a), _isControlled(isControlled)
{
}

//draws snake onto application
void Player::draw(SDL_Renderer* m_window_renderer)
{
   
    SDL_Rect player;
    player.x = _x;
    player.y = _y;
    player.w = _w;
    player.h = _h;
    
    SDL_SetRenderDrawColor(Application::m_window_renderer, _r, _g, _b, _a);
    SDL_RenderFillRect(Application::m_window_renderer, &player);
}

//direction player wants
void Player::direction(SDL_Event(&event)) {
    if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym) {
            case SDLK_DOWN:
            case SDLK_UP:
                vertical();
              //  autoMoveY(playerMovement);
                std::cout << "Down/Up" << std::endl;
                break;
            case SDLK_RIGHT:
            case SDLK_LEFT:
                horizontal();
                std::cout << "Left/Right" << std::endl;
                break;
        }
    }
}

void Player::update(float playerMovement) {
    
        
        autoMoveX(playerMovement);
    
    
}


void Player::autoMoveX(float playerMovement) {
        _x += playerMovement;
        std::cout << "X: " << _x << std::endl;;
        
    
}

void Player::autoMoveY(float playerMovement) {
        _y += playerMovement;
        std::cout << "Y: " << _x << std::endl;;
    
}


void Player::vertical() {
    if(_isHorizontal) {
        _isHorizontal = false;
        int width = _h;
        int height = _w;
        _w = width;
        _h = height;
        std::cout << "W: "<< _w << " H: " << _h << std::endl;
        
    }
}

void Player::horizontal() {
    if(_isHorizontal == false) {
        _isHorizontal = true;
        int width = _h;
        int height = _w;
        _w = width;
        _h = height;
        std::cout << "W: "<< _w << " H: " << _h << std::endl;
        
    }
}
