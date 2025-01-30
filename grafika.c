#include "grafika.h"

void babu_rajzol(SDL_Renderer *renderer, SDL_Texture *babuk, Piece melyik, int x, int y) {
    SDL_Rect src = { (melyik % 6) * 157 + 14, (melyik / 6) * 135 + 15, 2*MERET, 2*MERET };
    SDL_Rect dest = { x, y, MERET, MERET };
    SDL_RenderCopy(renderer, babuk, &src, &dest);
}

void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }
    SDL_Window *window = SDL_CreateWindow(felirat, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, szeles, magas, 0);
    if (window == NULL) {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Nem hozhato letre a megjelenito: %s", SDL_GetError());
        exit(1);
    }
    SDL_RenderClear(renderer);

    *pwindow = window;
    *prenderer = renderer;
}

void tabla_rajz(SDL_Renderer *renderer){
    /* tabla rajz */
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j+=2){
            boxRGBA(renderer,j*50,i*50,j*50+50,i*50+50,255,255,255,255);
            boxRGBA(renderer,j*50+50,i*50,j*50+100,i*50+50,205, 127, 50,255);
        }
        i++;
        for(int j = 0; j < 8; j+=2){
            boxRGBA(renderer,j*50,i*50,j*50+50,i*50+50,205, 127, 50,255);
            boxRGBA(renderer,j*50+50,i*50,j*50+100,i*50+50,255,255,255,255);
        }
    }
}

void lehet_kirajzolas(SDL_Renderer *renderer, Babu **eleje, int db){
    for(int i = 0; i < db; i++){
        filledCircleRGBA(renderer,(*eleje)[i].x,(*eleje)[i].y,10,34,139,34,200);
    }
}

void babu_rajz(SDL_Renderer *renderer, SDL_Texture *pieces, Babu *babuk){
    for(int i = 0; i < 16; i++){
        if(babuk[i].x > 0 && babuk[i].y >0){
            if(babuk[i].f){
                switch(babuk[i].c){
                case 'p':
                    babu_rajzol(renderer, pieces, VGyalog, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'r':
                    babu_rajzol(renderer, pieces, VBastya, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'h':
                    babu_rajzol(renderer, pieces, VHuszar, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'b':
                    babu_rajzol(renderer, pieces, VFuto, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'q':
                    babu_rajzol(renderer, pieces, VVezer, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'k':
                    babu_rajzol(renderer, pieces, VKiraly, babuk[i].x-25, babuk[i].y-25);
                    break;
                }
            }
            else{
                switch(babuk[i].c){
                case 'p':
                    babu_rajzol(renderer, pieces, SGyalog, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'r':
                    babu_rajzol(renderer, pieces, SBastya, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'h':
                    babu_rajzol(renderer, pieces, SHuszar, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'b':
                    babu_rajzol(renderer, pieces, SFuto, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'q':
                    babu_rajzol(renderer, pieces, SVezer, babuk[i].x-25, babuk[i].y-25);
                    break;
                case 'k':
                    babu_rajzol(renderer, pieces, SKiraly, babuk[i].x-25, babuk[i].y-25);
                    break;
                }
            }
        }
    }
}
