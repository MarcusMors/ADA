#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void f(const int n)
{
  //
  const int entries = 1 << n;
  bool table[entries][n];

  bool flag{ false };
  int count = 1 << (n - 1);
  for (int i = 0; i < n; i++) {

    for (int j = 0; j < (1 << n); j++) {
      if (j % count == 0) { flag = not flag; }
      table[j][i] = flag;
    }
    count = count >> 1;
  }

  int rpta = 0;
  char init = 'a';
  stringstream boolean_algebra;
  for (int j = 0; j < (1 << n); j++) {
    stringstream ss;
    bool flag{ true };
    ss << "(";
    if (table[j][0]) {
      ss << init;
    } else {
      ss << "-" << init;
    }
    // cout << table[j][0];
    for (int i = 1; i < n; i++) {//
      ss << "*";
      if (table[j][i]) {
        ss << static_cast<char>(init + i);
      } else {
        ss << "-" << static_cast<char>(init + i);
      }
      // cout << table[j][i];
      if (table[j][i] == 1 and table[j][i - 1] == 1) { flag = false; }
    }
    // cout << endl;
    ss << ")";
    if (flag) {
      boolean_algebra << ss.str() << "+";
      rpta++;
    }
  }
  string str = boolean_algebra.str();
  str.pop_back();
  cout << str << endl;
  cout << rpta << endl;
}

int main()
{
  for (int i = 1; i < 7; i++) { f(i); }
  return 0;
}
