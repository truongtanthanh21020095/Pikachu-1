#ifndef _create_texture_
#define _create_texture_

void create_texture()
{
    //IMG_LoadTexture(SDL_Renderer *renderer, const char *file)
    texture_backgroundImg = IMG_LoadTexture(renderer, "pictures/bgpikachu.png");
    texture_start = IMG_LoadTexture(renderer, "pictures/Start.png");
    texture_hint  = IMG_LoadTexture(renderer, "pictures/gamehints.png");
    texture_picking = IMG_LoadTexture(renderer, "pictures/load01.png");
    texture_unmuteSound = IMG_LoadTexture(renderer, "pictures/unmuteSound.png");
    texture_muteSound = IMG_LoadTexture(renderer, "pictures/muteSound.png");
    texture_pauseGame = IMG_LoadTexture(renderer, "pictures/pause.png");
    texture_bgtime = IMG_LoadTexture(renderer, "pictures/bgtime.png");
    texture_time = IMG_LoadTexture(renderer, "pictures/timebar.png");
    texture_noigoc1 = IMG_LoadTexture(renderer, "pictures/noigoc1.png");
    texture_noigoc2 = IMG_LoadTexture(renderer, "pictures/noigoc2.png");
    texture_noigoc3 = IMG_LoadTexture(renderer, "pictures/noigoc3.png");
    texture_noigoc4 = IMG_LoadTexture(renderer, "pictures/noigoc4.png");
    texture_noingang = IMG_LoadTexture(renderer, "pictures/noingang.png");
    texture_noingang2 = IMG_LoadTexture(renderer, "pictures/noingang2.png");
    texture_noingang4 = IMG_LoadTexture(renderer, "pictures/noingang4.png");
    texture_noithang = IMG_LoadTexture(renderer, "pictures/noithang.png");
    texture_noithang1 = IMG_LoadTexture(renderer, "pictures/noithang1.png");
    texture_noithang3 = IMG_LoadTexture(renderer, "pictures/noithang3.png");
    for(int i = 1; i <= 36; i++)
    {
        string file = "pictures/";
        file += change_NumberToString( i );
        file += ".png";
        texture_monster[i] = IMG_LoadTexture(renderer, file.c_str());
    }
}
#endif // _create_texture_
