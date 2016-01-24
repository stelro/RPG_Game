#include "Trees.h"

Trees::Trees(int passed_x, int passed_y,float *passed_CameraX, float *passed_CameraY,SDL *csdl_setup) {

    CameraX = passed_CameraX;
    CameraY = passed_CameraY;

    x = passed_x;
    y = passed_y;

    Trunk = new CSprite(csdl_setup->GetRenderer(), "images/Trunk.png",x, y,43,145, passed_CameraX, passed_CameraY,CollisionRect(0,120,43,36));

    Crown = new CSprite(csdl_setup->GetRenderer(),"images/Crown.png", x-75, y-115,183,165, passed_CameraX, passed_CameraY, CollisionRect());
}

Trees::~Trees() {
    delete Trunk;
    delete Crown;
}

int Trees::GetX() const {
    return x;
}

int Trees::GetY() const {
    return y;
}

void Trees::DrawCrown() {
    Crown->Draw();
}

void Trees::DrawTrunk() {
    if (100 >= *CameraX + Trunk->GetPositionRect().y)
        Trunk->Draw();
}

CSprite *Trees::GetCrown()
{
    return Crown;
}

CSprite *Trees::GetTrunk()
{

    return Trunk;
}
