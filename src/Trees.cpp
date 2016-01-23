#include "Trees.h"

Trees::Trees(int x, int y,float *CameraX, float *CameraY,SDL *csdl_setup) {

    Trunk = new CSprite(csdl_setup->GetRenderer(), "images/Trunk.png",x, y,43,145, CameraX, CameraY);

    Crown = new CSprite(csdl_setup->GetRenderer(),"images/Crown.png", x-75, y-115,183,165, CameraX, CameraY);
}

Trees::~Trees() {
    delete Trunk;
    delete Crown;
}

void Trees::DrawCrown() {
    Crown->Draw();
}

void Trees::DrawTrunk() {
    Trunk->Draw();
}
