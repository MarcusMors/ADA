#include <bits/stdc++.h>

using namespace std;

signed main()
{
  vector<int> v{ 7, 3, 1, 4, 7, 2, 9 };
  sort(v.rbegin(), v.rend());
  int arr[10] = { 2, 4, 8, 2, 9, 2, 1, 8, 2, 10 };
  sort(arr, arr + 10);

  for (int i = 0; i < v.size(); i++) { cout << v[i] << " "; }

  return 0;
}
