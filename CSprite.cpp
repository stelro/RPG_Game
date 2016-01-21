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

    X_pos = x;
    Y_pos = y;

}

void CSprite::Draw() {
    SDL_RenderCopy(renderer,texture,nullptr,&t_rect);
}

void CSprite::SetX(const double X) {
    X_pos = X;
    t_rect.x = int(X_pos);
}

void CSprite::SetY(const double Y) {
    Y_pos = Y;
    t_rect.y = int(Y_pos);
}

void CSprite::SetPosition(const double X, const double Y) {
    Y_pos = Y;
    X_pos = X;
    t_rect.x = int(X_pos);
    t_rect.y = int(Y_pos);
}

double CSprite::GetX() const {
    return X_pos;
}

double CSprite::GetY() const {
    return Y_pos;
}

CSprite::~CSprite() {
    SDL_DestroyTexture(texture);
}
