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

#include <bitset>
#include <iostream>
#include <string>

#include <iostream>

using namespace std;

int main()
{
  const unsigned max_input = 100000;
  unsigned arr[max_input]{};
  unsigned n;
  cin >> n;

  for (unsigned i = 0; i < n; i++) {
    unsigned exp;
    cin >> exp;
    arr[exp]++;
  }

  unsigned *l_it{ nullptr };
  unsigned counter{ 0 };

  bool first_one{ false };
  bool second_one{ false };
  for (unsigned *it = arr; it != arr + max_input - 1 and counter < n - 1; it++) {
    if (*it == 0) { continue; }
    if ((*it & 1) == 0) {// it's pair
      *(it + 1) += *it / 2;
      *it = 0;
      l_it = it + 1;
      counter++;
    } else {// odd case
      if (first_one) {
        if (second_one) {
          cout << "N";
          return 0;
        }
        second_one = true;
      }
      first_one = true;
    }
  }

  if (l_it != nullptr) {
    if ((*l_it & 1) == 0) {
      cout << "Y";
    } else if (n > 1 and *l_it == 1) {
      cout << "Y";
    } else {
      cout << "N";
    }
  } else {
    cout << "N";
  }
  return 0;
}
