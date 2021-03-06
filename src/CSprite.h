#ifndef GUARD_CSPRITE_H
#define GUARD_CSPRITE_H

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include "CollisionRectangle.h"

//TODO: constructors
//TODO: Error handling

class CSprite {
public:
    CSprite(SDL_Renderer *passed_renderer, const std::string FilePath, const int x, const int y, const int w, const int h, float *passed_CameraX, float *passed_CameraY, CollisionRect passed_CollisonRect);
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
    void DrawSteady();
    void PlayAnimation(int BeginFrame,int EndFrame, int Row, int Speed);
    void SetUpAnimation(const int x, const int y);
    bool isColliding(CollisionRect theCollider);
    CollisionRect GetCollisionRect();
    SDL_Rect GetPositionRect();
private:

    float *CameraX;
    float *CameraY;

    SDL_Texture *texture;
    SDL_Texture *CollisionImage;

    SDL_Rect Camera;
    SDL_Rect t_rect;
    SDL_Rect crop;
    int texture_width;
    int texture_height;
    int CurrentFrame;
    int animation_delay;
    SDL_Renderer *renderer;

    int Amount_Frame_X;
    int Amount_Frame_Y;

    double X_pos;
    double Y_pos;

    double Origin_x;
    double Origin_y;

    CollisionRect Collision_Rect;
};

#endif
