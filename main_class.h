#ifndef GUARD_MAIN_CLASS_H
#define GUARD_MAIN_CLASS_H

#include <SDL.h>
#include "error_handling.h"

//TODO: copy constructor

class MainClass {
public:
    MainClass();
    MainClass(const bool flag, const string &title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const u_int32_t h,const string &window_state);
    ~MainClass();
    void GameLoop();
private:
    bool quit_state;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *main_event;

    SDL_Texture *background_image;
    SDL_Texture *main_char_image;

    SDL_Rect background_rect;
    SDL_Rect main_char_rect;
};

#endif
