#ifndef GUARD_SDL_INITIALIZER
#define GUARD_SDL_INITIALIZER

#include <SDL.h>
#include "error_handling.h"

class SDL {
public:
    SDL(Uint32 flags = 0) throw(InitError);
    virtual ~SDL();
};

#endif
