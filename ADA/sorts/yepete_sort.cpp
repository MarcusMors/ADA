#include <iostream>
#include <vector>

template<typename Iterator> void merge(Iterator left, Iterator middle, Iterator right)
{
  std::vector<typename Iterator::value_type> temp(std::distance(left, right));
  auto i = left;
  auto j = middle;
  auto temp_it = temp.begin();

  while (i < middle && j < right) {
    if (*i < *j) {
      *temp_it = *i;
      i++;
    } else {
      *temp_it = *j;
      j++;
    }
    temp_it++;
  }

  while (i < middle) { *temp_it++ = *i++; }

  while (j < right) { *temp_it++ = *j++; }

  std::copy(temp.begin(), temp.end(), left);
}

template<typename Iterator> void mergeSort(Iterator left, Iterator right)
{
  if (std::distance(left, right) > 1) {
    auto middle = left + std::distance(left, right) / 2;
    mergeSort(left, middle);
    mergeSort(middle, right);
    merge(left, middle, right);
  }
}

int main()
{
  std::vector<int> vec = { 4, 2, 7, 1, 5, 3 };

  std::cout << "Original vector:" << std::endl;
  for (const auto &element : vec) { std::cout << element << " "; }
  std::cout << std::endl;

  mergeSort(vec.begin(), vec.end());

  std::cout << "Sorted vector:" << std::endl;
  for (const auto &element : vec) { std::cout << element << " "; }
  std::cout << std::endl;

  return 0;
}
