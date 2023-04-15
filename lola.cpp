// Copyright (C) 2023 José Enrique Vilca Campana
// b
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

// T <= 8

#include <iostream>
#include <limits>

using namespace std;

struct SD
{
  int start{};
  int duration{};
  SD() = default;
  SD(int s, int d) : start{ s }, duration{ d } {}
  // int start(){}
  [[nodiscard]] int end() const { return start + duration; }
  [[nodiscard]] int within_range(int t) const { return start <= t && t <= end(); }
};

void f(SD events[], int n, int x, int &t, int &c, int lowest_possible)
{
  const int max_i = events[n - 1].end() + 1;
  const int max_t = 8 * 60;

  int best_t_until_now{};
  int lowest_c_until_now{ std::numeric_limits<int>::max() };

  for (t = 0; t < max_t; t++) {
    c = 0;

    for (int i = t; i < max_i; i += x) {

      // check conflicts
      for (int j = 0; j < n; j++) {
        cout << "s:" << events[j].start << ",e:" << events[j].end() << endl;
        cout << "t:" << t << ",i:" << i << endl;
        // if^
        if (events[j].within_range(i)) {
          //
          c++;
        }
      }

      if (c < lowest_c_until_now) {
        best_t_until_now = t;
        lowest_c_until_now = c;
      }
      cout << c << endl;
    }
    cout << "end analysis" << endl;
    if (c == lowest_possible) { break; }
  }
  t = best_t_until_now;
  c = lowest_c_until_now;
}


int main()
{
  int n;
  cin >> n;

  SD events[n];

  int x;
  cin >> x;

  // int longest = std::numeric_limits<int>::min();
  // int shortest = std::numeric_limits<int>::max();

  int n_longer_than_x{};
  int n_shorter_than_x{};
  // int earliest_s = std::numeric_limits<int>::max();
  // int most_later_s = std::numeric_limits<int>::min();

  for (int i = 0; i < n; i++) {
    int &start = events[i].start;
    int &duration = events[i].duration;

    cin >> start;
    cin >> duration;

    // if (duration < n_shorter_than_x) {
    //   n_shorter_than_x++;
    // } else if (duration > n_longer_than_x) {
    //   n_longer_than_x++;
    // }

    if (duration < x) {
      n_shorter_than_x++;
    } else if (duration > x) {
      n_longer_than_x++;
    } else {
      n_shorter_than_x++;
      n_longer_than_x++;
    }
  }

  // sort starts and d's;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (events[j].start > events[i].start) {
        const SD tmp = events[i];
        events[i] = events[j];
        events[j] = tmp;
      }
    }
  }


  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  for (int i = 0; i < n; i++) { cout << "(" << events[i].start << ";" << events[i].duration << ")" << endl; }


  int t, c;
  f(events, n, x, t, c, events[n - 1].end(), n_longer_than_x);
  cout << t;
  cout << c;
  cout << endl;
  return 0;
}
