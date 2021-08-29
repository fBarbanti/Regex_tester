/* MatchItem.c generated by valac 0.40.25, the Vala compiler
 * generated from MatchItem.vala, do not modify */

/*
* Copyright (c) 2021 Francesco Barbanti
*
* Akira is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* Akira is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with Akira. If not, see <https://www.gnu.org/licenses/>.
*
* Authored by: Francesco Barbanti <francesco.barbanti.97@gmail.com>
*/


#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gobject/gvaluecollector.h>


#define REGEX_TESTER_TYPE_MATCH_ITEM (regex_tester_match_item_get_type ())
#define REGEX_TESTER_MATCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), REGEX_TESTER_TYPE_MATCH_ITEM, Regex_testerMatchItem))
#define REGEX_TESTER_MATCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), REGEX_TESTER_TYPE_MATCH_ITEM, Regex_testerMatchItemClass))
#define REGEX_TESTER_IS_MATCH_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), REGEX_TESTER_TYPE_MATCH_ITEM))
#define REGEX_TESTER_IS_MATCH_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), REGEX_TESTER_TYPE_MATCH_ITEM))
#define REGEX_TESTER_MATCH_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), REGEX_TESTER_TYPE_MATCH_ITEM, Regex_testerMatchItemClass))

typedef struct _Regex_testerMatchItem Regex_testerMatchItem;
typedef struct _Regex_testerMatchItemClass Regex_testerMatchItemClass;
typedef struct _Regex_testerMatchItemPrivate Regex_testerMatchItemPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Regex_testerParamSpecMatchItem Regex_testerParamSpecMatchItem;

struct _Regex_testerMatchItem {
	GTypeInstance parent_instance;
	volatile int ref_count;
	Regex_testerMatchItemPrivate * priv;
};

struct _Regex_testerMatchItemClass {
	GTypeClass parent_class;
	void (*finalize) (Regex_testerMatchItem *self);
};

struct _Regex_testerMatchItemPrivate {
	gchar* _text;
	gint _pos_start;
	gint _pos_end;
};

struct _Regex_testerParamSpecMatchItem {
	GParamSpec parent_instance;
};


static gpointer regex_tester_match_item_parent_class = NULL;

gpointer regex_tester_match_item_ref (gpointer instance);
void regex_tester_match_item_unref (gpointer instance);
GParamSpec* regex_tester_param_spec_match_item (const gchar* name,
                                                const gchar* nick,
                                                const gchar* blurb,
                                                GType object_type,
                                                GParamFlags flags);
void regex_tester_value_set_match_item (GValue* value,
                                        gpointer v_object);
void regex_tester_value_take_match_item (GValue* value,
                                         gpointer v_object);
gpointer regex_tester_value_get_match_item (const GValue* value);
GType regex_tester_match_item_get_type (void) G_GNUC_CONST;
#define REGEX_TESTER_MATCH_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), REGEX_TESTER_TYPE_MATCH_ITEM, Regex_testerMatchItemPrivate))
Regex_testerMatchItem* regex_tester_match_item_new (const gchar* text,
                                                    gint pos_start,
                                                    gint pos_end);
Regex_testerMatchItem* regex_tester_match_item_construct (GType object_type,
                                                          const gchar* text,
                                                          gint pos_start,
                                                          gint pos_end);
static void regex_tester_match_item_set_text (Regex_testerMatchItem* self,
                                       const gchar* value);
static void regex_tester_match_item_set_pos_start (Regex_testerMatchItem* self,
                                            gint value);
static void regex_tester_match_item_set_pos_end (Regex_testerMatchItem* self,
                                          gint value);
const gchar* regex_tester_match_item_get_text (Regex_testerMatchItem* self);
gint regex_tester_match_item_get_pos_start (Regex_testerMatchItem* self);
gint regex_tester_match_item_get_pos_end (Regex_testerMatchItem* self);
static void regex_tester_match_item_finalize (Regex_testerMatchItem * obj);


Regex_testerMatchItem*
regex_tester_match_item_construct (GType object_type,
                                   const gchar* text,
                                   gint pos_start,
                                   gint pos_end)
{
	Regex_testerMatchItem* self = NULL;
#line 23 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (text != NULL, NULL);
#line 23 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self = (Regex_testerMatchItem*) g_type_create_instance (object_type);
#line 24 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	regex_tester_match_item_set_text (self, text);
#line 25 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	regex_tester_match_item_set_pos_start (self, pos_start);
#line 26 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	regex_tester_match_item_set_pos_end (self, pos_end);
#line 23 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return self;
#line 119 "MatchItem.c"
}


