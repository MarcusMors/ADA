#include <iostream>
#include <vector>

using namespace std;


int arr[50]{};

void r(vector<int> v, int d)
{
  for (size_t i = b; i < e; i++) {
    v.pop_back();
    v.push_back(i);
    vector<int> vec{ i };
    d--;
    if (d == 0) {
      // check condition of comb;
      return;
    }

    r();
  }
}

void solve()
{
  int r = 3;
  int c = 5;

  // 10
  // vector<int> v{ 1, 2, 3, 4, 5 };
  vector<int> v{ 10, 20, 30, 40, 50 };
  unsigned count = 0;
  // vector c(3);
  for (int a = 0; a < v.size(); a++) {
    for (int b = a + 1; b < v.size(); b++) {
      vector<int> comb{ v[a], v[b] };
      for (int c = b + 1; c < v.size(); c++) {
        comb.push_back(v[c]);
        count++;
        for (auto &&e : comb) { cout << e << ", "; }
        cout << endl;

        comb.pop_back();
      }
    }
  }

  cout << "count: " << count << endl;
}

int main()
{
  //
  solve();
  return 0;
}
