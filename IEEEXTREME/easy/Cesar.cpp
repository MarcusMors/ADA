#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define FI first
#define SE second
#define MP make_pair
#define PB push_back

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

const int INF = 1e18, N = 2e5 + 10, MOD = 1e9 + 7;
const int SQN = sqrtl(N) + 1, LOGN = __lg(N) + 1;
const ld EPS = 1e-6;

string s;
void solve()
{
  int n;
  getline(cin, s);
  n = stoi(s);
  string in;
  getline(cin, in);
  in = " " + in + " ";
  auto indx = in.find(" the ");
  if (indx != string::npos) {
    // auto indx = in.find(" the");
    // cipher
    for (char &c : in) {
      if (!isspace(c)) { c = ((c - 'a') - n + 26) % 26 + 'a'; }
    }
  } else {
    // decipher
    for (char &c : in) {
      if (!isspace(c)) {
        c = ((c - 'a') + n) % 26 + 'a';
        //~ cout<<c<<"\n";
      }
    }
  }
  in.pop_back();
  cout << in.substr(1, string::npos) << "\n";
}

signed main()
{
  cin.tie(0)->sync_with_stdio(0);
  cout.precision(10);
  cout << fixed;
  int t;
  getline(cin, s);
  t = stoi(s);
  while (t--) { solve(); }
  //~ solve();
  return 0;
}
