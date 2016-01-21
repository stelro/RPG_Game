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

CSprite::~CSprite() {
    SDL_DestroyTexture(texture);
}
