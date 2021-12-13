#ifdef HAVE_CONGIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuu.h"
#include <gtk/gtk.h>

enum
{

eid,
ejour,
eformule,
eentree,
eplat_principal, 
edessert, 

COLUMNS,

};
///////////////////////////////////////////////////////
void ajout_menu(menu ml)
{
FILE* f;
f=fopen("menu.txt","a+");
  if(f!=NULL)
   {
   fprintf(f,"%s %s %s %s %s %s   \n", ml.id, ml.jour, ml.formule, ml.entree, ml.plat_principal, ml.dessert);
   }
fclose(f);
}

///////////////////////////////////////////////////////

void afficher(GtkTreeView *list)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
{
char id[30];
char jour[30];
char formule[30];
char entree[30];
char plat_principal [30];
char dessert[30];


store=NULL;

FILE  *f;

store=gtk_tree_view_get_model(list);

  if(store==NULL)
  {

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",eid,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
   

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",ejour,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
	
 

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("formule",renderer,"text",eformule,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);
   
   
   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("entree",renderer,"text",eentree,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);

   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes("plat_principal",renderer,"text",eplat_principal,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column);


   renderer=gtk_cell_renderer_text_new();
   column=gtk_tree_view_column_new_with_attributes(" dessert",renderer,"text", edessert,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(list),column); 

}
   store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

   f=fopen("menu.txt","r");

     if(f==NULL) { return;}
else
{
         f=fopen("menu.txt","a+");
         while(fscanf(f," %s %s %s %s %s %s  ",id,jour, formule, entree, plat_principal, dessert )!=EOF)
          {
         gtk_list_store_append(store,&iter);
         gtk_list_store_set(store,&iter,eid,id,ejour,jour,eformule,formule,eentree,entree,eplat_principal,plat_principal, edessert,dessert,-1);
          }
        
   fclose(f);

   gtk_tree_view_set_model(GTK_TREE_VIEW(list),GTK_TREE_MODEL(store));
   g_object_unref(store);  

   }
}}

///////////////////////////////////////////////////////

void supprimer_menu(menu ml)
{


menu m;	
FILE *f;
FILE *g;

f=fopen("menu.txt","a+");
g=fopen("menu2.txt","a+");
if (f!=NULL )
{
while (fscanf(f,"%s %s %s %s %s %s   \n", m.id, m.jour, m.formule, m.entree, m.plat_principal, m.dessert)!=EOF)
{if (strcmp(m.id,ml.id)!=0)	
    { fprintf(g,"%s %s %s %s %s %s    \n", m.id, m.jour, m.formule, m.entree, m.plat_principal, m.dessert); }
}

	fclose(f);
	fclose(g);
	remove("menu.txt");
	rename("menu2.txt","menu.txt");

   }
}

///////////////////////////////////////////////////////
void modifier_menu(menu ml)
{
menu m;
FILE *f;
FILE *g;

f=fopen("menu.txt","a+");
g=fopen("menu2.txt","a+");
if(f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s   \n", m.id, m.jour, m.formule, m.entree, m.plat_principal, m.dessert)!=EOF)
{ if (strcmp(m.id,ml.id)==0)
	fprintf(g,"%s %s %s %s %s %s   \n", ml.id, ml.jour, ml.formule, ml.entree, ml.plat_principal, ml.dessert);
else
	fprintf(g,"%s %s %s %s %s %s   \n", m.id, m.jour, m.formule, m.entree, m.plat_principal, m.dessert);
}
fclose(f);
fclose(g);
remove("menu.txt");
rename("menu2.txt","menu.txt");

}}
///////////////////////////////////////////////////////

