#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// __gcd(value1, value2)
// append ll to get the int version
// __builtin_ffs(x)// returns 1+ index of least significant bit else returns cero.
// __builtin_ffs(10) = 2 // because 10: "1010", 2 is 1 + the index of the least significant bit from right to left
// __builtin_clz(x) // returns number of leading 0-bits of x which starts from most significant bit position.
// __builtin_clz(16) = 27// int has 32 bits, because 16: "1 0000", has 5 bits, 32 - 5 = 27.
// __builtin_popcount(x) // returns number of 1-bits of x. x is unsigned int
// __builtin_popcount(14) = 3// because 14: "1110", has three 1-bits.

// #define int long long
#define rep(i, begin, end) \
  for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

// 4'294'967'296
const int INF = 1'000'000'000;

bool reachable(int start[2], int end[2])
{
  int x = end[0] - start[0];
  int y = abs((end[1] - start[1]));
  return ((x >= 0) && (x >= y)) ? true : false;
}

int max(int arr[], int length)
{
  int max = 0;
  for (int i = 0; i < length; i++) { max = (max < arr[i]) ? arr[i] : max; }
  return max;
}

int walter(int start[2], int bearingsPoints[][3] = { 0 }, int length = 0, int accumulated = 0)
{

  if (length == 0) {
    return accumulated;
  } else if (length == 1) {
    return accumulated + bearingsPoints[0][2];
  }

  int arr[length];
  int auxStart[2];
  int auxEnd[2];

  for (int i = 0; i < length; i++) {
    int counter = 0;
    int auxLength = (length);
    int auxBearingsPoints[auxLength][3];

    auxStart[0] = bearingsPoints[i][0];
    auxStart[1] = bearingsPoints[i][1];

    for (int j = 0; j < auxLength; j++) {
      if (j != i) {
        auxEnd[0] = bearingsPoints[j][0];
        auxEnd[1] = bearingsPoints[j][1];

        if (reachable(auxStart, auxEnd)) {
          auxBearingsPoints[counter][2] = bearingsPoints[j][2];
          counter++;
        }
      }
    }
    arr[i] = walter(auxStart, auxBearingsPoints, counter, accumulated + bearingsPoints[i][2]);
  }

  return max(arr, length);
}

signed main()
{
  int n;
  cin >> n;
  int example[1];
  int bearingsPoints[n][3];
  int auxBearingsPoints[3];
  int start[2] = { 0, 0 };
  int maxPoints;
  int count = 0;

  for (int i = 0; i < n; i++) {
    cin >> auxBearingsPoints[0] >> auxBearingsPoints[1] >> auxBearingsPoints[2];
    if (abs(auxBearingsPoints[1]) > auxBearingsPoints[0]) { continue; }
    bearingsPoints[count][0] = auxBearingsPoints[0];
    bearingsPoints[count][1] = auxBearingsPoints[1];
    bearingsPoints[count][2] = auxBearingsPoints[2];
    count++;
  }

  maxPoints = walter(start, bearingsPoints, count, 0);
  cout << maxPoints << "\n";
  return 0;
}
