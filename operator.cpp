// Copyright (C) 2023 José Enrique Vilca Campana
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as
// published by the Free Software Foundation, either version 3 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


#include <iostream>

using namespace std;

int f(int n, int x, int y)
{
  if ((x + y % 2) == 0) { return n - 2; }
  return n;
}

int main()
{
  int t{};
  cin >> t;
  for (int n = 0; n < t; n++) {
    cin >> n;
    int x{}, y{};
    cin >> x >> y;
    if (x + y > n / 2) { cout << -1 << endl; }
    cout << f(n, x, y) << endl;
  }


  return 0;
}
