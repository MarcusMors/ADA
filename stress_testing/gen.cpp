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

void print_random_data()
{
  using Seed = std::random_device;
  using Engine = std::default_random_engine;
  // supported int Types // check https://en.cppreference.com/w/cpp/header/random
  // short, int, long, long long,
  // unsigned short, unsigned int, unsigned long, or unsigned long long
  using intType = unsigned;
  using Distribution = std::uniform_int_distribution<intType>;

  Seed seed;
  Engine engine{ seed() };
  /**
   * n_max = 10^5 = 100'000
   * i_max = 10^9 = 1'000'000
   */
  // const intType n_max = 100'000;
  const intType n_max = 10;
  const intType n_min = 1;
  Distribution n_distribution(n_min, n_max);
  // const intType i_max = 1'000'000;
  const intType i_max = 1'00;
  const intType i_min = 1;
  Distribution i_distribution(i_min, i_max);
  auto generate_n = [&]() { return n_distribution(engine); };
  auto generate_i = [&]() { return i_distribution(engine); };

  // const std::string file_name = "GD_uniform_distribution__" + to_str(sizeof(intType)) + "b-" + to_str(Bytes) +
  // "B.csv";
  // const std::string file_name = "GD_uniform_distribution__" + to_str(data_size) + ".csv";

  // std::ofstream out;
  // out.open(file_name);
  // cout << data_size << ",";

  using std::cout;
  using std::endl;
  cout << 1 << endl;
  const intType data_size = generate_n();
  cout << data_size << endl;
  for (intType i = 0; i < data_size; i++) { cout << generate_i() << ' '; }
  cout << endl;
  // out.close();
}

int main()
{
  print_random_data();

  return 0;
}
