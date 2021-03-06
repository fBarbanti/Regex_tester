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

public class Regex_tester.HeaderBar : Gtk.HeaderBar {

    construct {
        set_title("Regex Tester");
        set_show_close_button(true);
        var setting_button = new Gtk.Button.from_icon_name("open-menu");
        setting_button.valign = Gtk.Align.CENTER;

        pack_end(setting_button);
       
    }

}

