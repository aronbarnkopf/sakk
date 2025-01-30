#ifndef FUGGVENYEK_H_INCLUDED
#define FUGGVENYEK_H_INCLUDED
#include <SDL.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Babu{
    int x;
    int y;
    char c;
    bool f;
}Babu;
typedef enum Piece {
    SKiraly, SVezer, SBastya, SFuto, SHuszar, SGyalog,VKiraly, VVezer, VBastya, VFuto, VHuszar, VGyalog

} Piece;
enum { MERET = 50 };
typedef struct Lepes{
    int honnan1;
    int honnan2;
    int hova1;
    int hova2;
    char pro;
    struct Lepes *kov;
}Lepes;
void uj_lepes(Lepes **eleje, int x1, int y1, int x2, int y2, char pro);
void felszabadit(Lepes *eleje);
void babuk_letrehozas(Babu *feher, Babu *fekete);
Babu *keres(Babu *eleje, int x, int y, int db);
Babu* lehetsegeslepesek(Babu *elem, Babu *feher, Babu *fekete, int* db);
bool utes(Babu *elem, Babu *feher, Babu *fekete);
void shortcastle(Babu *elem, Babu* feher, Babu* fekete);
void longcastle(Babu *elem, Babu *feher, Babu *fekete);
char promotion(SDL_Renderer *renderer, SDL_Texture *pieces, Babu* elem);
bool sakk(bool vilagos, Babu *feher, Babu *fekete);
void babu_rajz(SDL_Renderer *renderer, SDL_Texture *pieces, Babu *babuk);
void babu_rajzol(SDL_Renderer *renderer, SDL_Texture *babuk, Piece melyik, int x, int y);

bool matt_e(bool kivansoron, Babu *feher, Babu *fekete);

#endif // FUGGVENYEK_H_INCLUDED