Regex_testerMatchItem*
regex_tester_match_item_new (const gchar* text,
                             gint pos_start,
                             gint pos_end)
{
#line 23 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return regex_tester_match_item_construct (REGEX_TESTER_TYPE_MATCH_ITEM, text, pos_start, pos_end);
#line 130 "MatchItem.c"
}


const gchar*
regex_tester_match_item_get_text (Regex_testerMatchItem* self)
{
	const gchar* result;
	const gchar* _tmp0_;
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (self != NULL, NULL);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_tmp0_ = self->priv->_text;
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	result = _tmp0_;
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return result;
#line 147 "MatchItem.c"
}


static void
regex_tester_match_item_set_text (Regex_testerMatchItem* self,
                                  const gchar* value)
{
	gchar* _tmp0_;
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_if_fail (self != NULL);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_tmp0_ = g_strdup (value);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_g_free0 (self->priv->_text);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self->priv->_text = _tmp0_;
#line 164 "MatchItem.c"
}


gint
regex_tester_match_item_get_pos_start (Regex_testerMatchItem* self)
{
	gint result;
	gint _tmp0_;
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_tmp0_ = self->priv->_pos_start;
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	result = _tmp0_;
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return result;
#line 181 "MatchItem.c"
}


static void
regex_tester_match_item_set_pos_start (Regex_testerMatchItem* self,
                                       gint value)
{
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_if_fail (self != NULL);
#line 20 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self->priv->_pos_start = value;
#line 193 "MatchItem.c"
}


gint
regex_tester_match_item_get_pos_end (Regex_testerMatchItem* self)
{
	gint result;
	gint _tmp0_;
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (self != NULL, 0);
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_tmp0_ = self->priv->_pos_end;
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	result = _tmp0_;
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return result;
#line 210 "MatchItem.c"
}


static void
regex_tester_match_item_set_pos_end (Regex_testerMatchItem* self,
                                     gint value)
{
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_if_fail (self != NULL);
#line 21 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self->priv->_pos_end = value;
#line 222 "MatchItem.c"
}


static void
regex_tester_value_match_item_init (GValue* value)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	value->data[0].v_pointer = NULL;
#line 231 "MatchItem.c"
}


static void
regex_tester_value_match_item_free_value (GValue* value)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (value->data[0].v_pointer) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		regex_tester_match_item_unref (value->data[0].v_pointer);
#line 242 "MatchItem.c"
	}
}


static void
regex_tester_value_match_item_copy_value (const GValue* src_value,
                                          GValue* dest_value)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (src_value->data[0].v_pointer) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		dest_value->data[0].v_pointer = regex_tester_match_item_ref (src_value->data[0].v_pointer);
#line 255 "MatchItem.c"
	} else {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		dest_value->data[0].v_pointer = NULL;
#line 259 "MatchItem.c"
	}
}


static gpointer
regex_tester_value_match_item_peek_pointer (const GValue* value)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return value->data[0].v_pointer;
#line 269 "MatchItem.c"
}


static gchar*
regex_tester_value_match_item_collect_value (GValue* value,
                                             guint n_collect_values,
                                             GTypeCValue* collect_values,
                                             guint collect_flags)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (collect_values[0].v_pointer) {
#line 281 "MatchItem.c"
		Regex_testerMatchItem * object;
		object = collect_values[0].v_pointer;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		if (object->parent_instance.g_class == NULL) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 288 "MatchItem.c"
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
#line 292 "MatchItem.c"
		}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = regex_tester_match_item_ref (object);
#line 296 "MatchItem.c"
	} else {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = NULL;
#line 300 "MatchItem.c"
	}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return NULL;
#line 304 "MatchItem.c"
}


static gchar*
regex_tester_value_match_item_lcopy_value (const GValue* value,
                                           guint n_collect_values,
                                           GTypeCValue* collect_values,
                                           guint collect_flags)
{
	Regex_testerMatchItem ** object_p;
	object_p = collect_values[0].v_pointer;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (!object_p) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
#line 320 "MatchItem.c"
	}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (!value->data[0].v_pointer) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		*object_p = NULL;
#line 326 "MatchItem.c"
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		*object_p = value->data[0].v_pointer;
#line 330 "MatchItem.c"
	} else {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		*object_p = regex_tester_match_item_ref (value->data[0].v_pointer);
#line 334 "MatchItem.c"
	}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return NULL;
#line 338 "MatchItem.c"
}


