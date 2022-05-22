#ifndef _inchu_
#define _inchu_
void printWord(SDL_Texture* texture, SDL_Renderer* renderer, string text,int sizetext, int xx, int yy, int r, int g, int b,string fonts)
{
    TTF_Font* font = NULL;

    if(fonts == "NightmareCodehack.ttf") font = TTF_OpenFont( "fonts/NightmareCodehack.otf", sizetext);
    if(fonts == "fonttime.ttf") font = TTF_OpenFont( "fonts/fonttime.ttf", sizetext);
    if(fonts == "Montague.ttf") font = TTF_OpenFont( "fonts/Montague.ttf", sizetext);
    if(fonts == "SinCity.ttf") font = TTF_OpenFont( "fonts/SinCity.ttf", sizetext);
    if(fonts == "pocket_calcuatlor_tt.ttf") font = TTF_OpenFont( "fonts/pocket_calcuatlor_tt.ttf", sizetext);
    if(fonts == "junegull.ttf") font = TTF_OpenFont( "fonts/junegull.ttf", sizetext);
    if(font == NULL) cout<<fonts<<endl;
    SDL_Color fg = { r, g, b };
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), fg);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

	srcRest.x = 0;
	srcRest.y = 0;

	desRect.x = xx;
	desRect.y = yy;

	desRect.w = srcRest.w;
	desRect.h = srcRest.h;
	SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
}
#endif // _inchu_
