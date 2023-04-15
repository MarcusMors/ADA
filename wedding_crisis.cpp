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
#include <bits/stdc++.h>
using namespace std;

int f_r(int *arr, int n, int start, int direction)
{
  //
  return 0;
}

int f(int *arr, int n, int prom, int lowest_i, int highest_i)
{
  // int best_until_now = f_r(arr,n,);

  // for (size_t i = 0; i < count; i++)
  // {
  //   /* code */
  // }

  //
  return best_until_now;
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  int arr[n];
  int prom = 0;
  int c = 0;

  int l_i{ numeric_limits<int>::max() }, h_i{ numeric_limits<int>::min() };
  int li{ 0 }, hi{ 0 };

  if (n == 1) {
    cin >> prom;// receive garbage
    cout << 0;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    c += arr[i];
    if (arr[i] > h_i) {
      h_i = arr[i];
      li = i;
    }
    if (arr[i] < l_i) {
      l_i = arr[i];
      hi = i;
    }
  }

  prom = c / n;

  cout << f(arr, n, prom, li, hi) << endl;

  return 0;
}
