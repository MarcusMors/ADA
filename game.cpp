
// #include <iostream>
#include <bits/stdc++.h>

using namespace std;

int get_i(int d)
{
  if (d == 2) { return 3; }

  const int n = sqrt(2 * d);

  // int c = n * (n + 1) / 2 - d;// case: 19, make it 4
  const int c = d - n * (n + 1) / 2;// case: 19, make it 4
  const int careful = d - (n * n) / 2;
  // check no exactly quadratic term of (n+1), (n+1)*(n+1) instead of n*(n+1); cases: 8, 32 , ...

  if (careful == 0) {// it's quadratic! exception
    // cout << "CAREFUL" << endl;
    return (2 * n) - 1;
  }

  if (c > -1) { return n + 2 * c; }
  if (c < -1) { return n + 1 + (-2 * c); }
  //  c is -1
  return n + 2;
}

int main()
{
  int a, b;
  cin >> a >> b;

  if (a > b) {
    cout << get_i(a - b);
  } else {
    cout << get_i(b - a);
  }
  // vector diffs{ 2, 10, 5, 12, 100, 534, 532, 1, 1000 };
  // for (auto &&d : diffs) { cout << d << ", "; }
  // cout << endl;
  // for (auto &&d : diffs) { cout << get_i(d) << ", "; }
  // cout << endl;

  // cout << "expected" << endl;
  // vector expected{ 3, 4, 5 };
  // for (auto &&d : diffs) { cout << get_i(d) << ", "; }
  // cout << endl;


  // const int d{ 128 };
  // // const int d{ 32 };
  // // const int d{ 8 };
  // // const int d{ 45 };
  // cout << get_i(d) << endl;

  return 0;
}
