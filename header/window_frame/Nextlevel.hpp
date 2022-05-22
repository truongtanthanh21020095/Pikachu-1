#ifndef _Nextlevel_
#define _Nextlevel_
void nextlevel(SDL_Texture* texture,SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);

    SDL_Rect range;

    range.x = 0; range.y = 0;
    range.h = 650; range.w = 1050;
    SDL_RenderCopy(renderer, texture_backgroundImg, NULL, &range);

    printWord(texture,renderer,"Next level", 100, 300, 250, 0, 100, 255,"fonttime.ttf");
    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    start(texture,renderer,false);
}
#endif // _Nextlevel_

