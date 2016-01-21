#ifndef GUARD_CSPRITE_H
#define GUARD_CSPRITE_H

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>

//TODO: constructors
//TODO: Error handling

class CSprite {
public:
    CSprite(SDL_Renderer *passed_renderer, const std::string FilePath, const int x, const int y, const int w, const int h);
    ~CSprite();
    void SetX(const int X);
    void SetY(const int Y);
    void SetPosition(const int X, const int Y);
    int GetX() const;
    int GetY() const;
    void Draw();
private:
    SDL_Texture *texture;
    SDL_Rect t_rect;
    SDL_Renderer *renderer;
};

#endif
