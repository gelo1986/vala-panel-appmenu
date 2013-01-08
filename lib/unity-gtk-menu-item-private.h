/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authors: Ryan Lortie <desrt@desrt.ca>
 *          William Hua <william.hua@canonical.com>
 */

#ifndef __UNITY_GTK_MENU_ITEM_PRIVATE_H__
#define __UNITY_GTK_MENU_ITEM_PRIVATE_H__

typedef struct _UnityGtkMenuItem      UnityGtkMenuItem;
typedef struct _UnityGtkMenuItemClass UnityGtkMenuItemClass;

#define UNITY_GTK_TYPE_MENU_ITEM            (unity_gtk_menu_item_get_type ())
#define UNITY_GTK_MENU_ITEM(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_GTK_TYPE_MENU_ITEM, UnityGtkMenuItem))
#define UNITY_GTK_IS_MENU_ITEM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_GTK_TYPE_MENU_ITEM))
#define UNITY_GTK_MENU_ITEM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_GTK_TYPE_MENU_ITEM, UnityGtkMenuItemClass))
#define UNITY_GTK_IS_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_GTK_TYPE_MENU_ITEM))
#define UNITY_GTK_MENU_ITEM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_GTK_TYPE_MENU_ITEM, UnityGtkMenuItemClass))

#include <gtk/gtk.h>
#include "unity-gtk-menu-shell-private.h"
#include "unity-gtk-action-private.h"

struct _UnityGtkMenuItem
{
  GObject parent_instance;

  /*< private >*/
  GtkMenuItem       *menu_item;
  gulong             menu_item_notify_handler_id;
  UnityGtkMenuShell *parent_shell;
  UnityGtkMenuShell *child_shell;
  guchar             child_shell_valid : 1;
  guint              item_index;
  UnityGtkAction    *action;
};

struct _UnityGtkMenuItemClass
{
  GObjectClass parent_class;
};

GType               unity_gtk_menu_item_get_type          (void)                            G_GNUC_INTERNAL;

UnityGtkMenuItem *  unity_gtk_menu_item_new               (GtkMenuItem       *menu_item,
                                                           UnityGtkMenuShell *parent_shell,
                                                           guint              item_index)   G_GNUC_INTERNAL;

UnityGtkMenuShell * unity_gtk_menu_item_get_child_shell   (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

void                unity_gtk_menu_item_set_action        (UnityGtkMenuItem  *item,
                                                           UnityGtkAction    *action)       G_GNUC_INTERNAL;

const gchar *       unity_gtk_menu_item_get_label         (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_visible        (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_sensitive      (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_active         (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_separator      (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_check          (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_is_radio          (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

gboolean            unity_gtk_menu_item_get_draw_as_radio (UnityGtkMenuItem  *item)         G_GNUC_INTERNAL;

void                unity_gtk_menu_item_print             (UnityGtkMenuItem  *item,
                                                           guint              indent)       G_GNUC_INTERNAL;

#endif /* __UNITY_GTK_MENU_ITEM_PRIVATE_H__ */