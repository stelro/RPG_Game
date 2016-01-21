#ifndef GUARD_SDL_INITIALIZER
#define GUARD_SDL_INITIALIZER

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "error_handling.h"

class SDL {
public:
    SDL();
    SDL(Uint32 flags, bool *quit_state,const char *title, const uint32_t pos_x, const uint32_t pos_y, const uint32_t w, const uint32_t h) throw(InitError);
    virtual ~SDL();
    SDL_Renderer *GetRenderer() const;
    SDL_Event *GetMainEvent() const;
    void SdlBegin() const;
    void SdlEnd() const;
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event *main_event;
};

#endif
