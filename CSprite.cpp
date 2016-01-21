#include "CSprite.h"

CSprite::CSprite(SDL_Renderer *passed_renderer, const std::string FilePath, const int x, const int y, const int w, const int h) {

    renderer = passed_renderer;
    texture = nullptr;
    texture = IMG_LoadTexture(renderer, FilePath.c_str());

    if (texture == nullptr) {
        std::cerr << "Couldn't load image" << std::endl;
    }

    t_rect.x = x;
    t_rect.y = y;
    t_rect.w = w;
    t_rect.h = h;

}

void CSprite::Draw() {
    SDL_RenderCopy(renderer,texture,nullptr,&t_rect);
}

void CSprite::SetX(const int X) {
    t_rect.x = X;
}

void CSprite::SetY(const int Y) {
    t_rect.y = Y;
}

void CSprite::SetPosition(const int X, const int Y) {
    t_rect.x = X;
    t_rect.y = Y;
}

int CSprite::GetX() const {
    return t_rect.x;
}

int CSprite::GetY() const {
    return t_rect.y;
}

CSprite::~CSprite() {
    SDL_DestroyTexture(texture);
}
