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
    void SetX(const double X);
    void SetY(const double Y);
    void SetPosition(const double X, const double Y);
    double GetX() const;
    double GetY() const;
    void SetWidth(const int w);
    void SetHeight(const int h);
    int GetWidth() const;
    int GetHeight() const;
    void SetOrigin(const double x, const double y);
    void Draw();
private:
    SDL_Texture *texture;
    SDL_Rect t_rect;
    SDL_Renderer *renderer;

    double X_pos;
    double Y_pos;

    double Origin_x;
    double Origin_y;
};

#endif
