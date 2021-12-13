#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"


#include "menuu.h"

int x;
void
on_button1_gestion_de_menu_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu;
GtkWidget *gestion_de_menu;
GtkTreeView *treeview1;

menu=lookup_widget(objet,"menu");

gtk_widget_destroy(menu);

gestion_de_menu=lookup_widget(objet,"gestion_de_menu");

gestion_de_menu=create_gestion_de_menu();
gtk_widget_show(gestion_de_menu);

treeview1=lookup_widget(gestion_de_menu,"treeview1");

afficher(treeview1);
}
void
on_button2_meilleur_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *meilleur;

meilleur=create_meilleur();
gtk_widget_show(meilleur);

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_button3_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
ajouter=create_ajouter();
gtk_widget_show(ajouter);


}
void
on_button4_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_de_menu,*modifier;
GtkWidget *combo;
	FILE *f;
	char id[30];
gestion_de_menu=lookup_widget(objet,"gestion_de_menu");
gtk_widget_destroy(gestion_de_menu );
modifier=create_modifier();
combo=lookup_widget(modifier,"combo_modifier");
	f=fopen("menu.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*s %*s\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(modifier);

}


void
on_button5_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *gestion_de_menu,*supprimer;
GtkWidget *combo;
	FILE *f;
	char id[30];
gestion_de_menu=lookup_widget(objet,"gestion_de_menu");
gtk_widget_destroy(gestion_de_menu );
supprimer=create_supprimer();
combo=lookup_widget(supprimer,"combo_supprimer");
	f=fopen("menu.txt","r");
	while(fscanf(f,"%s %*s %*s %*s %*s %*s\n",id)!=EOF)
	{
		gtk_combo_box_append_text(GTK_COMBO_BOX(combo),id);
	}
	fclose(f);
gtk_widget_show(supprimer);
}

void
on_button7_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu;

menu=create_menu();
gtk_widget_show(menu);
}
////////////////////////////////////////////////////////////////////////////////////////////////

void
on_button8_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu ml;


GtkWidget *id, *jour,*entree,*plat_principal,*dessert,*output;
GtkWidget *ajouter;

ajouter=lookup_widget(objet,"ajouter");

output=lookup_widget(objet,"label_ajout");

id=lookup_widget(objet,"entry1_id");


jour=lookup_widget(objet,"combobox1");


entree=lookup_widget(objet,"entry4_entree");
plat_principal=lookup_widget(objet,"entry5_plat");
dessert=lookup_widget(objet,"entry6_dessert");

strcpy(ml.id,gtk_entry_get_text(GTK_ENTRY(id)));

strcpy(ml.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
printf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));





if(x==1) strcpy(ml.formule,"midi");
else if(x==2) strcpy(ml.formule,"soir");

strcpy(ml.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(ml.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
strcpy(ml.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));

ajout_menu(ml);
gtk_label_set_text(GTK_LABEL(output)," Ajout effectué avec succès ! ");

}


void
on_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouter;
GtkWidget *gestion_de_menu;
GtkTreeView *treeview1;

ajouter=lookup_widget(objet,"ajouter");

gtk_widget_destroy(ajouter);

gestion_de_menu=lookup_widget(objet,"gestion_de_menu");

gestion_de_menu=create_gestion_de_menu();
gtk_widget_show(gestion_de_menu);

treeview1=lookup_widget(gestion_de_menu,"treeview1");

afficher(treeview1);

}



void
on_button12_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu ml;
GtkWidget *input,*output;
input= lookup_widget(objet,"combo_supprimer");
output=lookup_widget(objet,"label_sup");
strcpy(ml.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));
supprimer_menu(ml);
gtk_label_set_text(GTK_LABEL(output)," Suppression réussie ! ");
}


void
on_button13_afficher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimer;
GtkWidget *gestion_de_menu;
GtkTreeView *treeview1;

supprimer=lookup_widget(objet,"supprimer");

gtk_widget_destroy(supprimer);

gestion_de_menu=lookup_widget(objet,"gestion_de_menu");

gestion_de_menu=create_gestion_de_menu();
gtk_widget_show(gestion_de_menu);

treeview1=lookup_widget(gestion_de_menu,"treeview1");

afficher(treeview1);
}


void
on_button10_modifier_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
menu ml;


GtkWidget *id,*jour,*entree,*plat_principal,*dessert,*output;
GtkWidget *modifier;

output=lookup_widget(objet,"label_mod");

id=lookup_widget(objet,"combo_modifier");

jour=lookup_widget(objet,"combobox3");

entree=lookup_widget(objet,"entry4");
plat_principal=lookup_widget(objet,"entry5");
dessert=lookup_widget(objet,"entry6");


strcpy(ml.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));

strcpy(ml.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));
printf(gtk_combo_box_get_active_text(GTK_COMBO_BOX(jour)));


if(x==1) strcpy(ml.formule,"midi");
else if(x==2) strcpy(ml.formule,"soir");

strcpy(ml.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(ml.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
strcpy(ml.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));

modifier_menu(ml);
gtk_label_set_text(GTK_LABEL(output)," Modification effectuée avec succès ! ");



}


void
on_button11_afficher_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *modifier;
GtkWidget *gestion_de_menu;
GtkTreeView *treeview1;

modifier=lookup_widget(objet,"modifier");

gtk_widget_destroy(modifier);

gestion_de_menu=lookup_widget(objet,"gestion_de_menu");

gestion_de_menu=create_gestion_de_menu();
gtk_widget_show(gestion_de_menu);

treeview1=lookup_widget(gestion_de_menu,"treeview1");

afficher(treeview1);
}


void
on_comboboxentry2_move_active          (GtkComboBox     *combobox,
                                        GtkScrollType    arg1,
                                        gpointer         user_data)
{

}


void
on_radiobutton_midi_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=1;}
}


void
on_radiobutton_soir_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;}
}


void
on_button_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *label_meilleur;
label_meilleur = lookup_widget(button, "label_meilleur") ;


FILE* f;
dechets d;
char ch[20];
char message[70];
int min=900;
char jour[30];



f=fopen("dechets.txt","r+");
if(f!=NULL)
{
while (fscanf(f,"%s %d %d\n",d.jour,&d.dejeuner,&d.dinner)!=EOF)
{
if (min >= d.dejeuner )
{
min = d.dejeuner;
strcpy(ch,"dejeuner");
strcpy(jour,d.jour);
}

if (min >= d.dinner)
{
min = d.dinner ;
strcpy(ch,"Dinner");
strcpy(jour,d.jour);
}

}
fclose(f);
sprintf(message,"Le meilleur menu est le : %s de %s",ch,jour);
gtk_label_set_text(GTK_LABEL(label_meilleur),message);
}
}




void
on_button_retour_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *menu;

menu=create_menu();
gtk_widget_show(menu);
}