GParamSpec*
regex_tester_param_spec_match_item (const gchar* name,
                                    const gchar* nick,
                                    const gchar* blurb,
                                    GType object_type,
                                    GParamFlags flags)
{
	Regex_testerParamSpecMatchItem* spec;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (g_type_is_a (object_type, REGEX_TESTER_TYPE_MATCH_ITEM), NULL);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	G_PARAM_SPEC (spec)->value_type = object_type;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return G_PARAM_SPEC (spec);
#line 358 "MatchItem.c"
}


gpointer
regex_tester_value_get_match_item (const GValue* value)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, REGEX_TESTER_TYPE_MATCH_ITEM), NULL);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return value->data[0].v_pointer;
#line 369 "MatchItem.c"
}


void
regex_tester_value_set_match_item (GValue* value,
                                   gpointer v_object)
{
	Regex_testerMatchItem * old;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, REGEX_TESTER_TYPE_MATCH_ITEM));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	old = value->data[0].v_pointer;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (v_object) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, REGEX_TESTER_TYPE_MATCH_ITEM));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = v_object;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		regex_tester_match_item_ref (value->data[0].v_pointer);
#line 392 "MatchItem.c"
	} else {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = NULL;
#line 396 "MatchItem.c"
	}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (old) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		regex_tester_match_item_unref (old);
#line 402 "MatchItem.c"
	}
}


void
regex_tester_value_take_match_item (GValue* value,
                                    gpointer v_object)
{
	Regex_testerMatchItem * old;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, REGEX_TESTER_TYPE_MATCH_ITEM));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	old = value->data[0].v_pointer;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (v_object) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, REGEX_TESTER_TYPE_MATCH_ITEM));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = v_object;
#line 424 "MatchItem.c"
	} else {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		value->data[0].v_pointer = NULL;
#line 428 "MatchItem.c"
	}
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (old) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		regex_tester_match_item_unref (old);
#line 434 "MatchItem.c"
	}
}


static void
regex_tester_match_item_class_init (Regex_testerMatchItemClass * klass)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	regex_tester_match_item_parent_class = g_type_class_peek_parent (klass);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	((Regex_testerMatchItemClass *) klass)->finalize = regex_tester_match_item_finalize;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_type_class_add_private (klass, sizeof (Regex_testerMatchItemPrivate));
#line 448 "MatchItem.c"
}


static void
regex_tester_match_item_instance_init (Regex_testerMatchItem * self)
{
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self->priv = REGEX_TESTER_MATCH_ITEM_GET_PRIVATE (self);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self->ref_count = 1;
#line 459 "MatchItem.c"
}


static void
regex_tester_match_item_finalize (Regex_testerMatchItem * obj)
{
	Regex_testerMatchItem * self;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, REGEX_TESTER_TYPE_MATCH_ITEM, Regex_testerMatchItem);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_signal_handlers_destroy (self);
#line 19 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	_g_free0 (self->priv->_text);
#line 473 "MatchItem.c"
}


GType
regex_tester_match_item_get_type (void)
{
	static volatile gsize regex_tester_match_item_type_id__volatile = 0;
	if (g_once_init_enter (&regex_tester_match_item_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { regex_tester_value_match_item_init, regex_tester_value_match_item_free_value, regex_tester_value_match_item_copy_value, regex_tester_value_match_item_peek_pointer, "p", regex_tester_value_match_item_collect_value, "p", regex_tester_value_match_item_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (Regex_testerMatchItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) regex_tester_match_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (Regex_testerMatchItem), 0, (GInstanceInitFunc) regex_tester_match_item_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType regex_tester_match_item_type_id;
		regex_tester_match_item_type_id = g_type_register_fundamental (g_type_fundamental_next (), "Regex_testerMatchItem", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&regex_tester_match_item_type_id__volatile, regex_tester_match_item_type_id);
	}
	return regex_tester_match_item_type_id__volatile;
}


gpointer
regex_tester_match_item_ref (gpointer instance)
{
	Regex_testerMatchItem * self;
	self = instance;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	g_atomic_int_inc (&self->ref_count);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	return instance;
#line 502 "MatchItem.c"
}


void
regex_tester_match_item_unref (gpointer instance)
{
	Regex_testerMatchItem * self;
	self = instance;
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		REGEX_TESTER_MATCH_ITEM_GET_CLASS (self)->finalize (self);
#line 18 "/home/francesco/Progetti_Personali/Regex_tester/src/Objects/MatchItem.vala"
		g_type_free_instance ((GTypeInstance *) self);
#line 517 "MatchItem.c"
	}
}


