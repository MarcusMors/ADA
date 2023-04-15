// Copyright (C) 2022 José Enrique Vilca Campana
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

int main()
{
  int n{ 12 };
  if (((n * (n + 1)) >> 1) & 1) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  if (n & 1)// it's ODD
  {
    const int n_half = (n >> 1);
    cout << n_half + 1 << "\n";
    cout << "1 2";

    const int size_of_sub_set = (n - 3) >> 2;
    int i = 4;
    for (; i < size_of_sub_set + 4; i++) { cout << " " << i; }
    for (int j = n + 1 - size_of_sub_set; j < n + 1; j++) { cout << " " << j; }
    cout << "\n";
    cout << n_half << "\n";
    cout << "3";
    for (; i < n + 1 - size_of_sub_set; i++) { cout << " " << i; }
  } else {// it's EVEN
    const int n_half = n >> 1;
    cout << n_half << "\n";
    const int size_of_sub_set = n >> 2;
    cout << "1";
    int i = 2;
    for (; i < size_of_sub_set + 1; i++) { cout << " " << i; }
    for (int j = n + 1 - size_of_sub_set; j < n + 1; j++) { cout << " " << j; }
    cout << "\n";
    cout << n_half << "\n";
    cout << i;
    i++;
    for (; i < n + 1 - size_of_sub_set; i++) { cout << " " << i; }
  }

  return 0;
}
