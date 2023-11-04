#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void printCombination(const vector<int> &vec, const vector<int> &indices)
{
  // Print the included elements
  for (int index : indices) { cout << vec[index] << " "; }

  // Print the elements that are not included
  for (uint i = 0; i < vec.size(); ++i) {
    if (find(indices.begin(), indices.end(), i) == indices.end()) { cout << "(" << vec[i] << ") "; }
  }

  cout << endl;
}

void generateCombinations(const vector<int> &vec)
{
  int n = vec.size();

  for (int k = 1; k <= n - 1; ++k) {
    cout << endl;

    // Generate combinations of k elements
    vector<int> indices(k, 0);
    for (int i = 0; i < k; ++i) { indices[i] = i; }

    do {
      printCombination(vec, indices);
    } while (next_permutation(indices.begin(), indices.end()));

    cout << endl;
  }
}

int main()
{
  vector<int> vec = { 1, 2, 3, 4, 5 };

  generateCombinations(vec);

  return 0;
}
