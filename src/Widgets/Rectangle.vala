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


//  public class Regex_tester.Rectangle : Gtk.Widget {

//      public double red {get; private set;}
//      public double green {get; private set;}
//      public double blue {get; private set;}


//      private Pango.Layout layout;

//      construct {
//          set_has_window (false);
//      }
    
//      public Rectangle (int red, int green, int blue){
//          this.red = red / 255;
//          this.green = green / 255;
//          this.blue = blue  / 255;
//          set_has_window (false);

//      }
     
//      public override bool draw (Cairo.Context cr) {

//          cr.set_source_rgba (red, green, blue, 1.0);
//          //  cr.rectangle (0, 0, 50, 50);
//          cr.arc(0, 0, 100, 0, 2*Math.PI);

//          //  cr.set_line_width (1);
//          //  cr.set_line_join (Cairo.LineJoin.ROUND);
//          cr.set_line_width (10.0);
//          cr.stroke ();
//          cr.fill();
//          return true;
//      }
    
//      /*
//       * This method gets called by Gtk+ when the actual size is known
//       * and the widget is told how much space could actually be allocated.
//       * It is called every time the widget size changes, for example when the
//       * user resizes the window.
//       */
//      public override void size_allocate (Gtk.Allocation allocation) {
//          // The base method will save the allocation and move/resize the
//          // widget's GDK window if the widget is already realized.
//          base.size_allocate (allocation);

//          // Move/resize other realized windows if necessary
//      }
//  }

public class Regex_tester.Rectangle : Gtk.Frame {
    
    public string style_color {get; private set;}

    public Rectangle(string style){
        style_color = style;
        set_size_request(6,18);
        margin = 3;
        margin_right = 0;
        valign = Gtk.Align.CENTER;
        get_style_context ().add_class(style_color);

    }

                                //  var colored_frame = new Gtk.Frame(null);
                            //  colored_frame.set_size_request(6, 13);
                            //  var ds = Gdk.RGBA ();
                            //  ds.red = 255;
                            //  ds.green = 186;
                            //  ds.blue = 0;
                            //  ds.alpha = 1;
                            //  colored_frame.override_background_color(Gtk.StateFlags.NORMAL,ds);
                            //  colored_frame.margin_start = 5;

}