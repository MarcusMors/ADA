#include <bits/stdc++.h>
#include <cctype>

#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// __gcd(value1, value2)
// append ll to get the long long version
// __builtin_ffs(x)// returns 1+ index of least significant bit else returns cero.
// __builtin_ffs(10) = 2 // because 10: "1010", 2 is 1 + the index of the least significant bit from right to left
// __builtin_clz(x) // returns number of leading 0-bits of x which starts from most significant bit position.
// __builtin_clz(16) = 27// int has 32 bits, because 16: "1 0000", has 5 bits, 32 - 5 = 27.
// __builtin_popcount(x) // returns number of 1-bits of x. x is unsigned int
// __builtin_popcount(14) = 3// because 14: "1110", has three 1-bits.

// #define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
// #define type typename

using namespace std;
using ui = unsigned;
using cui = const unsigned;
using strs = std::stringstream;
using vii = std::vector<std::pair<int, int>>;
using vi = std::vector<int>;
using ii = std::pair<int, int>;

template<class T, class U> std::ostream &operator<<(ostream &os, pair<T, U> v)
{
  return os << "(" << v.first << "," << v.second << ")";
}
template<class T> std::ostream &operator<<(ostream &os, vector<T> v)
{
  for (auto &&e : v) { os << e << " "; }
  return os;
}

template<class It> void print(It begin, It end)
{
  while (begin != end) {
    cout << *begin << " ";
    begin++;
  }
}
template<class It> void print(It it, int n) { print(it, it + n); }
template<class T> void print(vector<T> v, int n) { print(v.begin(), v.begin() + n); }


template<class It> void fill(It it, int n)
{
  It limit = it + n;
  auto val = *it;
  if (n == 0) { return; }
  cin >> val;
  *it = val;
  ++it;

  while (it != limit) {
    char coma;
    cin >> coma;
    cin >> val;
    *it = val;
    ++it;
  }
}

template<class T> void fill(vector<T> &v) { fill(v.begin(), v.size()); }
template<class T> void fill(vector<T> &v, int n) { fill(v.begin(), n); }


int sum_of_digits(string str)
{
  if (str.empty()) { return 0; }
  int sum = str[0] - '0';
  while (str.size() > 1) {
    strs ss;
    sum = 0;
    for (auto e : str) { sum += e - '0'; }
    str = to_string(sum);
  }

  return sum;
}

void solve()
{
  const string get_l[10]{
    "zer",// 0
    "one",// 1
    "two",// 2
    "thr",// 3
    "fou",// 4
    "fiv",// 5
    "six",// 6
    "sev",// 7
    "eig",// 8
    "nin",// 9
  };

  string line;
  getline(cin, line);

  bool negative_num{ false };
  if (line[0] == '+') {
    line.erase(line.begin());
  } else if (line[0] == '-') {
    line.erase(line.begin());
    negative_num = true;
  }

  strs ss{ line };

  int count = 0;
  for (auto &&e : line) {
    if (e == ' ') { count++; }
  }
  if (count > 1) {
    cout << "Invalid";
    return;
  }

  string num_str;
  string name;
  ss >> num_str;

  int dot_count = 0;
  bool dot{ false };
  int dot_i = 0;

  for (auto &&e : num_str) {
    if (isdigit(e)) {
      continue;
    } else if (e == '.') {
      dot = true;
      dot_count++;
      if (dot_count > 1) {
        cout << "Invalid";
        return;
      }
    } else {
      cout << "Invalid";
      return;
    }
    dot_i++;
  }

  ss >> name;
  strs num_ss{ num_str };
  int lhs;
  int exp{ 0 };

  int integer{ 0 };
  int decimal{ 0 };
  bool sign{ true };

  if (dot) {
    char d;
    num_ss >> lhs;
    num_ss >> d;
    string l = to_string(lhs);
    if (lhs == 0) {
      // consider the prefix ceros of rhs
      int n_0 = 0;
      for (size_t i = dot_i + 2; i < num_str.size(); i++) {
        if (num_str[i] == '0') {
          n_0++;
        } else {
          break;
        }
      }
      string r(num_str.begin() + dot_i + 2 + n_0, num_str.end());
      // cout << "r: " << r << "\n";

      sign = false;
      exp = sum_of_digits(to_string(n_0 + 1));
      integer = r[0] - '0';
      r.erase(r.begin());
      // cout << "r: " << r << "\n";
      decimal = sum_of_digits(r);

    } else {

      sign = true;
      exp = sum_of_digits(to_string(l.size() - 1));
      integer = l[0] - '0';
      l.erase(l.begin());
      string r{ "" };
      num_ss >> r;
      l += r;
      decimal = sum_of_digits(l);
    }
  } else {
    // num_str
    int prefix_zeros = 0;
    for (auto &&e : num_str) {
      if (e == '0') {
        prefix_zeros++;
      } else {
        break;
      }
    }

    string n(num_str.begin() + prefix_zeros, num_str.end());

    sign = true;
    exp = sum_of_digits(to_string(n.size() - 1));
    integer = n[0] - '0';
    n.erase(n.begin());
    decimal = sum_of_digits(n);
  }

  if (negative_num) { cout << "-"; }

  cout << get_l[integer] << "." << get_l[decimal] << "e";
  if (exp != 0) {
    if (sign) {
      cout << "+";
    } else {
      cout << "-";
    }
  }
  cout << get_l[exp] << "@";
  if (exp % 2 == 0) {
    for (size_t i = 1; i < name.size(); i += 2) { cout << name[i]; }
  } else {
    for (size_t i = 0; i < name.size(); i += 2) { cout << name[i]; }
  }
  //    123456
  // 00.00000934749
}


/*
1
054785949 rajarajeswari

1
00.00000934749 bhuvaneswari

2
054785949 rajarajeswari
00.00000934749 bhuvaneswari

out:
fiv.onee+sev@rjrjsai
nin.nine-six@hvnsai

input
2
12.7u3 mahadev
3 dhanyajoselyn
out:
Invalid
thr.zerezer@hnaoey

 */

signed main()
{
  fastio();

  int t;
  string str;
  getline(cin, str);
  t = stoi(str);
  // cin >> t;
  for (int i = 0; i < t - 1; i++) {
    solve();
    cout << "\n";
  }
  solve();

  // while (t--) { solve(); }
  // solve();

  return 0;
}
