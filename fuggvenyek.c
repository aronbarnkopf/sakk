#include <SDL.h>
#include <SDL_image.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fuggvenyek.h"
#include "lepesek.h"
#include "grafika.h"

void babuk_letrehozas(Babu *feher, Babu *fekete){
    char alapallas[]="rhbqkbhr";
    for(int i = 0; i < 8; i++){
        fekete[i].c=alapallas[i];
        fekete[i].f=false;
        fekete[i].x=25+50*i;
        fekete[i].y=25;
        //----------------parasztok
        fekete[i+8].c='p';
        fekete[i+8].f=false;
        fekete[i+8].x=25+50*i;
        fekete[i+8].y=75;
    }
    for(int i = 0; i < 8; i++){
        feher[i].c=alapallas[i];
        feher[i].f=true;
        feher[i].x=25+50*i;
        feher[i].y=375;
        //----------------parasztok
        feher[i+8].c='p';
        feher[i+8].f=true;
        feher[i+8].x=25+50*i;
        feher[i+8].y=325;
    }
}

void uj_lepes(Lepes **eleje, int x1, int y1, int x2, int y2, char pro){
    if(*eleje==NULL){
        (*eleje) = (Lepes*)malloc(sizeof(Lepes));
        (*eleje)->honnan1=x1;
        (*eleje)->honnan2=y1;
        (*eleje)->hova1=x2;
        (*eleje)->hova2=y2;
        (*eleje)->pro=pro;
        (*eleje)->kov=NULL;
    }else{
        Lepes *epp = (*eleje);
        while(epp->kov!=NULL)
            epp=epp->kov;

        epp->kov = (Lepes*)malloc(sizeof(Lepes));
        epp->kov->honnan1=x1;
        epp->kov->honnan2=y1;
        epp->kov->hova1=x2;
        epp->kov->hova2=y2;
        epp->kov->pro=pro;
        epp->kov->kov=NULL;
    }
}

void felszabadit(Lepes *eleje){
    while(eleje!=NULL){
        Lepes *kovetkezo = eleje->kov;
        free(eleje);
        eleje=kovetkezo;
    }
}

Babu *keres(Babu *eleje, int x, int y, int db){
    for(int i = 0; i < db; i++){
        if(abs(eleje[i].x-x)<20 && abs(eleje[i].y-y)<20){
            return &eleje[i];
        }
    }
    return NULL;
}


Babu* lehetsegeslepesek(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet;
    *db = 0;
    switch(elem->c){
    case 'p':
        lehet = gyalog_lepes(elem, feher, fekete, db);
        break;

    case 'h':
        lehet = lo_lepes(elem, feher, fekete, db);
        break;

    case 'r':
        lehet = bastya_lepes(elem, feher, fekete, db);
        break;

    case 'b':
        lehet = futo_lepes(elem, feher, fekete, db);
        break;

    case 'q':
        lehet = kiralyno_lepes(elem, feher, fekete, db);
        break;

    case 'k':
        lehet = kiraly_lepes(elem, feher, fekete, db);
        break;
    default:
        break;
    }
    return lehet;
}

