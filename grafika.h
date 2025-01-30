#ifndef GRAFIKA_H_INCLUDED
#define GRAFIKA_H_INCLUDED
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
#include "fuggvenyek.h"
void babu_rajzol(SDL_Renderer *renderer, SDL_Texture *babuk, Piece melyik, int x, int y);
void sdl_init(char const *felirat, int szeles, int magas, SDL_Window **pwindow, SDL_Renderer **prenderer);
void tabla_rajz(SDL_Renderer *renderer);
void lehet_kirajzolas(SDL_Renderer *renderer, Babu **eleje, int db);
void babu_rajz(SDL_Renderer *renderer, SDL_Texture *pieces, Babu *babuk);

#endif // GRAFIKA_H_INCLUDED
