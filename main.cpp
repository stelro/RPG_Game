#include <iostream>
#include <string>
#include "main_class.h"

const uint32_t WINDOW_POS_X{0};
const uint32_t WINDOW_POS_Y{0};
const uint32_t WINDOW_WIDTH_PX{1024};
const uint32_t WINDOW_HEIGHT_PX{768};


int main(int argc, char **argv)
{

    MainClass *game_init = new MainClass(false,"RPG",WINDOW_POS_X,
    WINDOW_POS_Y,
    WINDOW_WIDTH_PX,
    WINDOW_HEIGHT_PX);

    game_init->GameLoop();

    delete game_init;

    return 0;

}
