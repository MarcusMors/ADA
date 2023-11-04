#include <iostream>
#include <vector>

using namespace std;

void generateRecursive(int n, int i, int k, const vector<int> &vec, vector<int> &combination, vector<bool> &other)
{
  if (k == 0) {
    // Print the combination
    cout << "c:";
    for (int elem : combination) { cout << elem << " "; }
    cout << endl;

    cout << "o:";
    for (size_t i = 0; i < other.size(); i++) {
      if (other[i]) { cout << vec[i] << " "; }
    }
    cout << endl;
    return;
  }

  // Generate combinations with the current element
  for (int j = i + 1; j < n; ++j) {
    combination.push_back(vec[j]);
    other[j] = false;
    generateRecursive(n, j, k - 1, vec, combination, other);
    combination.pop_back();
    other[j] = true;
  }
}

void generateCombinations(const vector<int> &vec)
{
  int n = vec.size();

  for (int k = 1; k < n; ++k) {
    // Generate combinations of k elements
    for (int i = 0; i < n; ++i) {
      vector<bool> other(n, true);
      vector<int> combination;
      combination.push_back(vec[i]);
      other[i] = false;

      generateRecursive(n, i, k - 1, vec, combination, other);
    }

    cout << endl;
  }
}

int main()
{
  vector<int> vec = { 1, 2, 3, 4, 5 };

  generateCombinations(vec);

  return 0;
}
