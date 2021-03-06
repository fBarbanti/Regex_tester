/* Application.c generated by valac 0.40.25, the Vala compiler
 * generated from Application.vala, do not modify */

/*
* Copyright (c) 2021 Francesco Barbanti
*
* Regex Tester is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* Regex Tester is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with Regex Tester. If not, see <https://www.gnu.org/licenses/>.
*
* Authored by: Francesco Barbanti <francesco.barbanti.97@gmail.com>
*/


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <gdk/gdk.h>


#define TYPE_APPLICATION (application_get_type ())
#define APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), TYPE_APPLICATION, Application))
#define APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), TYPE_APPLICATION, ApplicationClass))
#define IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), TYPE_APPLICATION))
#define IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), TYPE_APPLICATION))
#define APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), TYPE_APPLICATION, ApplicationClass))

typedef struct _Application Application;
typedef struct _ApplicationClass ApplicationClass;
typedef struct _ApplicationPrivate ApplicationPrivate;
enum  {
	APPLICATION_0_PROPERTY,
	APPLICATION_NUM_PROPERTIES
};
static GParamSpec* application_properties[APPLICATION_NUM_PROPERTIES];

#define REGEX_TESTER_TYPE_WINDOW (regex_tester_window_get_type ())
#define REGEX_TESTER_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), REGEX_TESTER_TYPE_WINDOW, Regex_testerWindow))
#define REGEX_TESTER_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), REGEX_TESTER_TYPE_WINDOW, Regex_testerWindowClass))
#define REGEX_TESTER_IS_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), REGEX_TESTER_TYPE_WINDOW))
#define REGEX_TESTER_IS_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), REGEX_TESTER_TYPE_WINDOW))
#define REGEX_TESTER_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), REGEX_TESTER_TYPE_WINDOW, Regex_testerWindowClass))

typedef struct _Regex_testerWindow Regex_testerWindow;
typedef struct _Regex_testerWindowClass Regex_testerWindowClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _Application {
	GtkApplication parent_instance;
	ApplicationPrivate * priv;
};

struct _ApplicationClass {
	GtkApplicationClass parent_class;
};


static gpointer application_parent_class = NULL;

GType application_get_type (void) G_GNUC_CONST;
Application* application_new (void);
Application* application_construct (GType object_type);
static void application_real_activate (GApplication* base);
GType regex_tester_window_get_type (void) G_GNUC_CONST;
Regex_testerWindow* regex_tester_window_new (GtkApplication* app);
Regex_testerWindow* regex_tester_window_construct (GType object_type,
                                                   GtkApplication* app);


Application*
application_construct (GType object_type)
{
	Application * self = NULL;
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	self = (Application*) g_object_new (object_type, "application-id", "com.github.fBarbanti.Regex_tester", "flags", G_APPLICATION_FLAGS_NONE, NULL);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	return self;
#line 87 "Application.c"
}


Application*
application_new (void)
{
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	return application_construct (TYPE_APPLICATION);
#line 96 "Application.c"
}


static void
application_real_activate (GApplication* base)
{
	Application * self;
	GtkCssProvider* css_provider = NULL;
	GtkCssProvider* _tmp0_;
	GdkScreen* _tmp1_;
	Regex_testerWindow* window = NULL;
	Regex_testerWindow* _tmp2_;
#line 26 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	self = (Application*) base;
#line 28 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	_tmp0_ = gtk_css_provider_new ();
#line 28 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	css_provider = _tmp0_;
#line 29 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	gtk_css_provider_load_from_resource (css_provider, "/com/github/fBarbanti/Regex_tester/styles/style.css");
#line 30 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	_tmp1_ = gdk_screen_get_default ();
#line 30 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	gtk_style_context_add_provider_for_screen (_tmp1_, (GtkStyleProvider*) css_provider, (guint) GTK_STYLE_PROVIDER_PRIORITY_USER);
#line 32 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	_tmp2_ = regex_tester_window_new ((GtkApplication*) self);
#line 32 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	g_object_ref_sink (_tmp2_);
#line 32 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	window = _tmp2_;
#line 34 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) window);
#line 26 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	_g_object_unref0 (window);
#line 26 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	_g_object_unref0 (css_provider);
#line 133 "Application.c"
}


static void
application_class_init (ApplicationClass * klass)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	application_parent_class = g_type_class_peek_parent (klass);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Application.vala"
	((GApplicationClass *) klass)->activate = (void (*) (GApplication*)) application_real_activate;
#line 144 "Application.c"
}


static void
application_instance_init (Application * self)
{
}


GType
application_get_type (void)
{
	static volatile gsize application_type_id__volatile = 0;
	if (g_once_init_enter (&application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (ApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Application), 0, (GInstanceInitFunc) application_instance_init, NULL };
		GType application_type_id;
		application_type_id = g_type_register_static (gtk_application_get_type (), "Application", &g_define_type_info, 0);
		g_once_init_leave (&application_type_id__volatile, application_type_id);
	}
	return application_type_id__volatile;
}



