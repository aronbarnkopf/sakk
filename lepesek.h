#ifndef LEPESEK_H_INCLUDED
#define LEPESEK_H_INCLUDED
#include "fuggvenyek.h"

Babu *gyalog_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);
Babu *lo_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);
Babu *futo_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);
Babu *bastya_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);
Babu *kiralyno_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);
Babu *kiraly_lepes(Babu *elem, Babu *feher, Babu *fekete, int* db);

#endif // LEPESEK_H_INCLUDED
