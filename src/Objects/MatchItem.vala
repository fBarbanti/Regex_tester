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

public class Regex_tester.MatchItem  {
    public string text { get; private set; }
    public int pos_start { get; private set; }
    public int pos_end { get; private set; }

    public MatchItem (string text, int pos_start, int pos_end) {
        this.text = text;
        this.pos_start = pos_start;
        this.pos_end = pos_end;
    }
    
}
