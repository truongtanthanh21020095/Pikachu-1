#ifndef _Shuffle_
#define _Shuffle_
void shuffle(SDL_Texture* texture,SDL_Renderer* renderer)
{
    SDL_RenderClear(renderer);
    sotexture = 0;
    SDL_Rect range;
    range.x = 0; range.y = 0;
    range.h = 650; range.w = 1050;
    SDL_RenderCopy(renderer, texture_backgroundImg, NULL, &range);
    printWord(texture,renderer,"Not Available Pair, Shuffle", 70, 150, 300, 0, 100, 255,"fonttime.ttf");
    SDL_RenderPresent(renderer);
    SDL_Delay(2500);
    timegame+=2500;
}
#endif // _Shuffle_
