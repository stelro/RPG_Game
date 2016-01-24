#include "CSprite.h"

CSprite::CSprite(SDL_Renderer *passed_renderer, const std::string FilePath, const int x, const int y, const int w, const int h, float *passed_CameraX, float *passed_CameraY,CollisionRect passed_CollisonRect) {

    Collision_Rect =  passed_CollisonRect;
    renderer = passed_renderer;
    texture = nullptr;
    texture = IMG_LoadTexture(renderer, FilePath.c_str());

    if (texture == nullptr) {
        std::cerr << "Couldn't load image" << std::endl;
    }

    CollisionImage = nullptr;
    CollisionImage = IMG_LoadTexture(renderer, "images/collision.png");

    if (CollisionImage == nullptr) {
        std::cerr << "Couldn't load image" << std::endl;
    }

    // texture rectangle
    t_rect.x = x;
    t_rect.y = y;
    t_rect.w = w;
    t_rect.h = h;

    SDL_QueryTexture(texture, nullptr, nullptr,&texture_width, &texture_height);

    crop.x = 0;
    crop.y = 0;
    crop.w = texture_width;
    crop.h = texture_height;

    X_pos = x;
    Y_pos = y;

    Origin_x = 0;
    Origin_y = 0;

    CurrentFrame = 0;

    Amount_Frame_X = 0;
    Amount_Frame_Y = 0;

    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

    Camera.x = t_rect.x + *CameraX;
    Camera.y = t_rect.y + *CameraY;
    Camera.w = t_rect.w;
    Camera.h = t_rect.h;

}

void CSprite::PlayAnimation(int BeginFrame,int EndFrame, int Row, int Speed) {

    if (animation_delay+Speed  < SDL_GetTicks()) {

        if (EndFrame <= CurrentFrame) {
            CurrentFrame = BeginFrame;
        }
        else
            CurrentFrame++;

        crop.x = CurrentFrame * (texture_width / Amount_Frame_X);
        crop.y = Row * (texture_height / Amount_Frame_Y);
        crop.w = texture_width / Amount_Frame_X;
        crop.h = texture_height / Amount_Frame_Y;

        animation_delay = SDL_GetTicks();
    }
}

void CSprite::Draw() {

    Camera.x = t_rect.x + *CameraX;
    Camera.y = t_rect.y + *CameraY;

    Collision_Rect.SetX(t_rect.x + *CameraX);
    Collision_Rect.SetY(t_rect.y + *CameraY);

    SDL_RenderCopy(renderer,texture,&crop,&Camera);
    SDL_RenderCopy(renderer,CollisionImage,nullptr,&Collision_Rect.GetRectangle());
}

void CSprite::DrawSteady() {

    /* with this function , character wont be affected of
    camera */

    SDL_RenderCopy(renderer,CollisionImage,nullptr,&Collision_Rect.GetRectangle());
    SDL_RenderCopy(renderer,texture,&crop,&t_rect);

}

void CSprite::SetX(const double X) {
    X_pos = X;
    t_rect.x = int(X_pos - Origin_x);
}

void CSprite::SetY(const double Y) {
    Y_pos = Y;
    t_rect.y = int(Y_pos - Origin_y);
}

void CSprite::SetPosition(const double X, const double Y) {
    Y_pos = Y;
    X_pos = X;
    t_rect.x = int(X_pos - Origin_x);
    t_rect.y = int(Y_pos - Origin_y);
}

double CSprite::GetX() const {
    return X_pos;
}

double CSprite::GetY() const {
    return Y_pos;
}

void CSprite::SetWidth(const int w) {
    t_rect.w = w;
}

void CSprite::SetHeight(const int h) {
    t_rect.h = h;
}

int CSprite::GetWidth() const {
    return t_rect.w;
}

int CSprite::GetHeight() const {
    return t_rect.h;
}

void CSprite::SetOrigin(const double x,const double y) {
    Origin_x = x;
    Origin_y = y;

    SetPosition(GetX(),GetY());
}

void CSprite::SetUpAnimation(const int x, const int y) {
    Amount_Frame_X = x;
    Amount_Frame_Y = y;
}

bool CSprite::isColliding(CollisionRect theCollider)
{
    return !(Collision_Rect.GetRectangle().x + Collision_Rect.GetRectangle().w < theCollider.GetRectangle().x || Collision_Rect.GetRectangle().y + Collision_Rect.GetRectangle().h < theCollider.GetRectangle().y || Collision_Rect.GetRectangle().x > theCollider.GetRectangle().x + theCollider.GetRectangle().w || Collision_Rect.GetRectangle().y > theCollider.GetRectangle().y + theCollider.GetRectangle().h);
}

CSprite::~CSprite() {
    SDL_DestroyTexture(texture);
}
