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

int get_max(istream &is, const char terminator = '\n')
{
  char prev;
  is >> prev;
  char ch;
  for (; is >> ch;) {}
}

int main()
{
  char str[1'000'001];
  getline(cin, str);

  char c;
  //
  cin >> c;

  char prev = c;
  // switch (c) {
  // case 'A':
  //   prev = 0;
  //   break;
  // case 'C':
  //   prev = 1;
  //   break;
  // case 'G':
  //   prev = 2;
  //   break;
  // case 'T':
  //   prev = 3;
  //   break;

  // default:
  //   break;
  // }
  int cont = 1;
  int max = 1;

  //  ACGTACGTACGTACGT...ACGT...ACGT
  while (cin >> c) {
    switch (c) {
    case 'A':
      if (prev == 'T') {
        cont++;
      } else if (cont > max) {
        max = cont;
      }
      prev = 'A';
      break;
    case 'C':
      if (prev == 'A') {
        cont++;
      } else if (cont > max) {
        max = cont;
      }
      prev = 'C';
      break;
    case 'G':
      if (prev == 'C') {
        cont++;
      } else if (cont > max) {
        max = cont;
      }
      prev = 'G';
      break;
    case 'T':
      if (prev == 'G') {
        cont++;
      } else if (cont > max) {
        max = cont;
      }
      prev = 'T';
      break;

    default:
      break;
    }
  }
  cout << max;


  return 0;
}
