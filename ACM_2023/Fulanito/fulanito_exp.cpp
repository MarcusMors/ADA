#include <bits/stdc++.h>
#define fastio()                         \
  std::ios_base::sync_with_stdio(false); \
  std::cin.tie(NULL);                    \
  std::cout.tie(NULL)

#define FOR_N(it, limit) for (unsigned long long it = 0; it < (limit); it++)

typedef unsigned long long ull;

using namespace std;

template<class It> It upper_bound_exp_search(It begin, It end, auto wanted)
{
  if (*begin == wanted) { return begin + 1; }
  size_t i = 1;
  while (((begin + i) < end) and (*(begin + i) <= wanted)) { i = i << 1; }

  It end_i = (begin + i) > end ? end : begin + i;
  return upper_bound(begin + (i >> 1), end_i, wanted);
}

// lower bouond return first greater or equal than wanted
template<class It> It lower_bound_exp_search(It begin, It end, auto wanted)
{
  if (*begin == wanted) { return begin; }
  size_t i = 1;
  while (((begin + i) < end) and (*(begin + i) < wanted)) { i = i << 1; }

  It end_i = (begin + i) > end ? end : begin + i;
  return lower_bound(begin + (i >> 1), end_i, wanted);
}


template<class Forward_it> Forward_it exponentialSearch(Forward_it begin, Forward_it end, const ull wanted)
{
  if (*begin == wanted) { return begin; }

  size_t i = 1;
  while (begin + i < end && *(begin + i) <= wanted) { i = i << 1; }

  return upper_bound(begin + (i >> 1), min(i, (end - begin) - 1), wanted);

  //  Call binary search for the found range.
}


void solve()
{
  unsigned n, q;
  cin >> q >> n;
  std::vector<ull> elems(n);
  ull acc = 0;
  FOR_N(i, n)
  {
    ull e;
    cin >> e;
    acc += e;
    elems[i] = acc;
  }

  FOR_N(i, q)
  {
    ull e;
    cin >> e;
    ull index = (upper_bound(elems.begin(), elems.end(), e) - elems.begin()) - 1;
    if (index == -1ULL) {
      cout << 0 << " " << e << endl;
    } else {
      cout << index + 1 << " " << e - elems[index] << endl;
    }
  }


  // std::sort(elems.begin(), elems.end());
}

int main()
{
  fastio();
  solve();

  return 0;
}

/*
2 5
1 200 30 345 12
250
576

 */
