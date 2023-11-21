#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // Create a sorted vector
  //                       0  1  2  3  4  5  6  7

  string str1 = "hokt0ktojuy5gr5sgoj5iglk";
  string str2 = "bienvenidos al maid cafe";

  cout << str1.size() << endl;
  cout << str2.size() << endl;

  vector<int> vec = { 1, 2, 4, 4, 4, 5, 7, 9 };

  int target = 4;
  auto lower = lower_bound(vec.begin(), vec.end(), target);
  auto upper = upper_bound(vec.begin(), vec.end(), target);

  int i = 0;
  cout << "Vector: ";
  for (const auto &element : vec) { cout << i++ << " "; }
  cout << endl;
  cout << "Vector: ";
  for (const auto &element : vec) { cout << element << " "; }
  cout << "\n";

  cout << "Lower bound of " << target << ": " << *lower << " at index " << (lower - vec.begin()) << "\n";
  cout << "Upper bound of " << target << ": " << *upper << " at index " << (upper - vec.begin()) << "\n";


  target = 0;
  lower = lower_bound(vec.begin(), vec.end(), target);
  upper = upper_bound(vec.begin(), vec.end(), target);

  if (lower == vec.end()) {
    cout << "lower not found" << endl;
  } else {
    cout << "Lower bound of " << target << ": " << *lower << " at index " << (lower - vec.begin()) << "\n";
  }

  if (upper == vec.end()) {
    cout << "upper not found" << endl;
  } else {
    cout << "Upper bound of " << target << ": " << *upper << " at index " << (upper - vec.begin()) << "\n";
  }

  target = 1;
  lower = lower_bound(vec.begin(), vec.end(), target);
  upper = upper_bound(vec.begin(), vec.end(), target);

  if (lower == vec.end()) {
    cout << "lower not found" << endl;
  } else {
    cout << "Lower bound of " << target << ": " << *lower << " at index " << (lower - vec.begin()) << "\n";
  }

  if (upper == vec.end()) {
    cout << "upper not found" << endl;
  } else {
    cout << "Upper bound of " << target << ": " << *upper << " at index " << (upper - vec.begin()) << "\n";
  }

  return 0;
}
