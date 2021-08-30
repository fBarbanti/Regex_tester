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


public class Regex_tester.Window : Gtk.ApplicationWindow {

    private Gtk.Entry entry_regex;
    private Gtk.TextView text_view;
    private RegexCompileFlags regex_compile_flags = GLib.RegexCompileFlags.CASELESS;
    private Gtk.Switch flag_case_insensitive;
    private Gtk.Switch flag_multiline;
    private Gtk.ListBox list_box;
    
    private int num_match;
    private Gtk.Label label_num_match;

    public Window(Gtk.Application app){
        Object (
            application: app
        );
    }



    construct {
        
        window_position = Gtk.WindowPosition.CENTER;
        set_default_size(1050,600);


        // Frame e label per num_match
        num_match = 0;
        
        var frame_num_match = new Gtk.Frame(null);
        frame_num_match.halign = Gtk.Align.END;
        frame_num_match.valign = Gtk.Align.CENTER;

        label_num_match = new Gtk.Label( @"$num_match" + " Match!");
        label_num_match.margin = 4;
        label_num_match.get_style_context ().add_class("flag-title");

        frame_num_match.set_label_widget(label_num_match);
        frame_num_match.margin_bottom = 10;
        frame_num_match.margin_top = 0;
        frame_num_match.get_style_context ().add_class("frame-border");

        // Crea flag chooser
        var regex_flags_chooser = create_flag_choose();

        // Metti della stessa dimensione num_match e flag chooser
        var size_group = new Gtk.SizeGroup(Gtk.SizeGroupMode.VERTICAL);
        size_group.add_widget(frame_num_match);
        size_group.add_widget(regex_flags_chooser);

        // Aggiungi num_match e flag chooser in un box
        var box_regex = new Gtk.Box(Gtk.Orientation.HORIZONTAL, 1);
        box_regex.halign = Gtk.Align.END;
        box_regex.pack_start (frame_num_match);
        box_regex.pack_start (regex_flags_chooser);

        // Regex entry
        entry_regex = new Gtk.Entry();
        entry_regex.set_placeholder_text("insert your regular expression here");
        entry_regex.margin = 10;
        entry_regex.margin_top = 0;
        entry_regex.valign = Gtk.Align.CENTER;
        entry_regex.changed.connect(apply_regex);
        entry_regex.halign =  Gtk.Align.FILL;
        entry_regex.get_style_context ().add_class ("text");
        entry_regex.set_hexpand(true);


        // Griglia in cui mettere entry e box regex
        var grid_top_window = new Gtk.Grid();
        grid_top_window.attach(entry_regex, 0, 0);
        grid_top_window.attach(box_regex, 1, 0);

        // TextView testo
        var scrolled_window = new Gtk.ScrolledWindow(null, null);
        scrolled_window.set_policy(Gtk.PolicyType.AUTOMATIC, Gtk.PolicyType.AUTOMATIC);

        text_view = new Gtk.TextView();
        text_view.set_wrap_mode(Gtk.WrapMode.WORD);
        text_view.set_hexpand(true);
        text_view.set_vexpand(true);
        text_view.left_margin = 12;
        text_view.top_margin = 12;
        text_view.get_buffer().changed.connect (() => apply_regex());
        text_view.get_style_context ().add_class ("text");
        scrolled_window.add(text_view);


        // create TextTag
        //  var rgba = Gdk.RGBA ();
        //  rgba.parse (Costants.color1);

        //  text_view.buffer.create_tag ("marked_first", "background_rgba", rgba);
        text_view.buffer.create_tag ("color0", "background", Costants.color0);
        text_view.buffer.create_tag ("group1", "background", Costants.color_group1);
        text_view.buffer.create_tag ("group2", "background", Costants.color_group2);
        text_view.buffer.create_tag ("group3", "background", Costants.color_group3);

        



        var grid = new Gtk.Grid();
        grid.margin = 12;
        grid.column_spacing = 12;
        grid.row_spacing = 12;
        grid.attach(grid_top_window, 0, 0);
        grid.attach(new Gtk.Separator (Gtk.Orientation.HORIZONTAL), 0, 1);
        grid.attach(scrolled_window, 0, 2);

        // Matches
        var matches_label = new Gtk.Label ("Match Information");
        matches_label.halign = Gtk.Align.START;
        matches_label.margin = 6;
        matches_label.get_style_context ().add_class ("match-title");
        matches_label.halign = Gtk.Align.CENTER;

        // Lista risultati
        list_box = new Gtk.ListBox();
        list_box.expand = true;
        list_box.width_request = 250;

        var scroller = new Gtk.ScrolledWindow (null, null);
        scroller.width_request = 250;
        scroller.add(list_box);

        // Griglia della sidebar
        var grid_sidebar = new Gtk.Grid();
        grid_sidebar.attach(matches_label, 0, 0);
        grid_sidebar.attach(new Gtk.Separator (Gtk.Orientation.HORIZONTAL),0, 1);
        grid_sidebar.attach(scroller, 0, 2);

        var pane = new Gtk.Paned (Gtk.Orientation.HORIZONTAL);
        pane.expand = true;
        pane.pack1 (grid, true, false);
        pane.pack2 (grid_sidebar, false, false);

        add(pane);
        
        var headerbar = new Regex_tester.HeaderBar();
        set_titlebar(headerbar);


        show_all();

    }

