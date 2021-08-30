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

 public class Application : Gtk.Application {
    public Application () {
        Object (
            application_id: "com.github.fBarbanti.Regex_tester",
            flags: ApplicationFlags.FLAGS_NONE
        );
    }

    protected override void activate () {
       
        var css_provider = new Gtk.CssProvider ();
        css_provider.load_from_resource("/com/github/fBarbanti/Regex_tester/styles/style.css");
        Gtk.StyleContext.add_provider_for_screen(Gdk.Screen.get_default (), css_provider, Gtk.STYLE_PROVIDER_PRIORITY_USER);

        var window = new Regex_tester.Window(this);

        add_window(window);

    }

}