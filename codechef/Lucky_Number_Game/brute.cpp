// Problem: Lucky Number Game
// Contest: CodeChef - JAN19
// URL: https://www.codechef.com/problems/HP18
// Memory Limit: 256 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
typedef long long ll;
#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL);
#define endl "\n"
#define loop(i, start, end) for (int i = start; i <= end; ++i)
#define loopr(i, end, start) for (int i = end; i >= start; --i)
#define pb push_back
#define MOD 1000000007
#define mod(a) (a % MOD + MOD) % MOD
using namespace std;

const int N = 2 * 1e5 + 5;
int A[N];

int main()
{
  IOS;
  int t, n, a, b, x;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    int bob = 0, alice = 0, c = 0;
    loop(i, 0, n - 1)
    {
      cin >> x;
      if (!(x % a) && !(x % b))
        ++c;
      else if (!(x % a))
        ++bob;
      else if (!(x % b))
        ++alice;
    }
    // cout << bob.size() << ' ' << alice.size() << endl;
    if (bob > alice)
      cout << "BOB";
    else if (bob < alice)
      cout << "ALICE";
    else {
      if (c)
        cout << "BOB";
      else
        cout << "ALICE";
    }
    cout << endl;
  }
  // cerr << "Execution: "<<(1.0*clock())/CLOCKS_PER_SEC << "s" << endl;
  return 0;
}
