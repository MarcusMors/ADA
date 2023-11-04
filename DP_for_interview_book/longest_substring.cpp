#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using uint = unsigned int;

const int N = 100;

/* sum[i][j] = Sum of digits from i to j
 * if i>j, then value holds no meaning.
 */

int sum[N][N];


int max_sub_string_length_dp(string str)
{
  const int n = str.size();
  int maxLen = 0;

  // Lower diagonal of matrix is not used (i>j)
  // Filling diagonal values
  for (int i = 0; i < n; i++) { sum[i][i] = str[i] - '0'; }

  for (int len = 2; len <= n; len++) {
    // Pick i and j for current substring
    for (int i = 0; i < n - len + 1; i++) {
      int k = len / 2;
      int j = i + len - 1;
      sum[i][j] = sum[i][j - k] + sum[j - k + 1][j];
    }
  }
  return maxLen;
}

/**
 * improved version that halves the memory usage.
 */
// const uint def_val = 0;
// const int N = 10000;
// std::vector<uint> sum(N, def_val);
// uint max_sub_string_length_dp(string str)
// {
//   const uint n = str.size();
//   uint max_len = 0;

//   {
//     uint cont = n;
//     auto it = str.begin();
//     for (uint i = 0; i < (n * (n + 1)) / 2; i += cont, it++, cont--) { sum[i] = *it - '0'; }
//   }
//   //
//   for (uint len = 2; len <= n; len++) {
//     uint cont = n;
//     uint padding = n + 1 - len;
//     uint i_limit = ((n + n - padding) * (padding + 1)) / 2;// trapeze formula
//     for (uint i = 0; i < i_limit; i += cont, cont--) {
//       const uint j = len - 1;
//       const uint k = len / 2;
//       // j - 1;
//       uint h = j - k + 1;
//       uint displacement = ((cont - 1 + cont - h) * h) / 2;
//       uint component_1 = sum[i + j - k];
//       uint component_2 = sum[i + j + displacement];
//       sum[i + j] = component_1 + component_2;
//       if (len % 2 == 0 and len > max_len and component_1 == component_2) { max_len = len; }
//     }
//   }
//   return max_len;
// }

// const int N = 100;
/* sum[i][j] = Sum of digits from i to j
 * if i>j, then value holds no meaning.
 */

// int sum[N][N];


// int max_three_equal_substr_sum_length(const string str)
// {
//   int n = str.size();
//   for (int i = 0; i < n; i++) { sum[i][i] = static_cast<int>(str[i] - '0'); }

//   for (int len = 2; len <= n; len++) {

//     for (int i = 0; i < n - len + 1; i++) {
//       int j = i + len - 1;
//       int displacement = len / 2;

//       int first_and_second = sum[i][j - displacement];
//       int third = sum[j - displacement][j];

//       sum[i][j] = ;
//       //
//     }
//   }
//   //
//   return 1;
// }

int main()
{
  std::vector<string> tests{
    "354417",
  };

  for (const auto &t : tests) {
    int rpta = max_sub_string_length_dp(t);
    cout << rpta << "\n";
    // cout << "sum vec: " << endl;
    // for (const auto &e : sum) {
    //   if (e != 0) { cout << e << ", "; }
    // }
    // for (const auto &e : sum) {//
    //   cout << e << ", ";
    // }
    // cout << endl;
    // cout << "---------------------------------------" << endl;
    // sum.assign(N, def_val);
  }


  return 0;
}
