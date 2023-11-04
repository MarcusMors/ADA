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
  // const intType n_max = 200'000;
  const intType n_max = 3;
  const intType n_min = 1;
  Distribution n_distribution(n_min, n_max);
  auto generate_n = [&]() { return n_distribution(engine); };

  const intType tolerancia_max = 100;
  const intType tolerancia_min = 1;
  Distribution tolerancia_distribution(tolerancia_min, tolerancia_max);
  auto generate_tolerancia = [&]() { return tolerancia_distribution(engine); };

  // const intType i_max = 1'000'000'000;
  const intType i_max = 23;
  const intType i_min = 7;
  Distribution i_distribution(i_min, i_max);
  auto generate_i = [&]() { return i_distribution(engine); };

  const intType j_max = 59;
  const intType j_min = 0;
  Distribution j_distribution(j_min, j_max);
  auto generate_j = [&]() { return j_distribution(engine); };

  // const std::string file_name = "GD_uniform_distribution__" + to_str(sizeof(intType)) + "b-" + to_str(Bytes) +
  // "B.csv";
  // const std::string file_name = "GD_uniform_distribution__" + to_str(data_size) + ".csv";

  // std::ofstream out;
  // out.open(file_name);
  // cout << data_size << ",";

  using std::cout;
  const intType data_size = generate_n();
  cout << data_size << " ";
  cout << generate_tolerancia() << " \n";
  for (intType i = 0; i < data_size; i++) {
    cout << generate_i() << ' ';
    cout << generate_j() << ' ';
    cout << "\n";
  }
  cout << "\n";
  // out.close();
}

int main()
{
  print_random_data();

  return 0;
}
