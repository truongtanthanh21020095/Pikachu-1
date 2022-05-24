#ifndef _Solve_Event_
#define _Solve_Event_
#include "./window_frame/Shuffle.hpp"
#include "./window_frame/Nextlevel.hpp"
#include "gameover.hpp"

void SolveEvent (SDL_Texture* texture,SDL_Renderer* renderer)
{
    if(endlevel() == true) createmap(texture,renderer);
        else  printMap(texture,renderer);
    SDL_Event e;
    time_elapsed = clock();
    while (true)
    {
        if(quit == true ) break;
        SDL_Delay(10);
        if(clock()-time_elapsed >= 1000)    printMap(texture,renderer);
        if(timegame <= 0) gameover(texture,renderer);
        if(SDL_PollEvent(&e))
        if (e.type == SDL_QUIT) {   quitSDL(window, renderer); quit = true; break;}
        else
        if (e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(unmuteSound == true )
            {
                Mix_Chunk* chunk = NULL;
                chunk = Mix_LoadWAV("Music/sound2.wav");
                if (chunk == NULL)  printf("%s", Mix_GetError());
                Mix_PlayChannel(-1, chunk, 0);
            }
            int xx = e.button.x;
            int yy = e.button.y;
            if(xx < 230 || yy < 60 )
            if(xx >= 40 && xx <= 180  &&  yy >= 475 && yy <= 615) //Hints button
            {
                monsterClicked = 0;
                if(numOfHints >= 1){
                    numOfHints--;
                    hint(texture,renderer); 
                }
                SDL_Delay(200);
            }
            if(xx >= 402 && xx <= 462 && yy >= 560 && yy <= 620) //Mute sound button
            {
                if(unmuteSound == true) { unmuteSound = false; Mix_PauseMusic(); }
                else { unmuteSound = true; Mix_ResumeMusic(); }
                printMap(texture,renderer);
            }
            if(xx >= 703 && xx <= 763 && yy >= 560 && yy <= 620) //Clock
            {
                timegame = timegame - clock() + time_elapsed;
                start( texture, renderer, false);
                if(quit == true) break;
                time_elapsed = clock();
                printMap( texture, renderer);
            }
            xx-= 230;
            yy-= 60;
            // Events when click on monster btn 
            if(xx >= 0 && yy >= 0)
            {
                monsterClicked ++;
                monsterOxy[monsterClicked].j = (xx/43)+1;
                monsterOxy[monsterClicked].i = (yy/53)+1;

                if(monsterOxy[monsterClicked].j >= 1 && monsterOxy[monsterClicked].j <= 16 && monsterOxy[monsterClicked].i >= 1 && monsterOxy[monsterClicked].i <= 9)
                    if(monstevalue[monsterOxy[monsterClicked].i][monsterOxy[monsterClicked].j] > 0)
                    {
                        SDL_Rect range;
                        range.x = 230 + (monsterOxy[monsterClicked].j-1)*43 - 3; range.y = 60 + (monsterOxy[monsterClicked].i-1)*53 - 3;
                        range.h = 56; range.w = 46;
                        SDL_RenderCopy(renderer, texture_picking, NULL, &range);
                        SDL_RenderPresent(renderer);
                    }
                if (monsterClicked == 2 )
                    if(monsterOxy[1].i == monsterOxy[2].i && monsterOxy[1].j == monsterOxy[2].j) monsterClicked = 0;
                    else {
                        kiemtra();
                            if(monstevalue[monsterOxy[1].i][monsterOxy[1].j] == monstevalue[monsterOxy[2].i][monsterOxy[2].j]  &&  monstevalue[monsterOxy[1].i][monsterOxy[1].j]!=0) {
                                int quai = monstevalue[monsterOxy[1].i][monsterOxy[1].j];
                                if(timduongdi(texture,renderer,monsterOxy[1].i,monsterOxy[1].j,monsterOxy[2].i,monsterOxy[2].j) == true)
                                {
                                    monsterClicked = 0;
                                    SDL_Delay(10);
                                    monste[quai] -= 1;
                                    levelgame(level);
                                    if(unmuteSound == true )
                                        {
                                            Mix_Chunk* chunk = NULL;
                                            chunk = Mix_LoadWAV("Music/sound4.wav");
                                            if (chunk == NULL)  printf("%s", Mix_GetError());
                                            Mix_PlayChannel(-1, chunk, 0);
                                        }
                                    SDL_Delay(100);
                                    printMap(texture,renderer);
                                    SDL_Delay(150);
                                    if(unmuteSound == true )
                                        {
                                            Mix_Chunk* chunk = NULL;
                                            chunk = Mix_LoadWAV("Music/sound3.wav");
                                            if (chunk == NULL)  printf("%s", Mix_GetError());
                                            Mix_PlayChannel(-1, chunk, 0);
                                        }
                                    SDL_Delay(50);
                                    if(endlevel()) {
                                            level++ ;
                                            if(numOfHints <= 9) numOfHints++;
                                            timegame = 360000;
                                            nextlevel(texture,renderer);
                                            createmap(texture,renderer);
                                    } 
                                    else
                                    {
                                    if(kiemtra() == 0)
                                            {
                                                shuffle(texture, renderer);
                                                createmap(texture, renderer);
                                            }
                                    }
                                }
                                else if(unmuteSound == true ) {
                                        Mix_Chunk* chunk = NULL;
                                        chunk = Mix_LoadWAV("Music/sound1.wav");
                                        if (chunk == NULL)  printf("%s", Mix_GetError());
                                        Mix_PlayChannel(-1, chunk, 0);
                                 }
                            }
                            else if(unmuteSound == true ){
                                    Mix_Chunk* chunk = NULL;
                                    chunk = Mix_LoadWAV("Music/sound1.wav");
                                    if (chunk == NULL)  printf("%s", Mix_GetError());
                                    Mix_PlayChannel(-1, chunk, 0);
                                }
                            printMap(texture,renderer);
                            monsterClicked = 0;
                            }
                    if(monsterClicked != 1) {
                        printMap(texture,renderer);
                        SDL_Delay(100);
                    }
               }
        }
        }
}

#endif // _Solve_Event_
