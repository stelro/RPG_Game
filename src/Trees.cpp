#include "Trees.h"

Trees::Trees(int passed_x, int passed_y,float *CameraX, float *CameraY,SDL *csdl_setup) {

    x = passed_x;
    y = passed_y;

    Trunk = new CSprite(csdl_setup->GetRenderer(), "images/Trunk.png",x, y,43,145, CameraX, CameraY);

    Crown = new CSprite(csdl_setup->GetRenderer(),"images/Crown.png", x-75, y-115,183,165, CameraX, CameraY);
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
    Trunk->Draw();
}
