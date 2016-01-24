#ifndef GUARD_COLLISION_RECTANGLE
#define GUARD_COLLISION_RECTANGLE

#include <SDL.h>

class CollisionRect {
public:
    CollisionRect();
    CollisionRect(int x, int y, int w, int h);
    ~CollisionRect();
    void SetRectangle(const int x, const int y, const int w, const int h);
    const SDL_Rect& GetRectangle();
    void SetX(const int x);
    void SetY(const int y);
private:
    int OffsetX;
    int OffsetY;
    SDL_Rect CollisionRectangle;
};

#endif
