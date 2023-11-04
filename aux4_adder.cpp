#include <iostream>
#include <vector>

using namespace std;

int main()
{
  while (true) {
    int n;
    cin >> n;
    int s = 0;
    for (size_t i = 0; i < n; i++) {
      int e;
      cin >> e;
      s += e;
    }
    cout << s << "\n";
  }


  return 0;
}
