#ifndef GUARD_MAIN_CLASS_H
#define GUARD_MAIN_CLASS_H

#include "_sdl.h"
#include "CSprite.h"
#include "MainCharacter.h"
#include "CEnvironment.h"
#include <cmath>

//TODO: copy constructor

class MainClass  {
public:
    MainClass();
    MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h);
    ~MainClass();
    void GameLoop();
private:
    float CameraX;
    float CameraY;

    Environment* Stage1_Area;
    MainCharacter *main_char;
    bool quit_state;
    SDL* csdl_setup;
    //-------------------------
    //Creating objects on the screen
    //-------------------------

    int MouseX;
    int MouseY;
};

#endif
