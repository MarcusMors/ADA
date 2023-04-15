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

int query(int tree[], int start, int end, int n, int h)
{
  if (tree[n * 2 + 1])
  {
  }
}

// int make_tree(int &arr[], int v_start, int v_end)
// {
// }

int main()
{

  int n;
  cin >> n;
  int arr[2 * n];

  for (int i = n; i < 2 * n; i++)
  {
    cin >> arr[i];
  }

  for (int i = n - 1; i > 0; i--)
  {
    arr[i] = arr[i * 2] + arr[(i * 2) + 1];
  }

  for (int i = 0; i < 2 * n; i++)
  {
    cout << arr[i] << ", ";
  }
  cout << endl;

  int l = 10;
  int r = 11;

  cout << query(arr, l, r, 0) << endl;

  // 1, 1*2 = left ... 1*2 +1 = right

  return 0;
}

/*
8
2 2 9 5 7 3 6 10
*/

// 7 -> 3 -> 1 -> 0
// 8 -> 4 -> 2 -> 1 -> 0
