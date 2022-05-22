#ifndef _start_
#define _start_

#include "./tools/wordPrinter.hpp"

void print(SDL_Texture* texture,SDL_Renderer* renderer,bool newgame,bool zoom1,bool zoom2,bool zoom3)
{
    sotexture = 0;
    SDL_RenderClear(renderer);

    SDL_Rect range;

    range.x = 0; range.y = 0;
    range.h = 650; range.w = 1050;
    SDL_RenderCopy(renderer, texture_start, NULL, &range);



    range.x = 930; range.y = 545;
    range.h = 70 ; range.w = 70;
    if(unmuteSound == true) SDL_RenderCopy(renderer, texture_unmuteSound, NULL, &range);
        else SDL_RenderCopy(renderer, texture_muteSound, NULL, &range);

    if(newgame == false)
        {
            string text = "START";
            if(zoom1 ==  false) printWord(texture, renderer, text, 75, 750, 300, 243, 156, 18, "Montague.ttf");
                else printWord(texture, renderer, text, 85, 730, 300, 243, 156, 18, "Montague.ttf");
        }
    string text = "New Game";
    if(zoom2 == false) printWord(texture, renderer, text, 75, 680, 400, 243, 156, 18, "Montague.ttf");
        else printWord(texture, renderer, text, 85, 660, 400, 243, 156, 18, "Montague.ttf");

    if(zoom3 == false) printWord(texture, renderer, "Quit", 50, 930, 490, 243, 156, 18, "Montague.ttf");
        else printWord(texture, renderer, "Quit", 55, 930, 490, 243, 156, 18, "Montague.ttf");
    SDL_RenderPresent(renderer);
}
void start(SDL_Texture* texture,SDL_Renderer* renderer,bool newgame)
{
    print(texture,renderer,newgame,false,false,false);//hiện ra menu ban đầu 
    SDL_Event e;
    while (true)
        {
        SDL_Delay(10);
        if ( SDL_WaitEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT) {   quitSDL(window, renderer); break;}
        if (e.type == SDL_MOUSEMOTION)
        {
            int xx = e.button.x;
            int yy = e.button.y;
            bool zoom1 = false;
            bool zoom2 = false;
            bool zoom3 = false;
            if(xx >= 670 && xx <= 1010 && yy >= 420 && yy <= 470)   { if(zoom1 == false) print(texture,renderer,newgame,false,true,false); zoom1 = true;}
                else
                    {
                        zoom1 = false;
                        if(xx >= 750 && xx <= 930 && yy >= 320 && yy <= 370)    { if(zoom2 == false) print(texture,renderer,newgame,true,false,false); zoom2 = true;}
                            else
                                {
                                    zoom2 = false;
                                    if(xx >= 930 && xx <= 1030 && yy >= 490 && yy <= 530)    { if(zoom3 == false) print(texture,renderer,newgame,false,false,true); zoom3 = true;}
                                    else { zoom3 = false; print(texture,renderer,newgame,false,false,false);}
                                }
                    }
        }
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            int xx = e.button.x;
            int yy = e.button.y;
            if(unmuteSound == true )
            {
                Mix_Chunk* chunk = NULL;
                chunk = Mix_LoadWAV("Music/sound2.wav");
                if (chunk == NULL)  printf("%s", Mix_GetError());
                Mix_PlayChannel(-1, chunk, 0);
            }
            if(xx >= 930 && xx <= 1000 && yy >= 545 && yy <= 615)
            {
                if(unmuteSound == true) { unmuteSound = false; Mix_PauseMusic(); }
                else { unmuteSound = true; Mix_ResumeMusic(); }
                print(texture,renderer,newgame,false,false,false);
            }
            if(xx >= 670 && xx <= 1010 && yy >= 420 && yy <= 470)
                {
                level = 0;
                for(int i=1;i<=36;i++) monste[i]=0;
                Score = 0;
                numOfHints = 5;
                timegame = 480000;
                createmap(texture,renderer);
                monsterClicked = 0;
                break;
                }
            if(xx >= 930 && xx <= 1030 && yy >= 500 && yy <= 530) {   
                quitSDL(window, renderer); quit = true; break;
            }
            if(xx >= 750 && xx <= 930 && yy >= 320 && yy <= 370)
                break;

        }
        }
}
#endif // _start_
