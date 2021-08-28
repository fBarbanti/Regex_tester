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

public class Regex_tester.HeaderBar : Gtk.HeaderBar {
    // Custom propriety
    //  public Gtk.TextView window_regex_box { get; construct; }
    //  public Gtk.TextView window_text_box { get; construct; }

    // Costruttore pubblico
    //  public HeaderBar(Gtk.TextView regex_box, Gtk.TextView text_box) {
    //      Object ( 
    //          window_regex_box: regex_box,
    //          window_text_box: text_box
    //      );
    //  }
    construct {
        set_title("Regex Tester");
        set_show_close_button(true);

        //  var play_button =  new Gtk.Button.from_icon_name("media-playback-start", Gtk.IconSize.BUTTON);
        //  play_button.valign = Gtk.Align.CENTER;

        var setting_button = new Gtk.Button.from_icon_name("open-menu");
        setting_button.valign = Gtk.Align.CENTER;

        pack_end(setting_button);
        //  pack_end(play_button);

        //  play_button.clicked.connect(() => {
        //      //  var i = window_result_box.create_buffer();
        //      //  i = window_result_box.get_buffer();
        //      //  //  print(i.text);
        //      //  //  print("------\n");
        //      //  var j = window_text_box.create_buffer();
        //      //  j = window_text_box.get_buffer();
        //      //  print(j.text);
            
        //  //     MyApp.Window.appy_regex(j.text, i.text);
        //      MyApp.Window.apply_regex();
        //  });

    }

}

