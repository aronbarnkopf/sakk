#include "lepesek.h"

Babu *gyalog_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    if(elem->f==true){
            if(elem->y-50>0 && keres(fekete,elem->x, elem->y-50, 16)==NULL && keres(feher,elem->x, elem->y-50, 16)==NULL){
                Babu tmp = *elem;
                elem->y-=50;
                if(!sakk(true,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem = tmp;
            }
            if(elem->y==325 && keres(feher,elem->x, elem->y-100, 16)==NULL && keres(fekete,elem->x, elem->y-100, 16)==NULL && keres(fekete,elem->x, elem->y-50, 16)==NULL && keres(feher,elem->x, elem->y-50, 16)==NULL){
                Babu tmp = *elem;
                elem->y-=100;
                if(!sakk(true,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
            //--------------------------------átlós ütések
            if(elem->y-50>0 && elem->x-50>0 && keres(fekete,elem->x-50, elem->y-50, 16)!=NULL){
                Babu tmp = *elem;
                elem->y-=50;
                elem->x-=50;
                if(!sakk(true,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
            if(elem->y-50>0 && elem->x+50<400 && keres(fekete,elem->x+50, elem->y-50, 16)!=NULL){
                Babu tmp = *elem;
                elem->y-=50;
                elem->x+=50;
                if(!sakk(true,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
        }
        else{
            if(elem->y+50<400 && keres(fekete,elem->x, elem->y+50, 16)==NULL && keres(feher,elem->x, elem->y+50, 16)==NULL){
                Babu tmp = *elem;
                elem->y+=50;
                if(!sakk(false,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
            if(elem->y==75 && keres(feher,elem->x, elem->y+100, 16)==NULL && keres(fekete,elem->x, elem->y+100, 16)==NULL && keres(fekete,elem->x, elem->y+50, 16)==NULL && keres(feher,elem->x, elem->y+50, 16)==NULL){
                Babu tmp = *elem;
                elem->y+=100;
                if(!sakk(false,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
            if(elem->y+50<400 && elem->x-50>0 && keres(feher,elem->x-50, elem->y+50, 16)!=NULL){
                Babu tmp = *elem;
                elem->y+=50;
                elem->x-=50;
                if(!sakk(false,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
            if(elem->y+50<400 && elem->x+50<400 && keres(feher,elem->x+50, elem->y+50, 16)!=NULL){
                Babu tmp = *elem;
                elem->y+=50;
                elem->x+=50;
                if(!sakk(false,feher,fekete)){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                }
                *elem=tmp;
            }
        }
        return lehet;
}

Babu *lo_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    if(elem->f){

        if(elem->x-75 >= 0 && elem->y-125 >= 0 && NULL==keres(feher, elem->x-50,elem->y-100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x-50;
            lehet[(*db)-1].y=elem->y-100;
        }
        if(elem->x+75 <= 400 && elem->y-125 >= 0 && NULL==keres(feher, elem->x+50,elem->y-100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x+50;
            lehet[(*db)-1].y=elem->y-100;
        }
        if(elem->x+75 <= 400 && elem->y+125 <= 400 && NULL==keres(feher, elem->x+50,elem->y+100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x+50;
            lehet[(*db)-1].y=elem->y+100;
        }
        if(elem->x-75 >= 0 && elem->y+125 <= 400 && NULL==keres(feher, elem->x-50,elem->y+100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x-50;
            lehet[(*db)-1].y=elem->y+100;
        }

        if(elem->x-125 >= 0 && elem->y-75 >= 0 && NULL==keres(feher, elem->x-100,elem->y-50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x-100;
            lehet[(*db)-1].y=elem->y-50;
        }
        if(elem->x-125 >= 0 && elem->y+75 <= 400 && NULL==keres(feher, elem->x-100,elem->y+50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x-100;
            lehet[(*db)-1].y=elem->y+50;
        }
        if(elem->x+125 <= 400 && elem->y-75 >= 0 && NULL==keres(feher, elem->x+100,elem->y-50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x+100;
            lehet[(*db)-1].y=elem->y-50;
        }
        if(elem->x+125 <= 400 && elem->y+75 <= 400 && NULL==keres(feher, elem->x+100,elem->y+50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=true;
            lehet[(*db)-1].x=elem->x+100;
            lehet[(*db)-1].y=elem->y+50;
        }

        }//-----------------------------------------------------------------------------------------FEKETE LÓ
        else{
            if(elem->x-75 >= 0 && elem->y-125 >= 0 && NULL==keres(fekete, elem->x-50,elem->y-100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x-50;
            lehet[(*db)-1].y=elem->y-100;
        }
        if(elem->x+75 <= 400 && elem->y-125 >= 0 && NULL==keres(fekete, elem->x+50,elem->y-100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x+50;
            lehet[(*db)-1].y=elem->y-100;
        }
        if(elem->x+75 <= 400 && elem->y+125 <= 400 && NULL==keres(fekete, elem->x+50,elem->y+100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x+50;
            lehet[(*db)-1].y=elem->y+100;
        }
        if(elem->x-75 >= 0 && elem->y+125 <= 400 && NULL==keres(fekete, elem->x-50,elem->y+100, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x-50;
            lehet[(*db)-1].y=elem->y+100;
        }

        if(elem->x-125 >= 0 && elem->y-75 >= 0 && NULL==keres(fekete, elem->x-100,elem->y-50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x-100;
            lehet[(*db)-1].y=elem->y-50;
        }
        if(elem->x-125 >= 0 && elem->y+75 <= 400 && NULL==keres(fekete, elem->x-100,elem->y+50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x-100;
            lehet[(*db)-1].y=elem->y+50;
        }
        if(elem->x+125 <= 400 && elem->y-75 >= 0 && NULL==keres(fekete, elem->x+100,elem->y-50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x+100;
            lehet[(*db)-1].y=elem->y-50;
        }
        if(elem->x+125 <= 400 && elem->y+75 <= 400 && NULL==keres(fekete, elem->x+100,elem->y+50, 16)){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='h';
            lehet[(*db)-1].f=false;
            lehet[(*db)-1].x=elem->x+100;
            lehet[(*db)-1].y=elem->y+50;
        }
        }
        return lehet;
}

Babu *bastya_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    int x = ((elem->x)-50);
        while(x>0 && keres(feher,x,elem->y,16)==NULL && keres(fekete,x,elem->y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='r';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=elem->y;
            x-=50;
        }
        if(x>0){
            if(elem->f&&keres(feher,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            } else if(!(elem->f)&&keres(fekete,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }
        }

        x = elem->x+50;
        while(x<400 && keres(feher,x,elem->y,16)==NULL && keres(fekete,x,elem->y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='r';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=elem->y;
            x+=50;
        }
        if(x<400){
            if(elem->f&&keres(feher,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }else if(!(elem->f)&&keres(fekete,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }
        }

        int y = elem->y-50;
        while(y>0 && keres(feher,elem->x,y,16)==NULL && keres(fekete,elem->x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='r';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=elem->x;
            lehet[(*db)-1].y=y;
            y-=50;
        }
        if(y>0){
            if(elem->f&&keres(feher,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }
        }

        y = elem->y+50;
        while(y<400 && keres(feher,elem->x,y,16)==NULL && keres(fekete,elem->x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='r';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=elem->x;
            lehet[(*db)-1].y=y;
            y+=50;
        }
        if(y<400){
            if(elem->f&&keres(feher,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='r';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }
        }
        return lehet;
}

Babu *futo_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    int x = elem->x-50;
    int y = elem->y-50;
        while(y>0 && x>0 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='b';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x-=50;
            y-=50;
        }
        if(y>0&&x>0){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x+50;
        y = elem->y+50;
        while(y<400 && x<400 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='b';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x+=50;
            y+=50;
        }
        if(y<400&&x<400){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x+50;
        y = elem->y-50;
        while(y>0 && x<400 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='b';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x+=50;
            y-=50;
        }
        if(y>0&&x<400){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x-50;
        y = elem->y+50;
        while(y<400 && x>0 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='b';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x-=50;
            y+=50;
        }
        if(y<400&&x>0){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='b';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }
        return lehet;
}

Babu *kiralyno_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    int x = elem->x-50;
        while(x>0 && keres(feher,x,elem->y,16)==NULL && keres(fekete,x,elem->y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=elem->y;
            x-=50;
        }
        if(x>0){
            if(elem->f&&keres(feher,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            } else if(!(elem->f)&&keres(fekete,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }
        }

        x = elem->x+50;
        while(x<400 && keres(feher,x,elem->y,16)==NULL && keres(fekete,x,elem->y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=elem->y;
            x+=50;
        }
        if(x<400){
            if(elem->f&&keres(feher,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }else if(!(elem->f)&&keres(fekete,x,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=elem->y;
            }
        }

        int y = elem->y-50;
        while(y>0 && keres(feher,elem->x,y,16)==NULL && keres(fekete,elem->x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=elem->x;
            lehet[(*db)-1].y=y;
            y-=50;
        }
        if(y>0){
            if(elem->f&&keres(feher,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }
        }

        y = elem->y+50;
        while(y<400 && keres(feher,elem->x,y,16)==NULL && keres(fekete,elem->x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=elem->x;
            lehet[(*db)-1].y=y;
            y+=50;
        }
        if(y<400){
            if(elem->f&&keres(feher,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,elem->x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=elem->x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x-50;
        y = elem->y-50;
        while(y>0 && x>0 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x-=50;
            y-=50;
        }
        if(y>0&&x>0){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x+50;
        y = elem->y+50;
        while(y<400 && x<400 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x+=50;
            y+=50;
        }
        if(y<400&&x<400){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x+50;
        y = elem->y-50;
        while(y>0 && x<400 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x+=50;
            y-=50;
        }
        if(y>0&&x<400){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }

        x = elem->x-50;
        y = elem->y+50;
        while(y<400 && x>0 && keres(feher,x,y,16)==NULL && keres(fekete,x,y,16)==NULL){
            (*db)++;
            lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
            lehet[(*db)-1].c='q';
            lehet[(*db)-1].f=elem->f;
            lehet[(*db)-1].x=x;
            lehet[(*db)-1].y=y;
            x-=50;
            y+=50;
        }
        if(y<400&&x>0){
            if(elem->f && keres(feher,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }else if(!(elem->f)&&keres(fekete,x,y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet,(*db)*sizeof(Babu));
                lehet[(*db)-1].c='q';
                lehet[(*db)-1].f=elem->f;
                lehet[(*db)-1].x=x;
                lehet[(*db)-1].y=y;
            }
        }
    return lehet;
}

Babu *kiraly_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db){
    Babu *lehet = malloc(0);
    if(elem->f){
            if(elem->y-50>0&&keres(feher,elem->x,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
            }
            if(elem->x-50>0&&keres(feher,elem->x-50,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x-=50;
            }
            if(elem->y+50<400&&keres(feher,elem->x,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
            }
            if(elem->x+50<400&&keres(feher,elem->x+50,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y-50>0&&elem->x-50>0&&keres(feher,elem->x-50,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
                lehet[(*db)-1].x-=50;
            }
            if(elem->y-50>0&&elem->x+50<400&&keres(feher,elem->x+50,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y+50<400&&elem->x+50<400&&keres(feher,elem->x+50,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y+50<400&&elem->x-50>0&&keres(feher,elem->x-50,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
                lehet[(*db)-1].x-=50;
            }
            Babu* rook=keres(feher,375,375,16);
            if(!sakk(true,feher,fekete)&&elem->x==225&&elem->y==375&&keres(feher,275,375,16)==NULL&&keres(feher,325,375,16)==NULL&&keres(fekete,275,375,16)==NULL&&keres(fekete,325,375,16)==NULL&&rook!=NULL&&rook->c=='r'){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x+=100;
            }
            rook=keres(feher,25,375,16);
            if(!sakk(true,feher,fekete)&&elem->x==225&&elem->y==375&&keres(feher,175,375,16)==NULL&&keres(feher,125,375,16)==NULL&&keres(feher,75,375,16)==NULL&&keres(fekete,175,375,16)==NULL&&keres(fekete,125,375,16)==NULL&&keres(fekete,75,375,16)==NULL&&rook!=NULL&&rook->c=='r'){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x-=100;
            }

        }else{
            if(elem->y-50>0&&keres(fekete,elem->x,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
            }
            if(elem->x-50>0&&keres(fekete,elem->x-50,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x-=50;
            }
            if(elem->y+50<400&&keres(fekete,elem->x,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
            }
            if(elem->x+50<400&&keres(fekete,elem->x+50,elem->y,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y-50>0&&elem->x-50>0&&keres(fekete,elem->x-50,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
                lehet[(*db)-1].x-=50;
            }
            if(elem->y-50>0&&elem->x+50<400&&keres(fekete,elem->x+50,elem->y-50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y-=50;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y+50<400&&elem->x+50<400&&keres(fekete,elem->x+50,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
                lehet[(*db)-1].x+=50;
            }
            if(elem->y+50<400&&elem->x-50>0&&keres(fekete,elem->x-50,elem->y+50,16)==NULL){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].y+=50;
                lehet[(*db)-1].x-=50;
            }
            Babu* rook=keres(fekete,375,25,16);
            if(!sakk(false,feher,fekete)&&elem->x==225&&elem->y==25&&keres(fekete,275,25,16)==NULL&&keres(fekete,325,25,16)==NULL&&keres(feher,275,25,16)==NULL&&keres(feher,325,25,16)==NULL&&rook!=NULL&&rook->c=='r'){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x+=100;
            }
            rook=keres(fekete,25,25,16);
            if(!sakk(false,feher,fekete)&&elem->x==225&&elem->y==25&&keres(fekete,175,25,16)==NULL&&keres(fekete,125,25,16)==NULL&&keres(fekete,75,25,16)==NULL&&keres(feher,175,25,16)==NULL&&keres(feher,125,25,16)==NULL&&keres(feher,75,25,16)==NULL&&rook!=NULL&&rook->c=='r'){
                (*db)++;
                lehet = (Babu*)realloc(lehet, (*db)*sizeof(Babu));
                lehet[(*db)-1]=*elem;
                lehet[(*db)-1].x-=100;
            }
        }
        return lehet;
}