bool sakk(bool vilagos, Babu *feher, Babu *fekete){
    int i = 0;
    int db;
    Babu *lehet;
    Babu *figura;
    if(vilagos){
        while(feher[i].c!='k')
            i++;
        figura = keres(fekete,feher[i].x-50,feher[i].y-50,16);
        if(figura!=NULL && figura->c=='p')
            return true;

        figura = keres(fekete,feher[i].x+50,feher[i].y-50,16);
        if(figura!=NULL && figura->c=='p')
            return true;

        db=0;
        lehet = lo_lepes(&feher[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(fekete,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && figura->c=='h')
                return true;
        }
        free(lehet);

        db=0;
        lehet = futo_lepes(&feher[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(fekete,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && (figura->c=='b' || figura->c=='q'))
                return true;
        }
        free(lehet);

        db=0;
        lehet = bastya_lepes(&feher[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(fekete,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && (figura->c=='r' || figura->c=='q'))
                return true;
        }
        free(lehet);
    }else{
        while(fekete[i].c!='k')
            i++;
        figura = keres(feher,fekete[i].x-50,fekete[i].y+50,16);
        if(figura!=NULL && figura->c=='p')
            return true;

        figura = keres(feher,fekete[i].x+50,fekete[i].y-50,16);
        if(figura!=NULL && figura->c=='p')
            return true;

        db=0;
        lehet = lo_lepes(&fekete[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(feher,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && figura->c=='h')
                return true;
        }
        free(lehet);

        db=0;
        lehet = futo_lepes(&fekete[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(feher,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && (figura->c=='b' || figura->c=='q'))
                return true;
        }
        free(lehet);

        db=0;
        lehet = bastya_lepes(&fekete[i],feher,fekete,&db);
        for(int j = 0; j < db; j++){
            figura = keres(feher,lehet[j].x,lehet[j].y,16);
            if(figura != NULL && (figura->c=='r' || figura->c=='q'))
                return true;
        }
        free(lehet);
    }
    return false;
}

bool utes(Babu *elem, Babu *feher, Babu *fekete){
    Babu *elem2;
    if(elem->f){
        elem2=keres(fekete,elem->x,elem->y,16);
        if(elem2!=NULL){
            elem2->x=-100;
            elem2->y=-100;
        }
    }else{
        elem2=keres(feher,elem->x,elem->y,16);
        if(elem2!=NULL){
            elem2->x=-100;
            elem2->y=-100;
        }
    }
    if(elem2!=NULL && elem2->c=='k')return true;
    return false;
}

void shortcastle(Babu *elem, Babu* feher, Babu* fekete){
    if(elem->f){
        Babu* elem2 = keres(feher,375,375,16);
        elem2->x=275;
    }else{
        Babu* elem2 = keres(fekete,375,25,16);
        elem2->x=275;
    }
}

void longcastle(Babu *elem, Babu *feher, Babu *fekete){
    if(elem->f){
        Babu* elem2 = keres(feher,25,375,16);
        elem2->x=175;
    }else{
        Babu* elem2 = keres(fekete,25,25,16);
        elem2->x=175;
    }
}

char promotion(SDL_Renderer *renderer, SDL_Texture *pieces, Babu* elem){
    babu_rajzol(renderer, pieces, VHuszar, 87, 425);
    babu_rajzol(renderer, pieces, VFuto, 87+75, 425);
    babu_rajzol(renderer, pieces, VBastya, 87+150, 425);
    babu_rajzol(renderer, pieces, VVezer, 87+225, 425);
    SDL_RenderPresent(renderer);
    SDL_Event event;
    bool nkatt = true;
    char c;
    while(nkatt){
        SDL_WaitEvent(&event);
        if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
            int klikkx = event.button.x;
            int klikky = event.button.y;
            if(klikkx>87 && klikkx<87+50 && klikky>425 && klikky < 475){
                elem->c='h';
                c = 'h';
                nkatt=false;
            }
            if(klikkx>87+50 && klikkx<87+100 && klikky>425 && klikky < 475){
                elem->c='b';
                c = 'b';
                nkatt=false;
            }
            if(klikkx>87+100 && klikkx<87+150 && klikky>425 && klikky < 475){
                elem->c='r';
                c='r';
                nkatt=false;
            }
            if(klikkx>87+150 && klikkx<87+200 && klikky>425 && klikky < 475){
                elem->c='q';
                c='q';
                nkatt=false;
            }
        }
    }
    boxRGBA(renderer,0,400,400,500,0,0,0,255);
    return c;
}

bool matt_e(bool kivansoron, Babu *feher, Babu *fekete){
    if(kivansoron){
        for(int i = 0; i < 16; i++){
            int db = 0;
            Babu tmp = feher[i];
            Babu *lehet = lehetsegeslepesek(&feher[i],feher,fekete,&db);
            for(int j = 0; j < db; j++){
                feher[i] = lehet[j];
                if(!sakk(true,feher,fekete)){
                    feher[i]=tmp;
                    free(lehet);
                    return false;
                }
            }
            free(lehet);
            feher[i]=tmp;
        }
    }else{
        for(int i = 0; i < 16; i++){
            int db = 0;
            Babu tmp = fekete[i];
            Babu *lehet = lehetsegeslepesek(&fekete[i],feher,fekete,&db);
            for(int j = 0; j < db; j++){
                fekete[i] = lehet[j];
                if(!sakk(false,feher,fekete)){
                    fekete[i]=tmp;
                    free(lehet);
                    return false;
                }
            }
            free(lehet);
            fekete[i]=tmp;
        }
    }
    return true;
}
