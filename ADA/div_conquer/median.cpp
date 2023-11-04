#include <iostream>
#include <vector>

using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// Function to partition the array
int partition(vector<int> &arr, int left, int right)
{
  int pivot = arr[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[right]);
  return i + 1;
}

// Function to find the kth element using quickselect
int quickselect(vector<int> &arr, int left, int right, int k)
{
  if (left == right) { return arr[left]; }

  int partitionIndex = partition(arr, left, right);

  if (partitionIndex == k) {
    return arr[k];
  } else if (partitionIndex < k) {
    return quickselect(arr, partitionIndex + 1, right, k);
  } else {
    return quickselect(arr, left, partitionIndex - 1, k);
  }
}

// Function to find the median of the array
double findMedian(vector<int> &arr, int n)
{
  if (n % 2 != 0) {
    return static_cast<double>(quickselect(arr, 0, n - 1, n / 2));
  } else {
    int firstElement = quickselect(arr, 0, n - 1, n / 2);
    int secondElement = quickselect(arr, 0, n - 1, n / 2 + 1);
    return static_cast<double>((firstElement + secondElement) / 2.0);
  }
}

int main()
{
  vector<int> arr = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
  int n = arr.size();
  cout << n << endl;
  // Find the median of the array
  double median = findMedian(arr, n);

  cout << "Median of the array is: " << median << endl;

  return 0;
}
