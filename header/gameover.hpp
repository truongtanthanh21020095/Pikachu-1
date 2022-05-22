#ifndef _gameover_
#define _gameover_
void gameover(SDL_Texture* texture,SDL_Renderer* renderer)
{
    cout<<"end"<<endl;
    sotexture = 0;
    SDL_RenderClear(renderer);
    SDL_Rect range;
    range.x = 0; range.y = 0;
    range.h = 650; range.w = 1050;
    SDL_RenderCopy(renderer, texture_backgroundImg, NULL, &range);
    printWord(texture,renderer,"Game Over", 50, 300, 300, 0, 100, 255,"SinCity.ttf");
    SDL_RenderPresent(renderer);
    for(int i = 0;i <= 39; i++) monste[i] = 0;
    SDL_Delay(5000);
    start(texture,renderer,true);
    createmap(texture,renderer);
}
#endif // _gameover_

