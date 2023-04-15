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

int bin_search(int *t_start, int *t_end, int wanted)
{
  if (wanted >= *t_start) { return 1; }
  if (wanted < *(t_end - 1)) { return t_end - t_start + 1; }
  int *start = t_start;
  int *end = t_end;

  for (int *mid = t_start + (t_end - t_start) / 2; mid != t_end;) {
    if (start == mid) { return (end - t_start) + 1; }
    if (wanted >= *mid) {// go_left
      end = mid;
      mid = start + (end - start) / 2;
    } else {// go_right
      start = mid;
      mid = start + (end - start) / 2;
    }
  }
  return (end - t_start) + 1;
}

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
  vector<int> rpta;

  int unique_ranked[ranked.size()];
  unique_ranked[0] = ranked[0];

  int size{ 1 };

  for (int i = 1; i < ranked.size(); i++) {
    if (ranked[i] == unique_ranked[size - 1]) { continue; }
    unique_ranked[size] = ranked[i];
    size++;
  }

  for (auto p_score : player) {//
    rpta.push_back(bin_search(unique_ranked, unique_ranked + size, p_score));
  }

  return rpta;
}

int main()
{
  /*
7
100 100 50 40 40 20 10

4
5 25 50 120
   */
  int r_n;
  cin >> r_n;
  vector<int> ranked(r_n);
  for (int i = 0; i < r_n; i++) {
    int n;
    cin >> n;
    ranked[i] = n;
  }
  int p_n;
  cin >> p_n;
  vector<int> player(p_n);
  for (int i = 0; i < p_n; i++) {
    int n;
    cin >> n;
    player[i] = n;
  }

  auto rpta = climbingLeaderboard(ranked, player);
  for (auto e : rpta) { cout << e << endl; }


  return 0;
}
