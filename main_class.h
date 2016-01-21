#ifndef GUARD_MAIN_CLASS_H
#define GUARD_MAIN_CLASS_H

#include "_sdl.h"
#include "CSprite.h"

//TODO: copy constructor

class MainClass  {
public:
    MainClass();
    MainClass(const bool flag, const char *title, const int pos_x, const int pos_y, const int w, const int h);
    ~MainClass();
    void GameLoop();
private:
    bool quit_state;
    SDL* csdl_setup;

    //-------------------------
    //Creating objects on the screen
    //-------------------------

    CSprite *background_img;
    CSprite *main_char;

    //-----------------------
    //Main character movments
    //-----------------------

    bool MoveRight;
    bool MoveLeft;
    bool MoveUp;
    bool MoveDown;

    size_t timeCheck;
};

#endif
