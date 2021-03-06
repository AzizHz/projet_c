/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *menu;
  GtkWidget *gestion_de_menu;
  GtkWidget *ajouter;
  GtkWidget *modifier;
  GtkWidget *supprimer;
  GtkWidget *meilleur;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  menu = create_menu ();
  gtk_widget_show (menu);

/*
  gestion_de_menu = create_gestion_de_menu ();
  gtk_widget_show (gestion_de_menu);
  ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
  modifier = create_modifier ();
  gtk_widget_show (modifier);
  supprimer = create_supprimer ();
  gtk_widget_show (supprimer);
  meilleur = create_meilleur ();
  gtk_widget_show (meilleur); */

  gtk_main ();
  return 0;
}

