#include <bits/stdc++.h>

using namespace std;

int nonDivisibleSubset(int k, vector<int> s)
{
  vector<int> mods(k, 0);

  for (const int e : s) { mods[e % k] += 1; }

  int count = 0;

  if (mods[0] != 0) { count = 1; }


  for (int i = 1; i < (k + 1) / 2; ++i) {
    if (mods[i] > mods[k - i]) {
      count += mods[i];
    } else {
      count += mods[k - i];
    }
  }


  if ((k % 2 == 0) and (mods[k / 2] != 0)) { count++; }

  return count;
}

int main()
{
  int n;
  cin >> n;
  std::vector<int> s(n);
  int k;
  cin >> k;
  for (int &e : s) { cin >> e; }

  /*
  4 3
  1 7 2 4
   */


  cout << nonDivisibleSubset(k, s);

  return 0;
}
