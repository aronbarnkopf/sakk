#include <SDL3.h>
#include <SDL_image.h>
#include <SDL3_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "debugmalloc.h"
#include "fuggvenyek.h"
#include "grafika.h"


int main(int argc, char *argv[]) {
    legeleje:
    printf("(1)uj jatek\n");
    printf("(2)visszanezes\n");
    printf("(3)folytatas\n");
    char a;
    scanf("%c", &a);
    switch(a){
    case '1':
        printf("Fajl neve:\n");
        char nev[50];
        scanf("%s", nev);

        SDL_Window *window;
        SDL_Renderer *renderer;
        sdl_init("Sakktabla", 400, 500, &window, &renderer);
        SDL_Texture *babuk = IMG_LoadTexture(renderer, "pieces.xcf");
        if (babuk == NULL) {
            SDL_Log("Nem nyithato meg a kepfajl: %s", IMG_GetError());
            exit(1);
        }
        tabla_rajz(renderer);
        Babu *feher = malloc(2*8*sizeof(Babu));
        Babu *fekete = malloc(2*8*sizeof(Babu));
        babuk_letrehozas(feher,fekete);
        babu_rajz(renderer,babuk,feher);
        babu_rajz(renderer,babuk,fekete);
        SDL_RenderPresent(renderer);

        SDL_Event ev;
        Lepes *lepesek = NULL;
        bool kivansoron = true; //ha feher - 1, ha fekete - 0
        Babu *elem;
        Babu *lehet = NULL;
        int db;
        bool vege = false;
        while (ev.type != SDL_QUIT && !vege) {
                SDL_WaitEvent(&ev);

                if(ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT) {
                        int klikkx = ev.button.x;
                        int klikky = ev.button.y;
                        if(lehet == NULL){
                            if(kivansoron){
                                elem = keres(feher,klikkx,klikky,16);
                            }else{
                                elem = keres(fekete,klikkx,klikky,16);
                            }
                            if(elem != NULL){
                                lehet = lehetsegeslepesek(elem, feher, fekete, &db);
                            }
                        }//------------------------------------------------------MÁSODIK KLIKK
                        else{
                            Babu *elem2;
                            elem2 = keres(lehet,klikkx,klikky, db);
                            lehet=NULL;
                            db=0;
                            if(elem2 != NULL){
                                if(elem->c=='k'&&abs(elem->x-elem2->x)>50){
                                    if(elem->x-elem2->x<0){
                                        shortcastle(elem,feher,fekete);
                                    }else{
                                        longcastle(elem,feher,fekete);
                                    }
                                }
                                Babu tmp = *elem;
                                *elem  = *elem2;
                                if(sakk(elem->f,feher,fekete)){
                                    *elem = tmp;
                                }
                                else{
                                    char proc = ' ';
                                    if(elem->c=='p'&&(elem->y==25||elem->y==375)){
                                        proc = promotion(renderer,babuk,elem);
                                    }
                                    uj_lepes(&lepesek,tmp.x,tmp.y,elem2->x,elem2->y,proc);
                                    vege = utes(elem2,feher,fekete);
                                    kivansoron = !kivansoron;
                                }
                            }
                        }

                        tabla_rajz(renderer);
                        babu_rajz(renderer,babuk,feher);
                        babu_rajz(renderer,babuk,fekete);
                        if(lehet != NULL){
                            lehet_kirajzolas(renderer,&lehet,db);
                        }
                        SDL_RenderPresent(renderer);
                        if(matt_e(kivansoron,feher,fekete)){
                            vege=true;
                        }
                }
        }
        bool matt = sakk(kivansoron,feher,fekete);
        FILE *fp;
        fp = fopen(nev, "w");
        if (fp == NULL) {
            perror("Fájl megnyitása sikertelen");
            return 1;
        }

        while(lepesek!=NULL){
            int a = lepesek->honnan1;
            int b = lepesek->honnan2;
            int c = lepesek->hova1;
            int d = lepesek->hova2;
            char p = lepesek->pro;
            fprintf(fp,"%d %d | %d %d%c\n",a,b,c,d,p);
            Lepes *epp=lepesek->kov;
            lepesek=epp;
        }
        fclose(fp);

        //felszabadit(lepesek);
        free(feher);
        free(fekete);

        if(vege)stringRGBA(renderer, 185, 440, "Vege", 255, 255, 255, 255);
        if(matt && vege){
            if(kivansoron && vege){
                stringRGBA(renderer, 150, 460, "Gyoztes: fekete", 255, 255, 255, 255);
            }else if(vege){
                stringRGBA(renderer, 150, 460, "Gyoztes: feher", 255, 255, 255, 255);
            }
        }else if(vege){
            stringRGBA(renderer, 190, 460, "Patt", 255, 255, 255, 255);
        }

        SDL_RenderPresent(renderer);
        while (vege && SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
        }
        SDL_Quit();
        break;
    case '2':
        printf("Fajl neve:\n");
        scanf("%s", nev);
        fp = fopen(nev, "r");
        if (fp == NULL) {
            printf("Fajl megnyitasa sikertelen\n");
            getchar();
            goto legeleje;
        }
        sdl_init("Sakktabla", 400, 500, &window, &renderer);
        babuk = IMG_LoadTexture(renderer, "pieces.xcf");
        if (babuk == NULL) {
            SDL_Log("Nem nyithato meg a kepfajl: %s", IMG_GetError());
            exit(1);
        }
        tabla_rajz(renderer);
        feher = malloc(2*8*sizeof(Babu));
        fekete = malloc(2*8*sizeof(Babu));
        babuk_letrehozas(feher,fekete);
        babu_rajz(renderer,babuk,feher);
        babu_rajz(renderer,babuk,fekete);
        SDL_RenderPresent(renderer);


        kivansoron = true;
        vege = false;
        int x1,y1,x2,y2;
        char p;
        while (ev.type != SDL_QUIT && !vege){
            SDL_WaitEvent(&ev);
            if(ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT){
            char str[30];
            char* siker = fgets (str, 25, fp);
            int sdb = sscanf(str,"%d %d | %d %d%c",&x1,&y1,&x2,&y2,&p);
            if(sdb!= 5 || siker==NULL){
                vege = true;
            }
            else{
            if(kivansoron){
                elem=keres(feher,x1,y1,16);
            }else{
                elem=keres(fekete,x1,y1,16);
            }

            if(elem!=NULL){
            elem->x=x2;
            elem->y=y2;
            if(elem->c=='k'&&abs(x1-x2)>50){
                if(x1-x2<0){
                    shortcastle(elem,feher,fekete);
                }else{
                    longcastle(elem,feher,fekete);
                }
            }
            if(elem->c=='p'&&(y2==25||y2==375)){
                elem->c=p;
            }}
            utes(elem,feher,fekete);
            kivansoron = !kivansoron;
            tabla_rajz(renderer);
            babu_rajz(renderer,babuk,feher);
            babu_rajz(renderer,babuk,fekete);
            SDL_RenderPresent(renderer);
            }
            }
        }

        fclose(fp);
        free(feher);
        free(fekete);
        SDL_Quit();
        break;
    case '3':
        printf("Fajl neve:\n");
        scanf("%s", nev);
        fp = fopen(nev, "r");
        if (fp == NULL) {
            printf("Fajl megnyitasa sikertelen\n");
            getchar();
            goto legeleje;
        }

        feher = malloc(2*8*sizeof(Babu));
        fekete = malloc(2*8*sizeof(Babu));
        babuk_letrehozas(feher,fekete);
        lepesek = NULL;
        kivansoron=true;
        char str[30];
        char *siker = fgets (str, 25, fp);
        int sdb = sscanf(str,"%d %d | %d %d%c",&x1,&y1,&x2,&y2,&p);
        while(sdb == 5 && siker !=NULL){
            uj_lepes(&lepesek,x1,y1,x2,y2,p);
            if(kivansoron){
                elem=keres(feher,x1,y1,16);
            }else{
                elem=keres(fekete,x1,y1,16);
            }
            if(elem!=NULL){
            elem->x=x2;
            elem->y=y2;
            if(elem->c=='k'&&abs(x1-x2)>50){
                if(x1-x2<0){
                    shortcastle(elem,feher,fekete);
                }else{
                    longcastle(elem,feher,fekete);
                }
            }
            if(elem->c=='p'&&(y2==25||y2==375)){
                elem->c=p;
            }
            utes(elem,feher,fekete);
            }
            kivansoron = !kivansoron;
            siker = fgets (str, 25, fp);
            sdb = sscanf(str,"%d %d | %d %d%c",&x1,&y1,&x2,&y2,&p);
        }
        fclose(fp);


        sdl_init("Sakktabla", 400, 500, &window, &renderer);
        babuk = IMG_LoadTexture(renderer, "pieces.xcf");
        if (babuk == NULL) {
            SDL_Log("Nem nyithato meg a kepfajl: %s", IMG_GetError());
            exit(1);
        }
        tabla_rajz(renderer);
        babu_rajz(renderer,babuk,feher);
        babu_rajz(renderer,babuk,fekete);
        SDL_RenderPresent(renderer);

        lehet = NULL;
        vege = false;
        while (ev.type != SDL_QUIT && !vege) {
                SDL_WaitEvent(&ev);

                if(ev.type == SDL_MOUSEBUTTONDOWN && ev.button.button == SDL_BUTTON_LEFT) {
                        int klikkx = ev.button.x;
                        int klikky = ev.button.y;
                        if(lehet == NULL){
                            if(kivansoron){
                                elem = keres(feher,klikkx,klikky,16);
                            }else{
                                elem = keres(fekete,klikkx,klikky,16);
                            }
                            if(elem != NULL){
                                lehet = lehetsegeslepesek(elem, feher, fekete, &db);
                            }
                        }//------------------------------------------------------MÁSODIK KLIKK
                        else{
                            Babu *elem2;
                            elem2 = keres(lehet,klikkx,klikky, db);
                            lehet=NULL;
                            db=0;
                            if(elem2 != NULL){
                                if(elem->c=='k'&&abs(elem->x-elem2->x)>50){
                                    if(elem->x-elem2->x<0){
                                        shortcastle(elem,feher,fekete);
                                    }else{
                                        longcastle(elem,feher,fekete);
                                    }
                                }
                                Babu tmp = *elem;
                                *elem  = *elem2;
                                if(sakk(elem->f,feher,fekete)/*nem mukszik*/){
                                    *elem = tmp;
                                }
                                else{
                                    char proc = ' ';
                                    if(elem->c=='p'&&(elem->y==25||elem->y==375)){
                                        proc = promotion(renderer,babuk,elem);
                                    }
                                    uj_lepes(&lepesek,tmp.x,tmp.y,elem2->x,elem2->y,proc);
                                    vege = utes(elem2,feher,fekete);
                                    kivansoron = !kivansoron;
                                }
                            }
                        }

                        tabla_rajz(renderer);
                        babu_rajz(renderer,babuk,feher);
                        babu_rajz(renderer,babuk,fekete);
                        if(lehet != NULL){
                            lehet_kirajzolas(renderer,&lehet,db);
                        }
                        SDL_RenderPresent(renderer);
                        if(matt_e(kivansoron,feher,fekete)){
                            vege=true;
                        }
                }
        }
        matt = sakk(kivansoron,feher,fekete);
        fp = fopen(nev, "w");
        if (fp == NULL) {
            perror("Fájl megnyitása sikertelen");
            return 1;
        }

        while(lepesek!=NULL){
            int a = lepesek->honnan1;
            int b = lepesek->honnan2;
            int c = lepesek->hova1;
            int d = lepesek->hova2;
            int p = lepesek->pro;
            fprintf(fp,"%d %d | %d %d%c\n",a,b,c,d,p);
            Lepes *epp=lepesek->kov;
            lepesek=epp;
        }
        fclose(fp);
        free(feher);
        free(fekete);
        if(vege)stringRGBA(renderer, 185, 440, "Vege", 255, 255, 255, 255);
        if(matt && vege){
            if(kivansoron && vege){
                stringRGBA(renderer, 150, 460, "Gyoztes: fekete", 255, 255, 255, 255);
            }else if(vege){
                stringRGBA(renderer, 150, 460, "Gyoztes: feher", 255, 255, 255, 255);
            }
        }else if(vege){
            stringRGBA(renderer, 190, 460, "Patt", 255, 255, 255, 255);
        }

        SDL_RenderPresent(renderer);
        while (vege && SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {
        }

        SDL_Quit();
        break;
    default:
        printf("Hibas bemenet\n");
        goto legeleje;
        break;
    }

    return 0;
}
