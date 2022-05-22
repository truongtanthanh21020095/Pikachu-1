#ifndef _mapPrinter_
#define _mapPrinter_

#include "./tools/NumberToString.hpp"
#include "./tools/wordPrinter.hpp"

void printMap(SDL_Texture* texture, SDL_Renderer* renderer)
{
    sotexture = 0;
    timegame = timegame - clock() + time_elapsed;
    time_elapsed = clock();
    int phut = timegame / 60000;
    int sec = (timegame - 60000 * phut) / 1000;
    SDL_RenderClear(renderer);
    SDL_Rect range;

    range.x = 0; range.y = 0;
    range.h = 650; range.w = 1050;
    SDL_RenderCopy(renderer, texture_backgroundImg, NULL, &range);

    range.x = 35; range.y = 550;
    range.h = 80; range.w = 140;
    SDL_RenderCopy(renderer, texture_hint, NULL, &range);

    range.x = 402; range.y = 570;
    range.h = 60; range.w = 60;
    if (unmuteSound == true) SDL_RenderCopy(renderer, texture_unmuteSound, NULL, &range);
    else SDL_RenderCopy(renderer, texture_muteSound, NULL, &range);

    range.x = 703; range.y = 570;
    range.h = 60; range.w = 60;
    SDL_RenderCopy(renderer, texture_pauseGame, NULL, &range);

    range.x = 969;  range.y = 60;
    range.h = 479; range.w = 33;
    SDL_RenderCopy(renderer, texture_bgtime, NULL, &range);

    range.x = 975;  range.y = 68;
    range.h = 469; range.w = 23;
    SDL_RenderCopy(renderer, texture_time, NULL, &range);

    range.x = 969;  range.y = 68;
    range.h = (480000 - timegame) * 469 / 480000; range.w = 33;
    SDL_RenderCopy(renderer, texture_bgtime, NULL, &range);

    //hints
    printWord(texture, renderer, change_NumberToString(numOfHints), 80, 80, 550, 243, 156, 18, "pocket_calcuatlor_tt.ttf");

    //level
    printWord(texture, renderer, "LEVEL", 60, 35, 200, 243, 156, 18, "pocket_calcuatlor_tt.ttf");
    printWord(texture, renderer, change_NumberToString(int(level + 1)), 60, 80, 260, 243, 156, 18, "pocket_calcuatlor_tt.ttf");

    //score
    printWord(texture, renderer, "SCORES", 60, 35, 340, 243, 156, 18, "pocket_calcuatlor_tt.ttf");
    string ssss;
    ssss = change_NumberToString(Score);
    printWord(texture, renderer, ssss, 60, 100 - ssss.length() * 10, 400, 243, 156, 18, "pocket_calcuatlor_tt.ttf");

    //time
    printWord(texture, renderer, change_NumberToString(phut), 40, 945, 560, 243, 156, 18, "fonttime.ttf");
    printWord(texture, renderer, " : ", 40, 960, 560, 243, 156, 18, "fonttime.ttf");
    ssss = change_NumberToString(sec);
    printWord(texture, renderer, change_NumberToString(sec), 40, 1005 - ssss.length() * 5, 560, 243, 156, 18, "fonttime.ttf");

    //in mảng quái 9x16
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 16; j++)
            if (monstevalue[i][j] > 0 && monstevalue[i][j] <= 36)
            {
                SDL_Rect range;

                range.x = 230 + (j - 1) * 43; range.y = 60 + (i - 1) * 53;
                range.h = 50; range.w = 40;

                SDL_RenderCopy(renderer, texture_monster[monstevalue[i][j]], NULL, &range);
            }
    // background xanh mờ khi click vào quái 
    if (monsterClicked >= 1 && monsterOxy[1].j >= 1 && monsterOxy[1].j <= 16 && monsterOxy[1].i >= 1 && monsterOxy[1].i <= 9)
    {
        if (monstevalue[monsterOxy[1].i][monsterOxy[1].j] > 0) {
            SDL_Rect range;
            range.x = 230 + (monsterOxy[1].j - 1) * 43 - 3; 
            range.y = 60 + (monsterOxy[1].i - 1) * 53 - 3;
            range.h = 56; range.w = 46;
            SDL_RenderCopy(renderer, texture_picking, NULL, &range);
        }
    }
    SDL_RenderPresent(renderer);
}

#endif // _mapPrinter_

