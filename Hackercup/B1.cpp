#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

// typedef long long int int
#define FOR_N(it, limit) for (int it = 0; it < (limit); it++)

using namespace std;


int smallest = 100000;
bool impossible = true;
int CASE = 0;

vector<int> facts;

int generateRecursive(int n, int i, int k, const vector<int> &vec, vector<int> &combination, vector<int> &other)
{
  if (k == 0) {
    int comb_p = 1;
    for (auto e : combination) { comb_p *= e; }

    int other_s = 0;
    for (size_t i = 0; i < other.size(); i++) {
      if (other[i]) { other_s += other[i]; }
    }
    int total = comb_p + other_s;

    int max_ones_sz = 100 - (vec.size() - combination.size() + 1);
    if (total < 41) {
      int ones_needed = 41 - comb_p;
      if (max_ones_sz >= ones_needed) {
        cout << "case #" << CASE << ": " << combination.size() + ones_needed << " ";
        for (size_t i = 0; i < ones_needed; i++) { cout << 1 << " "; }
        // print comb_p
        cout << comb_p << " ";
        // print Pf - (elements_of_comb_p);
        for (size_t i = 0; i < other.size(); i++) {
          if (other[i]) { cout << vec[i] << " "; }
        }

        cout << "\n";
        impossible = false;
        return -1;
      }
    }

    if (total > 41) {
      int ones_needed = (comb_p - 41);
      if (max_ones_sz / 2 >= ones_needed) {
        cout << "case #" << CASE << ": " << combination.size() + 2 * ones_needed << " ";
        for (size_t i = 0; i < 2 * ones_needed; i++) { cout << -1 << " "; }
        // print comb_p
        cout << comb_p << " ";
        // print Pf - (elements_of_comb_p);
        for (size_t i = 0; i < other.size(); i++) {
          if (other[i]) { cout << vec[i] << " "; }
        }

        cout << "\n";
        impossible = false;
        return -1;
      }
    }
  }

  // Generate combinations with the current element
  for (int j = i + 1; j < n; ++j) {
    combination.push_back(vec[j]);
    other[j] = false;
    generateRecursive(n, j, k - 1, vec, combination, other);
    other[j] = true;
    combination.pop_back();
  }
  return 1;
}

void generateCombinations(const vector<int> &vec)
{
  int n = vec.size();

  for (int k = 1; k <= n - 1; ++k) {
    // Generate combinations of k elements
    for (int i = 0; i < n; ++i) {
      vector<int> combination;
      combination.push_back(vec[i]);
      vector<int> other(n, 1);
      other[i] = false;

      if (impossible) {
        generateRecursive(n, i, k - 1, vec, combination, other);
      } else {
        break;
      }
    }
  }
}


void solve()
{
  unsigned P;
  cin >> P;

  vector<int> Pf;
  int sum = 0;
  for (int i = 2; i <= P; i++) {
    if (P % i == 0) {
      sum += i;
      Pf.push_back(i);
      P = P / i;
      if (i > P) {
        break;
      } else {
        i--;
      }
    }
  }


  if (sum == 41) {
    cout << "case #" << CASE << ": " << Pf.size() << " ";
    for (auto e : Pf) { cout << e << " "; }
    cout << "\n";
    return;
  }


  // bool flag{ false };
  generateCombinations(Pf);

  if (impossible == true) {
    int max_ones_sz = 100 - Pf.size();
    if (P < 41) {
      int ones_needed = 41 - P;
      if (max_ones_sz >= ones_needed) {
        cout << "case #" << CASE << ": " << Pf.size() + ones_needed << " ";
        for (size_t i = 0; i < ones_needed; i++) { cout << 1 << " "; }
        for (int elem : Pf) { cout << elem << " "; }
        cout << "\n";
        impossible = false;
        return;
      }
    }

    if (P > 41) {
      int ones_needed = (P - 41);
      if (max_ones_sz / 2 >= ones_needed) {
        cout << "case #" << CASE << ": " << Pf.size() + 2 * ones_needed << " ";
        for (size_t i = 0; i < 2 * ones_needed; i++) { cout << -1 << " "; }
        for (int elem : Pf) { cout << elem << " "; }
        cout << "\n";
        impossible = false;
        return;
      }
    }
  }


  if (impossible) { cout << "case #" << CASE << ": " << -1; }
}

signed main()

{
  // fastio();

  unsigned t;
  cin >> t;

  FOR_N(i, t)
  {
    CASE = i;
    impossible = true;
    // smallest = 100000;
    solve();
  }
  // while (t--) { solve(t); }
  // while (t--) { solve(t); }

  return 0;
}
