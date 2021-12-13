#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<gtk/gtk.h>
typedef struct{
char id[30];
char jour[30];
char formule[30];
char entree[30];
char plat_principal [30];
char dessert[30];
}menu;

typedef struct
{
char jour[30];
int dejeuner;
int dinner;
}dechets;


void ajout_menu(menu );

void supprimer_menu(menu );


void modifier_menu(menu );

void afficher(GtkTreeView *list);





