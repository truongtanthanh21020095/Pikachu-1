#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <fstream>

using namespace std;

struct arrayChecker
{
    int i1;
    int i3;
    int j2;
    int j4;
};

struct coordinate
{
    int i;
    int j;
};

int monstevalue[20][20], monste[40], level;
arrayChecker Plus_sign[20][20]; //lưu lại dấu + để in đường đi
bool unmuteSound = true;
int numOfHints, Score;
SDL_Window* window;
clock_t timegame, time_elapsed;
coordinate monsterOxy[2+1]; // Lưu tọa độ Oxy con quái đang được chọn
int monsterClicked = 0;
bool quit;
int sotexture;
SDL_Texture* texture_backgroundImg;
SDL_Texture* texture_start;
SDL_Texture* texture_hint;
SDL_Texture* texture_monster[100];
SDL_Texture* texture_picking;
SDL_Texture* texture_unmuteSound;
SDL_Texture* texture_muteSound;
SDL_Texture* texture_pauseGame;
SDL_Texture* texture_bgtime;
SDL_Texture* texture_time;
SDL_Texture* texture_noigoc1;
SDL_Texture* texture_noigoc2;
SDL_Texture* texture_noigoc3;
SDL_Texture* texture_noigoc4;
SDL_Texture* texture_noingang;
SDL_Texture* texture_noingang2;
SDL_Texture* texture_noingang4;
SDL_Texture* texture_noithang;
SDL_Texture* texture_noithang1;
SDL_Texture* texture_noithang3;

SDL_Renderer* renderer;

#include "./header/tools/SDL_default.hpp"
#include "./header/endlevel.hpp"
#include "./header/testtwopoints.hpp"
#include "./header/mapChecker.hpp"
#include "./header/mapPrinter.hpp"
#include "./header/create_map.hpp"
#include "./header/start.hpp"
#include "./header/timduongdi.hpp"
#include "./header/gamehints.hpp"
#include "./header/levelgame.hpp"
#include "./header/Solve_Event.hpp"
#include "./header/file_work/ReadFile.hpp"
#include "./header/file_work/WriteFile.hpp"
#include "./header/create_texture.hpp"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    SDL_Surface* surface;
    SDL_Texture* texture = NULL;
    Mix_Music* music = NULL;

    initSDL(window, renderer);
    create_texture(); // add hết ảnh quái vào ram 
    quit = false;
    //---- Xử lí âm thanh
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) printf("%s", Mix_GetError());
    music = Mix_LoadMUS("Music/nen.mp3");
    if (music == NULL) printf("%s", Mix_GetError());
    Mix_PlayMusic(music, -1);

    if (TTF_Init() < 0) SDL_Log("%s", TTF_GetError());
    // Check xem game còn chơi dở không, nếu k thì tạo game mới 
    ReadFile();
    bool newgame;
    if (level == 0 && endlevel() == true) newgame = true;
    else newgame = false;
    start(texture, renderer, newgame);
    if (endlevel()) newgame = false;

    if (quit == false) SolveEvent(texture, renderer);
    TTF_Quit();
    Mix_CloseAudio();
    quitSDL(window, renderer);
    WriteFile();
    return 0;
}
