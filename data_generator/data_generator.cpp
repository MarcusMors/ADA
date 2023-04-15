#include <fstream>
#include <iostream>
#include <limits>
#include <random>
#include <sstream>
#include <string>

template<typename T> T bit_number(unsigned Bytes)
{
  // static_assert(sizeof(T) < Bytes, "the type isn't able to hold that much Bytes");
  if (sizeof(T) < Bytes) {
    std::cerr << "the type isn't able to hold " << Bytes << " Bytes\n";
    std::cerr << "sizeof(T)\t: " << sizeof(T) << "\n";
    std::cerr << "Bytes\t\t: " << Bytes << " \n";
    return 0;
  }
  T n{ 1 };
  for (unsigned i = 0; i <= Bytes; i++) { n <<= 3; }

  return n;
}

template<typename T> std::string to_str(const T &number)
{
  std::stringstream ss;
  ss << number;
  std::string str;
  ss >> str;
  return str;
}

template<class It_type, class T> void fill_file_with_random_data(T data_size)
{
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // supported int Types // check https://en.cppreference.com/w/cpp/header/random
  // short, int, long, long long,
  // unsigned short, unsigned int, unsigned long, or unsigned long long
  using intType = short;
  using Distribution = std::uniform_int_distribution<intType>;

  Seed seed;
  Engine engine{ seed() };
  const intType max = std::numeric_limits<intType>::max();
  const intType min = std::numeric_limits<intType>::min();
  Distribution distribution(min, max);
  auto generate_random_number = [&]() { return distribution(engine); };

  // const std::string file_name = "GD_uniform_distribution__" + to_str(sizeof(intType)) + "b-" + to_str(Bytes) +
  // "B.csv";
  const std::string file_name = "GD_uniform_distribution__" + to_str(data_size) + ".csv";

  std::ofstream out;
  out.open(file_name);

  out << data_size << ",";
  for (It_type i = 0; i < data_size; i++) { out << generate_random_number() << ','; }

  out.close();
}

int main()
{
  using it_type = unsigned long long;
  // const unsigned Bytes = 1;
  // const it_type data_size = bit_number<it_type>(Bytes);
  // const it_type data_size = std::numeric_limits<it_type>::max();
  // const it_type data_size = 500'000;
  it_type data_size = 500'000;
  for (it_type i = 0; data_size <= 1'000'000; i++) {
    data_size += 50'000;
    fill_file_with_random_data<it_type>(data_size);
  }


  return 0;
}
