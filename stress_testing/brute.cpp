#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

template<typename FwdIter, typename F, typename Eq = std::equal_to<>>
static void group_by(FwdIter from, FwdIter to, F f, Eq eq = {})
{
  if (from == to) return;
  auto p = from;
  std::size_t rep = 1;
  for (auto q = std::next(p); q != to; ++p, ++q, ++rep)
    if (!eq(*p, *q)) {
      std::invoke(f, *p, rep);
      rep = 0;
    }
  std::invoke(f, *p, rep);
}

static std::size_t testcase(unsigned N, std::vector<unsigned> A)
{
  if (N <= 2) return 0;
  std::sort(A.begin(), A.end());
  std::size_t maxrep = 0;
  group_by(A.begin(), A.end(), [&](auto, auto rep) { maxrep = std::max(maxrep, rep); });
  return maxrep == 1 ? N - 2 : N - maxrep;
}

static void testcase()
{
  unsigned N;
  std::cin >> N;
  std::vector<unsigned> A(N);
  std::copy_n(std::istream_iterator<unsigned>(std::cin), N, A.begin());
  std::cout << testcase(N, std::move(A)) << '\n';
}

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  unsigned T;
  std::cin >> T;
  while (T--) testcase();
}