    /*
        Metodo che, una volta modificata la regex la esegue e seleziona i match
    */
    
    private void apply_regex(){

        var str_regex =  this.entry_regex.text;
        var str_text = text_view.buffer.text;

    
        Gtk.TextIter start, end;
        text_view.buffer.get_bounds (out start, out end);
        
        // Rimuovi vecchi tag
        remove_tags(text_view);
        
        // Resetta il numero di match
        num_match = 0;

        // Pulisci i risultati
        foreach (var match in list_box.get_children ()) {
            list_box.remove (match);
        }

        Regex regex;
        MatchInfo match_info;

        if (str_regex == "") {
            return;
        }

        // Elimina l'icona dell'errore
        entry_regex.set_icon_from_icon_name(Gtk.EntryIconPosition.SECONDARY, null);
        set_compile_flags();


        try {
            regex = new Regex(str_regex, regex_compile_flags);
            GLib.List<string> list = new GLib.List<string> ();

            if(regex.match(str_text, 0, out match_info)){

                int pos_start = 0;
                int pos_end = 0;

                while(match_info.matches()) {
                    //  Regex_tester.MatchItem group_items = new Regex_tester.MatchItem ();

                    var match_grid = new Gtk.Grid();

                    for(int i=0; i<match_info.get_match_count(); i++){
                        match_info.fetch_pos(i, out pos_start, out pos_end);
                        //  stdout.printf( "start:%d - end:%d\n-----\n", pos_start, pos_end);
                        
                        start.set_offset(pos_start - shift_unichar (str_text, pos_start));
                        end.set_offset(pos_end - shift_unichar (str_text, pos_end));
                        
                        string str = match_info.fetch (i);
                        list.append(str);

                       
                        if(str != ""){
                            // Se è un match
                            if (i == 0)
                                text_view.buffer.apply_tag_by_name("color0", start, end);
                            else{
                            // se è un gruppo
                                string s = "group" + i.to_string ();
                                text_view.buffer.apply_tag_by_name(s, start, end);
                            }

                            match_grid.attach(new Gtk.Label(str), 0, i);
                        }
                    }
                    list_box.add(new Gtk.Separator (Gtk.Orientation.HORIZONTAL));
                    list_box.add(match_grid);

                    num_match ++;

                    match_info.next();
                }
                list_box.show_all();

            }
        }

        catch( RegexError re ) {
            entry_regex.set_icon_from_icon_name(Gtk.EntryIconPosition.SECONDARY,"dialog-error");
            entry_regex.set_icon_tooltip_markup(Gtk.EntryIconPosition.SECONDARY, "EXEC ERROR: Invalid regular expression");  
        }   
        
        label_num_match.label =  @"$num_match" + " Match!";

        return;
    }

