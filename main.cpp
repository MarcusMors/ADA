
#include <queue>
#include <iostream>

using namespace std;

int math_way(int start, int end)
{
  int steps = 0;
  while (end % 2 == 0)
  {
    end;
  }
  while (start > end)
  {
    end++;
    steps++;
  }
}

int main()
{
  int a, b;
  cin >> a;
  cin >> b;

  cout << inverse(a, b) << endl;
  // cout << brute_force(a, b) << endl;

  // 3 5
  // 3 -> 6 -> 5
  // 2 -> 4 -> 8 -> 7,6,5

  // 1 9
  // 1 -> 2 -> 4 -> 8 ->
  // 1 -> 2 -> 4 -> 8 ->

  return 0;
}
