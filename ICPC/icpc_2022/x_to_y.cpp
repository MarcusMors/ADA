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

void f(const int t_x, const int t_h, const int exp);

int main()
{
  const int exp = 4;
  const int x = 16;
  const int h = 16;

  // printf("x:%i -> h: %i\n", x, h);
  f(x, h, exp);

  return 0;
}

void f(const int t_x, const int t_h, int exp)
{
  int x = t_x;
  int h = t_h;
  int n = 1 << exp;
  int b = h - 1;
  int a = n - h;
  int mid = n / 2;

  enum Fold { left, right } fold;
  enum Stack { above, below } stack;

  Stack instructions[exp];

  int last = exp - 1;

  while (last != -1) {
    if (mid < h) {
      // stack below
      instructions[last] = Stack::below;
      const int tmp = a;
      a = b - mid;
      b = tmp;
    } else {
      // stack above
      instructions[last] = Stack::above;
      a = a - mid;
    }

    mid = mid / 2;
    last--;
    h = b + 1;
  }

  // for (int i = 0; i < exp; i++) {
  //   if (instructions[i] == Stack::above) {
  //     cout << "A";
  //   } else {
  //     cout << "B";
  //   }
  // }
  // cout << endl;

  int i = 0;
  mid = n / 2;

  while (i != exp) {

    const int a_mid = mid + 1;
    if (instructions[i] == Stack::above) {
      // fold
      if (x <= mid) {
        cout << 'R';
      } else {
        cout << 'L';
        x = (x - mid);
      }
    } else {// Stack::below
      if (x <= mid) {
        cout << 'L';
        x = (a_mid - x);
      } else {
        cout << 'R';
        x = mid - (x - a_mid);
      }
    }
    //
    mid = mid / 2;
    i++;
  }
}
