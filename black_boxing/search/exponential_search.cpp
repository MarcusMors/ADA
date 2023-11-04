#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// upper bouond return first strictly greater than wanted

template<class It> It upper_bound_exp_search(It begin, It end, auto wanted)
{
  if (*begin == wanted) { return begin + 1; }
  size_t i = 1;
  while (((begin + i) < end) and (*(begin + i) <= wanted)) {
    //
    i = i << 1;
  }

  It end_i = (begin + i) > end ? end : begin + i;
  return upper_bound(begin + (i >> 1), end_i, wanted);
}

// lower bouond return first greater or equal than wanted
template<class It> It lower_bound_exp_search(It begin, It end, auto wanted)
{
  if (*begin == wanted) { return begin; }
  size_t i = 1;
  while (((begin + i) < end) and (*(begin + i) < wanted)) {
    //
    i = i << 1;
  }

  It end_i = (begin + i) > end ? end : begin + i;
  return lower_bound(begin + (i >> 1), end_i, wanted);
}


int main()
{

  vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

  auto it = upper_bound_exp_search(v.begin(), v.end(), 4);// 4=>4,5=>6
  // auto it = lower_bound_exp_search(v.begin(), v.end(), 20);
  if (it == v.end()) {
    cout << "not found" << endl;
  } else {
    cout << "found at: " << (it - v.begin()) << endl;
  }

  return 0;
}