    private Gtk.MenuButton create_flag_choose(){
        // Regex flags 
        flag_case_insensitive = new Gtk.Switch();
        flag_multiline = new Gtk.Switch();

        flag_case_insensitive.halign = Gtk.Align.END;
        flag_multiline.halign = Gtk.Align.END;

        var flag_case_insensitive_name = new Gtk.Label("Case Insensitive");
        var flag_multiline_name = new Gtk.Label("Multiline");

        flag_case_insensitive_name.margin = 5;
        flag_multiline_name.margin = 5;


        var flag_case_insensitive_box = new Gtk.Box(Gtk.Orientation.HORIZONTAL, 0);
        flag_case_insensitive_box.pack_start (flag_case_insensitive_name);
        flag_case_insensitive_box.pack_start (flag_case_insensitive);

        var flag_multiline_box = new Gtk.Box(Gtk.Orientation.HORIZONTAL, 0);
        flag_multiline_box.pack_start (flag_multiline_name);
        flag_multiline_box.pack_start (flag_multiline);

        flag_case_insensitive.notify["active"].connect(apply_regex);
        flag_multiline.notify["active"].connect(apply_regex);


        // Box che contiene i radio button dei flag
        var menu_flags = new Gtk.Box(Gtk.Orientation.VERTICAL, 0);
        var label = new Gtk.Label("Expression flag");
        menu_flags.pack_start (label, false, false, 2);
        menu_flags.pack_start (new Gtk.Separator (Gtk.Orientation.HORIZONTAL), false, false, 2);
        menu_flags.pack_start (flag_case_insensitive_box, false, false, 2);
        menu_flags.pack_start (flag_multiline_box, false, false, 2);
        menu_flags.margin = 3;

        // MAke lable expression flag bold
        var label_context = label.get_style_context ();
        label_context.add_class ("flag-title");

        // Creo un popover
        var popover_flag = new Gtk.PopoverMenu ();
        popover_flag.add (menu_flags);

        // Inserisco i check button dei flag in un Menu button
        var regex_flags_chooser = new Gtk.MenuButton();
        regex_flags_chooser.set_popover(popover_flag);
        regex_flags_chooser.direction = Gtk.ArrowType.DOWN;
        regex_flags_chooser.halign = Gtk.Align.END;
        regex_flags_chooser.has_tooltip = true;
        regex_flags_chooser.valign = Gtk.Align.CENTER;
        regex_flags_chooser.tooltip_text = "Choose flags for your regex";
        regex_flags_chooser.set_image(new Gtk.Image.from_icon_name ("accessories-dictionary", Gtk.IconSize.SMALL_TOOLBAR));
        regex_flags_chooser.set_always_show_image(true);
        regex_flags_chooser.set_label("Flags");
        regex_flags_chooser.clicked.connect(() => popover_flag.show_all());
        regex_flags_chooser.margin = 10;
        regex_flags_chooser.margin_top = 0;

        return regex_flags_chooser;
    }
    private void set_compile_flags(){

        // clear flag
        if(GLib.RegexCompileFlags.CASELESS in regex_compile_flags)
            regex_compile_flags = regex_compile_flags - GLib.RegexCompileFlags.CASELESS;
        if(GLib.RegexCompileFlags.MULTILINE in regex_compile_flags)
            regex_compile_flags = regex_compile_flags - GLib.RegexCompileFlags.MULTILINE;

        // set the correct flag 
        if(flag_case_insensitive.get_active())
            regex_compile_flags = regex_compile_flags | GLib.RegexCompileFlags.CASELESS;
        if(flag_multiline.get_active())            
            regex_compile_flags = regex_compile_flags | GLib.RegexCompileFlags.MULTILINE;


       return;
    }

    private void remove_tags(Gtk.TextView text_view){
        Gtk.TextIter start, end;
        text_view.buffer.get_bounds (out start, out end);

        start.set_offset (0);
        end.set_offset (text_view.buffer.text.length);

        text_view.buffer.remove_all_tags (start, end);

        return;
    }

    private int shift_unichar (string text, int pos) {
        int return_value = 0;
        var substring = text.substring (0, pos);

        foreach (var c in substring.to_utf8 ()) {
            if (c.isprint () || c.isspace ()) {
                continue;
            }
            return_value += 1;
        }

        return return_value / 2;
    }

    //  private string hex_to_rgb(string c1, string c2){

    //  }
}