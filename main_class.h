#ifndef GUARD_MAIN_CLASS_H
#define GUARD_MAIN_CLASS_H

#include <iostream>
#include "_sdl.h"

//TODO: copy constructor

class MainClass  {
public:
    MainClass();
    MainClass(const bool flag, const char *title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const uint32_t h);
    ~MainClass();
    void GameLoop();
private:
    bool quit_state;
    SDL_Texture *background_image;
    SDL_Texture *main_char_image;
    SDL_Rect background_rect;
    SDL_Rect main_char_rect;

    SDL* csdl_setup;
};

#endif
