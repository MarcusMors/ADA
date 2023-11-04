#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
  int n;
  int k;
  cin >> n >> k;
  int c = 0;
  for (int i = 0; i < n; i++) {
    int hora;
    int min;
    cin >> hora >> min;
    min += (60 * hora) - (7 * 60);
    if (min <= k) { c++; }
  }
  cout << c << endl;
}
