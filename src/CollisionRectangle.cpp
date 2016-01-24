#include "CollisionRectangle.h"

CollisionRect::CollisionRect(int x, int y, int w, int h)
{
    OffsetX = x;
    OffsetY = y;
    SetRectangle(0,0,w,h);
}

CollisionRect::CollisionRect()
{
    OffsetX = 0;
    OffsetY = 0;
    SetRectangle(0,0,0,0);
}

CollisionRect::~CollisionRect()
{

}

void CollisionRect::SetX(const int x)
{

    CollisionRectangle.x = x + OffsetX;
}

void CollisionRect::SetY(const int y)
{
    CollisionRectangle.y = y + OffsetY;
}

void CollisionRect::SetRectangle(const int x, const int y, const int w, const int h)
{
    CollisionRectangle.x = x + OffsetX;
    CollisionRectangle.y = y + OffsetY;
    CollisionRectangle.w = w;
    CollisionRectangle.h = h;
}

const SDL_Rect &CollisionRect::GetRectangle()
{
    return CollisionRectangle;
}
